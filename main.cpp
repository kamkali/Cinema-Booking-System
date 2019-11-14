#include <iostream>

//
// Created by Piotr on 12.11.2019.
//
#include "movie/Movie.h"
#include "room/CinemaRoom.h"
#include "room/RoomFactory.h"
#include "room/CinemaRoomFactory.h"
#include "db/Database.h"
#include "sqlite/sqlite3.h"

int main(int argc, char * argv[]){

    Database db;

    db.initialize("test");
    db.close();
}
