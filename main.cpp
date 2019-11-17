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


int main(int argc, char * argv[]){

    Command * command = new InitializeCinemaSystem("cinema");

    command->execute();

    Database * database = dynamic_cast<InitializeCinemaSystem *>(command)->getDatabase();

    command = new InitializeAdminAccount(database, "admin", "admin");

    command->execute();

    command = new InitializeRooms(database, 10, 100, 10);

    command->execute();

    RoomFactory * roomPool = dynamic_cast<InitializeRooms *>(command)->getRoomPool();

    Room * room = roomPool->getInstance();

    command = new ReturnRoom(database, roomPool, room, "ROLE_ADMIN");

    command->execute();

    database->close();
}
