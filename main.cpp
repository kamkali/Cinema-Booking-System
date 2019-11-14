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

    std::map<unsigned int, std::string> queries = queryLoader.getQueries();

    for(const auto& a:queries){
        std::cout << a.first << " ---> " << a.second << std::endl;
    }

    Database database(queries);

    database.initialize("cinema");

    database.execute(QueryName::MOVIES_CREATE);

    database.execute(QueryName::MOVIE_INSERT , "Titanic", "Brosman", "1999", "12", "14.32", "1");

    database.close();
}
