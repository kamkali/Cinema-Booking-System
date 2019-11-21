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
#include "command/InitializeAdminAccount.h"
#include "command/InitializeCinemaSystem.h"
#include "command/InitializeRooms.h"
#include "command/ReturnRoom.h"
#include "command/SelectOccupiedRooms.h"
#include "command/CreateSeance.h"
#include "command/DeleteMovieCommand.h"
#include "command/ListMoviesCommand.h"
#include "command/CreateMovieCommand.h"
#include "command/LoginUserCommand.h"
#include "command/RegisterUserCommand.h"
#include "command/DeleteSeance.h"
#include "command/OrderSeat.h"
#include "workflow.h"

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

    command = new InitializeCinemaSystem(DATABASE_NAME);
    command->execute();
    db = dynamic_cast<InitializeCinemaSystem *>(command)->getDatabase();
    command = new InitializeAdminAccount(db, ADMIN_USERNAME, ADMIN_PASSWORD);
    command ->execute();
    command = new InitializeRooms(db, 10, SEATS_NUMBER, ROWS_NUMBER);
    command->execute();

    RoomFactory * roomPool = dynamic_cast<InitializeRooms *>(command)->getRoomPool();

    command = new SelectOccupiedRooms(db, SEATS_NUMBER/ROWS_NUMBER);
    command->execute();

    vector<Room*> occupiedRooms = dynamic_cast<SelectOccupiedRooms *>(command)->getOccupiedRooms();

    string login;
    string password;
    int order;

    cout << "Kuglan'n'Kali Cinema" << endl;

    cout << "Sign in (1)\nSign up (2)\n" << endl;
    cout << "~: ";
    cin >> order;

    if(order == 1){
        cout << "Your login: ";
        cin >> login;
        cout << "Your password: ";
        cin >> password;

        command = new RegisterUserCommand(db, login, password);
        command->execute();
    }

    cout << "login: ";
    cin >> login;
    cout << "password: ";
    cin >> password;

    command = new LoginUserCommand(db, login, password);
    command->execute();

    if(dynamic_cast<LoginUserCommand *>(command)->isLogged()){
        int userId = dynamic_cast<LoginUserCommand *>(command)->getUserId();

        showUserMenu(db, roomPool, occupiedRooms, ROWS_NUMBER, userId);
    } else{
        cout << "You are no authorized!" << endl;
        cout << "Closing..." << endl;
    }
}