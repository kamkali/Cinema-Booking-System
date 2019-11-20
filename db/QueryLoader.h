//
// Created by ubuntu on 11/14/19.
//

#ifndef SIMPLE_EXAMPLE_QUERYLOADER_H
#define SIMPLE_EXAMPLE_QUERYLOADER_H
#include <fstream>
#include <map>
#include <string>

enum QueryName{
    MOVIE_DELETE_BY_ID,
    MOVIE_INSERT,
    MOVIE_SELECT_BY_ID,
    MOVIE_SELECT_BY_NAME,
    MOVIES_CREATE,
    ROOM_DELETE,
    ROOM_INSERT_BY_NAME,
    ROOM_SELECT_ALL,
    ROOM_SELECT_BY_ID,
    ROOM_SELECT_BY_NAME,
    ROOM_SELECT_BY_SEANS_ID,
    ROOM_SELECT_BY_SEANS_NAME,
    ROOM_SELECT_OCCUPIED_ROOMS,
    ROOM_UPDATE_BY_ID,
    ROOMS_CREATE,
    SEANS_DELETE,
    SEANS_INSERT,
    SEANS_SELECT_BY_ID,
    SEANS_SELECT_BY_MOVIE_ID,
    SEANS_SELECT_BY_NAME,
    SEANSES_CREATE,
    SEAT_DELETE_BY_ID,
    SEAT_INSERT,
    SEAT_SELECT_BY_ROOM_ID,
    SEAT_SELECT_BY_ROOM_ID_AND_NUMBER_IN_ROOM,
    SEAT_UPDATE_BY_ROOM_ID,
    SEATS_CREATE,
    USER_DELETE_BY_ID,
    USER_INSERT,
    USER_SELECT_BY_NAME,
    USERS_CREATE,
    MOVIE_SELECT_ALL,
    SEANS_SELECT_ALL
};

class QueryLoader {
private:
    const std::string PATH = "../db/sql_queries/";
    std::fstream file;
    std::map<unsigned int, std::string> queries;
    std::string loadSingleQuery(const std::string & name);
public:
    void loadQueries();
    std::map<unsigned int, std::string> & getQueries();
};


#endif //SIMPLE_EXAMPLE_QUERYLOADER_H
