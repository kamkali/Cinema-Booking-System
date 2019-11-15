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

int main(int argc, char * argv[]){

    QueryLoader queryLoader;

    queryLoader.loadQueries();

    std::map<unsigned int, std::string> queries = queryLoader.getQueries(); //load queries from sql files

    Database database(queries);

    database.initialize("cinema"); //create database

    database.execute(QueryName::MOVIES_CREATE);

    std::string array[] ={"Titanic", "Brosman", "1999", "12", "14.32", "1"};

    std::vector<std::vector<std::string> *> *result = database.execute(QueryName::MOVIE_INSERT, array);

    Database::deleteResult(result); //clear result pointer values

    for (auto i : *result) {
        for (const auto &j: *i)
            std::cout << j << ", ";

        std::cout << std::endl;
    }

    std::string array2[] = {"Skyfall", "Craig", "2005", "13", "21.32", "5"};

    result = database.execute(QueryName::MOVIE_INSERT, array2);

    Database::deleteResult(result);

    std::string array3[] = {"Titanic", "Craig", "2005", "13", "21.32", "5"};

    result = database.execute(QueryName::MOVIE_INSERT, array3);

    Database::deleteResult(result);

    std::string array5[]{"Titanic"};

    result = database.execute(QueryName::MOVIE_SELECT_BY_NAME, array5);

    for (auto i : *result) {
        for (const auto &j: *i)
            std::cout << j << ", ";

        std::cout << std::endl;
    }

    Database::deleteResult(result);

    database.close();
}
