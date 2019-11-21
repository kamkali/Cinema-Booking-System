//
// Created by piotr on 19.11.2019.
//

#include "CreateSeance.h"

#include <utility>

void CreateSeance::execute() {

    std::string argsSeansInsert[] = {name, std::to_string(movie->getId())};

    Database::deleteResult(database->execute(QueryName::SEANS_INSERT, argsSeansInsert));

    std::string argSeansSelect[] = {name};

    std::vector<std::vector<std::string> *> *seansResult = database->execute(QueryName::SEANS_SELECT_BY_NAME, argSeansSelect);

    if(seansResult->empty()){
        std::cout << "There is no movie of this title!" << std::endl;
        return;
    }

    int seanceId = stoi(seansResult->at(0)->at(0));

    seance = new Seance(seanceId, movie, room);

    std::string argsRoomUpdate[] = {dynamic_cast<CinemaRoom *>(room)->getName(), seansResult->at(0)->at(0),
                                    std::to_string(dynamic_cast<CinemaRoom *>(room)->getId())};

    Database::deleteResult(database->execute(QueryName::ROOM_UPDATE_BY_ID, argsRoomUpdate));
}

Seance *CreateSeance::getSeance() {
    return seance;
}

CreateSeance::CreateSeance(Database *database, std::string name, Room *room, Movie *movie):
database(database), name(std::move(name)), room(room), movie(movie) {
    seance = nullptr;
}
