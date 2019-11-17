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

int main(int argc, char * argv[]){

    QueryLoader queryLoader;

    queryLoader.loadQueries();

    std::map<unsigned int, std::string> queries = queryLoader.getQueries(); //load queries from sql files

    Database database(queries);

    database.initialize("cinema"); //create database

    Command * command = new InitializeAdminAccount(&database, "admin", "admin");

    command->execute();

    database.close();
}
