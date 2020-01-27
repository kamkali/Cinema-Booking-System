//
// Created by Kamil Kaliś on 20/11/2019.
//

#include "ListSeancesCommand.h"
#include "SelectOccupiedRoomsCommand.h"


void ListSeancesCommand::execute() {

    std::vector<std::vector<std::string> *> *allSeances = database->execute(QueryName::SEANS_SELECT_ALL);

    for(auto seanceRow : *allSeances){
        int seanceId = std::stoi(seanceRow->at(0));
        int movieId = std::stoi(seanceRow->at(2));

        std::string movieSelectArg[] = {std::to_string(movieId)};

        std::vector<std::vector<std::string> *> *movie = database->execute(QueryName::MOVIE_SELECT_BY_ID, movieSelectArg);

        Movie * localMovie = nullptr;

        if(!movie->empty()) {
            std::string title = movie->at(0)->at(1);
            std::string director = movie->at(0)->at(2);
            int productionYear = stoi(movie->at(0)->at(3));
            int price = stoi(movie->at(0)->at(4));
            double movieLength = stof(movie->at(0)->at(5));
            std::string movieDescription = movie->at(0)->at(6);

            localMovie = new Movie(movieId, title, director, productionYear, price, movieLength,
                                         movieDescription);
        }

        Database::deleteResult(movie);

        std::string roomSelectArg[] = {std::to_string(seanceId)};

        std::vector<std::vector<std::string> *> *roomFromDatabase = database->execute(QueryName::ROOM_SELECT_BY_SEANS_ID, roomSelectArg);

        int roomId = stoi(roomFromDatabase->at(0)->at(0));

        Database::deleteResult(roomFromDatabase);

        Seance * seance;

        unsigned int i{0};
        for(i = 0; i < occupiedRooms->size(); i++){
            auto * room = dynamic_cast<CinemaRoom *>(occupiedRooms->at(i));
            if(room->getId() == roomId){
                seance = new Seance(seanceId, localMovie, room);
                seance_vec->push_back(seance);
                break;
            }
        }

    }

    Database::deleteResult(allSeances);
}

std::vector<Seance *> *ListSeancesCommand::getSeanceVec() const {
    return seance_vec;
}

ListSeancesCommand::ListSeancesCommand(Database *db, std::vector<Room *> *occupiedRooms): database(db), occupiedRooms(occupiedRooms) {
    seance_vec = new std::vector<Seance *>();
}








