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

#define SEATS_PER_ROW 10
#define ADMIN "ROLE_ADMIN"

int main(int argc, char * argv[]){

    Command * command = new InitializeCinemaSystem("cinema");

    command->execute();

    Database * database = dynamic_cast<InitializeCinemaSystem *>(command)->getDatabase();

    command = new InitializeAdminAccount(database, "admin", "admin");

    command->execute();

    command = new InitializeRooms(database, 10, 100, SEATS_PER_ROW);

    command->execute();

    RoomFactory * roomPool = dynamic_cast<InitializeRooms *>(command)->getRoomPool();

    command = new SelectOccupiedRooms(database, SEATS_PER_ROW);

    command->execute();

//    std::vector<Room*> occupiedRooms = dynamic_cast<SelectOccupiedRooms *>(command)->getOccupiedRooms();
//
//    for(auto room: occupiedRooms) {
//
//        command = new ReturnRoom(database, roomPool, room, "ROLE_ADMIN");
//
//        command->execute();
//
//    }

//    MovieDescription * movieDescription = new MovieDescription();
//
//    command = new CreateMovieCommand(database, "Titanic1", "Brosman_T", 1999, 12, 14.32, "Description", "ROLE_ADMIN");
//
//    command->execute();

    Command *userRegister = new RegisterUserCommand(database, "janko123", "jaknoPass123");
    userRegister->execute();

    Command *logUser = new LoginUserCommand(database, "janko123", "jaknoPass123");
//    Command *logUser = new LoginUserCommand(database, "janko123", "wrongPass");

    logUser->execute();

    bool loggedUser = dynamic_cast<LoginUserCommand *>(logUser)->isLogged();
    if (!loggedUser)
        std::cout << "Cannot log user" << std::endl;

    Command *createMovie = new CreateMovieCommand(database, "Tities", "Brosman_T", 1999, 12, 14.32, "Description", ADMIN);
    createMovie->execute();

    auto film = (dynamic_cast<CreateMovieCommand *>(createMovie)->getCreatedMovie());

    film->printMovieInfo();

//    Command *createMovie2 = new CreateMovieCommand(database, "Somth", "Hehe", 3000, 1122, 112, "Other Descript", ADMIN);
//    createMovie2->execute();


    Command *listMovies = new ListMoviesCommand(database);
    listMovies->execute();

    auto moviesFromDb = (dynamic_cast<ListMoviesCommand *>(listMovies)->getMoviesVec());

    for (auto &movieRecord: moviesFromDb) {
        movieRecord.printMovieInfo();
    }

//    Command *deleteMovie = new DeleteMovieCommand(database, "Tities", ADMIN);
//    deleteMovie->execute();

    std::cout << std::endl;


    database->close();
}
