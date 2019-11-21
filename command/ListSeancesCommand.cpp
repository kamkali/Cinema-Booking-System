//
// Created by Kamil Kaliś on 20/11/2019.
//

#include "ListSeancesCommand.h"
#include "SelectOccupiedRooms.h"


void ListSeancesCommand::execute() {
    seance_vec.clear();
    std::vector<std::vector<std::string> *> *allSeances = DB->execute(SEANS_SELECT_ALL);

    if ((*allSeances).empty()){
        std::cout << "There is no any seance" << std::endl;
    }else{
        for (auto singleSeance: *allSeances) {

            std::string movieId[] = {singleSeance->at(2)};


            std::vector<std::vector<std::string> *> *seanceRoom = DB->execute(ROOM_SELECT_OCCUPIED_ROOMS);

            std::vector<std::vector<std::string> *> *seanceMovie = DB->execute(MOVIE_SELECT_BY_ID, movieId);

            auto showingMovie = new Movie(std::stoi(seanceMovie->at(0)->at(0)), seanceMovie->at(0)->at(1),
                                          seanceMovie->at(0)->at(2), std::stoi(seanceMovie->at(0)->at(3)),
                                          std::stoi(seanceMovie->at(0)->at(4)), std::stod(seanceMovie->at(0)->at(5)),
                                          seanceMovie->at(0)->at(6));

            auto mySeanceId = std::stoi(singleSeance->at(0));
            int i{0};
            for (auto room: occupiedRooms) {
                if(mySeanceId == dynamic_cast<CinemaRoom *>(room)->getId()) {
                    break;
                }
                i++;
            }

            auto *seance = new Seance(std::stoi(singleSeance->at(0)),
                                      showingMovie, occupiedRooms.at(i));
            seance_vec.push_back(*seance);

            Database::deleteResult(seanceRoom);
            Database::deleteResult(seanceMovie);
        }
    }
    Database::deleteResult(allSeances);
}

ListSeancesCommand::ListSeancesCommand(Database *db, int seatsPerRow, const std::vector<Room *> &occupiedRooms) : DB(
        db), seatsPerRow(seatsPerRow), occupiedRooms(occupiedRooms) {}

const std::vector<Seance> &ListSeancesCommand::getSeanceVec() const {
    return seance_vec;
}









