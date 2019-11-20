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
//
    Command *createMovie = new CreateMovieCommand(database, "Tities", "Brosman_T", 1999, 12, 14.32, "Description", ADMIN);

    createMovie->execute();

    command = new CreateSeance(database, "seans 1", roomPool->getInstance(), dynamic_cast<CreateMovieCommand *>(createMovie)->getCreatedMovie());

    command->execute();

    Seance * seance = dynamic_cast<CreateSeance *>(command)->getSeance();

    command = new OrderSeat(database, seance, 10, 1);

    command->execute();

    command = new DeleteSeance(database, seance, roomPool, ADMIN);

    command->execute();

    database->close();
}
