//
// Created by Kamil Kaliś on 21/11/2019.
//

#include "SeancePropertiesCommand.h"

void SeancePropertiesCommand::execute() {
    std::string args[] = {std::to_string(seanceId)};
    std::vector<std::vector<std::string> *> *seanceFromDb = DB->execute(SEANS_SELECT_BY_ID, args);

    if ((*seanceFromDb).empty()) {
        std::cout << "There is no existing seance of id " << seanceId << std::endl;
    } else {
        std::string movieId[] = {seanceFromDb->at(0)->at(2)};

        std::vector<std::vector<std::string> *> *seanceMovie = DB->execute(MOVIE_SELECT_BY_ID, movieId);

        std::vector<std::vector<std::string> *> *rooms = DB->execute(ROOM_SELECT_OCCUPIED_ROOMS);

        auto showingMovie = new Movie(std::stoi(seanceMovie->at(0)->at(0)), seanceMovie->at(0)->at(1),
                                      seanceMovie->at(0)->at(2), std::stoi(seanceMovie->at(0)->at(3)),
                                      std::stoi(seanceMovie->at(0)->at(4)), std::stod(seanceMovie->at(0)->at(5)),
                                      seanceMovie->at(0)->at(6));

        int i{0};
        for(auto room: *rooms){
            if (seanceId == std::stoi(room->at(2))){
                break;
            }
            i++;
        }
        seance = new Seance(std::stoi(seanceFromDb->at(0)->at(0)), showingMovie, occupiedRooms.at(i));

        Database::deleteResult(seanceMovie);
        Database::deleteResult(rooms);
    }
    Database::deleteResult(seanceFromDb);
}

Seance *SeancePropertiesCommand::getSeance() const {
    return seance;
}

SeancePropertiesCommand::SeancePropertiesCommand(Database *db, int seanceId, const std::vector<Room *> &occupiedRooms,
                                                 size_t seatsPerRow) : DB(db), seanceId(seanceId),
                                                                       occupiedRooms(occupiedRooms),
                                                                       seatsPerRow(seatsPerRow) {}







