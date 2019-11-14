#include <iostream>

//
// Created by Piotr on 12.11.2019.
//
#include "movie/Movie.h"
#include "room/CinemaRoom.h"
#include "room/RoomFactory.h"
#include "room/CinemaRoomFactory.h"
#include "Database"
#include "sqlite/sqlite3.h"

int main(int argc, char * argv[]){

    sqlite3* DB;

    int exit = sqlite3_open("cinema.db", &DB);

    if (exit) {
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        return (-1);
    }
    else
        std::cout << "Opened Database Successfully!" << std::endl;
    sqlite3_close(DB);
    return (0);


    return 0;
}
