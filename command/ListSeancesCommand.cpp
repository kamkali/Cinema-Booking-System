//
// Created by Kamil Kaliś on 20/11/2019.
//

#include "ListSeancesCommand.h"
#include "SelectOccupiedRooms.h"


const std::vector<Seance> &ListSeancesCommand::getSeanceVec() const {
    return seance_vec;
}

void ListSeancesCommand::execute() {
    seance_vec.clear();
    std::vector<std::vector<std::string> *> *allSeances = DB->execute(SEANS_SELECT_ALL);

    for (auto singleSeance: *allSeances) {

        std::string seanceId[] = {singleSeance->at(0)};
        std::string movieId[] = {singleSeance->at(2)};


        std::vector<std::vector<std::string> *> *seanceRoom = DB->execute(ROOM_SELECT_OCCUPIED_ROOMS, seanceId);

        std::vector<std::vector<std::string> *> *seanceMovie = DB->execute(MOVIE_SELECT_BY_ID, movieId);



        auto *seance = new Seance(std::stoi(singleSeance->at(0)),
                                  new Movie(std::stoi(seanceMovie->at(0)->at(0)), seanceMovie->at(0)->at(1),
                                            seanceMovie->at(0)->at(2), std::stoi(seanceMovie->at(0)->at(3)),
                                            std::stoi(seanceMovie->at(0)->at(4)), std::stod(seanceMovie->at(0)->at(5)),
                                            seanceMovie->at(0)->at(6)), occupiedRooms.at(std::stoi(seanceRoom->at(0)->at(0))));
        seance_vec.push_back(*seance);

        Database::deleteResult(seanceRoom);
        Database::deleteResult(seanceMovie);
    }
    Database::deleteResult(allSeances);
}

ListSeancesCommand::ListSeancesCommand(Database *db, int seatsPerRow,
                                       const std::vector<Room *> &occupiedRooms) : DB(db),
                                                                                   seatsPerRow(seatsPerRow),
                                                                                   occupiedRooms(occupiedRooms) {}

