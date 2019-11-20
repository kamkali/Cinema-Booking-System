//
// Created by ubuntu on 11/14/19.
//

#include "QueryLoader.h"



void QueryLoader::loadQueries() {

    static std::string queriesNames[]{
            "movie_delete_by_id",
            "movie_insert",
            "movie_select_by_id",
            "movie_select_by_name",
            "movies_create",
            "room_delete",
            "room_insert_by_name",
            "room_select_all",
            "room_select_by_id",
            "room_select_by_name",
            "room_select_by_seans_id",
            "room_select_by_seans_name",
            "room_select_occupied_rooms",
            "room_update_by_id",
            "rooms_create",
            "seans_delete",
            "seans_insert",
            "seans_select_by_id",
            "seans_select_by_movie_id",
            "seans_select_by_name",
            "seanses_create",
            "seat_delete_by_id",
            "seat_insert",
            "seat_select_by_room_id",
            "seat_select_by_room_id_and_number_in_room",
            "seat_update_by_room_id",
            "seats_create",
            "user_delete_by_id",
            "user_insert",
            "user_select_by_name",
            "users_create",
            "movie_select_all",
            "seans_select_all"
    };

    std::string temp;

    unsigned int enumValue = QueryName::MOVIE_DELETE_BY_ID;

    for(const auto& query:queriesNames){
        temp = loadSingleQuery(query);
        queries.insert(std::pair<unsigned int, std::string>(enumValue, temp));
        enumValue++;
    }


}

std::string QueryLoader::loadSingleQuery(const std::string &name) {
    std::string query{};
    std::string temp;

    file.open(PATH + name + ".sql");

    while(!file.eof()){
        getline(file, temp);
        query += temp;
    }

    file.close();

    return query;
}

std::map<unsigned int, std::string> &QueryLoader::getQueries() {
    return queries;
}
