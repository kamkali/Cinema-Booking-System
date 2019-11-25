#include <iostream>

//
// Created by Piotr on 12.11.2019.
//
#include <iostream>
#include "movie/Movie.h"
#include "room/CinemaRoom.h"
#include "room/RoomFactory.h"
#include "room/CinemaRoomFactory.h"
#include "db/Database.h"
#include "sqlite/sqlite3.h"
#include "db/QueryLoader.h"
#include "command/Command.h"
#include "command/InitializeAdminAccountCommand.h"
#include "command/InitializeCinemaSystemCommand.h"
#include "command/InitializeRoomsCommand.h"
#include "command/ReturnRoomCommand.h"
#include "command/SelectOccupiedRoomsCommand.h"
#include "command/CreateSeanceCommand.h"
#include "command/DeleteMovieCommand.h"
#include "command/ListMoviesCommand.h"
#include "command/CreateMovieCommand.h"
#include "command/LoginUserCommand.h"
#include "command/RegisterUserCommand.h"
#include "command/DeleteSeanceCommand.h"
#include "command/OrderSeatCommand.h"
#include "workflow.h"
#include "exception/UserNotFoundException.h"

#define DATABASE_NAME "cinema"
#define ADMIN_USERNAME "admin"
#define ADMIN_PASSWORD "admin"
#define SEATS_NUMBER 100
#define ROWS_NUMBER 10
#define ADMIN "ROLE_ADMIN"

using namespace std;

int main(int argc, char * argv[]){

    Database * db;

    Command * command;

    command = new InitializeCinemaSystemCommand(DATABASE_NAME);
    command->execute();
    db = dynamic_cast<InitializeCinemaSystemCommand *>(command)->getDatabase();
    command = new InitializeAdminAccountCommand(db, ADMIN_USERNAME, ADMIN_PASSWORD);
    command ->execute();
    command = new InitializeRoomsCommand(db, 10, SEATS_NUMBER, ROWS_NUMBER);
    command->execute();

    RoomFactory * roomPool = dynamic_cast<InitializeRoomsCommand *>(command)->getRoomPool();

    command = new SelectOccupiedRoomsCommand(db, SEATS_NUMBER / ROWS_NUMBER);
    command->execute();

    vector<Room*> occupiedRooms = dynamic_cast<SelectOccupiedRoomsCommand *>(command)->getOccupiedRooms();

    string login;
    string password;
    int order{};
    string orderString;

    cout << "        Kuglan'n'Kali Cinema        " << endl;
    cout << "____________________________________" << endl;
    cout << "Welcome to the Kuglan'n'Kali Cinema!" << endl;
    cout << "Sign in (1)\nSign up (2)\n" << endl;
    cout << "~: ";

    try {
        cin >> orderString;
        order = stoi(orderString);
    }catch (invalid_argument & exc){
        cerr << "invalid argument: pick proper argument" << endl;
        return 0;
    }


    if(order == 1){
        cout << "Your login: ";
        cin >> login;
        cout << "Your password: ";
        cin >> password;

        command = new RegisterUserCommand(db, login, password);
        command->execute();
    }

    if(order == 1 || order == 2) {

        cout << "login: ";
        cin >> login;
        cout << "password: ";
        cin >> password;

        try {
            command = new LoginUserCommand(db, login, password);
            command->execute();
        }catch (UserNotFoundException & exc){
            cerr << exc.what() << endl;
            return 0;
        }

        if (dynamic_cast<LoginUserCommand *>(command)->isLogged()) {
            auto *loginUserCommand = dynamic_cast<LoginUserCommand *>(command);
            int userId = loginUserCommand->getUserId();
            bool isAdmin = loginUserCommand->isUserAdmin();

            if (isAdmin)
                showAdminMenu(db, roomPool, &occupiedRooms);
            else
                showUserMenu(db, occupiedRooms, ROWS_NUMBER, userId);

        } else {
            cout << "You are no authorized!" << endl;
            cout << "Closing..." << endl;
        }
    } else{
        cout << "Choose proper option" << endl;
    }
}