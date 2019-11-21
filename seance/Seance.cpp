#include <utility>

#include <utility>

//
// Created by Kamil Kaliś on 12/11/2019.
//

#include <iostream>
#include <fstream>
#include "Seance.h"
#include "../db/QueryLoader.h"
#include "../db/Database.h"

using namespace std;


Seance::Seance(int id, Movie *showingMovie, Room *showingRoom) : id(id), showingMovie(showingMovie),
                                                                 showingRoom(showingRoom) {
}


void Seance::playCommercial() {
    cout << "#########################  REKLAMA  #########################" << endl;
    cout << "#                    _                                      #" << endl;
    cout << "#                  -=\\`\\                                    #" << endl;
    cout << R"(#              |\ ____\_\__                                 #)" << endl;
    cout << R"(#            -=\c`""""""" "`)                               #)" << endl;
    cout << "#               `~~~~~/ /~~`\\                                #" << endl;
    cout << "#                 -==/ /                                    #" << endl;
    cout << "#                   '-'                                     #" << endl;
    cout << "#                  _  _                                     #" << endl;
    cout << "#                 ( `   )_                                  #" << endl;
    cout << "#                (    )    `)                               #" << endl;
    cout << "#              (_   (_ .  _) _)                             #" << endl;
    cout << "#                                             _             #" << endl;
    cout << "#                                            (  )           #" << endl;
    cout << "#             _ .                         ( `  ) . )        #" << endl;
    cout << "#           (  _ )_                      (_, _(  ,_)_)      #" << endl;
    cout << "#         (_  _(_ ,)                                        #" << endl;
    cout << "LINIE LOTNICZE KUGLAN&KALI AIRLINES >>>>> KUP BILET NA STRONIE WWW.KUGLANKALIS.COM" << endl;
}

int Seance::getId() const {
    return id;
}

void Seance::setId(int id) {
    Seance::id = id;
}

Movie *Seance::getShowingMovie() const {
    return showingMovie;
}

void Seance::setShowingMovie(Movie *showingMovie) {
    Seance::showingMovie = showingMovie;
}

Room *Seance::getShowingRoom() const {
    return showingRoom;
}

void Seance::setShowingRoom(Room *showingRoom) {
    Seance::showingRoom = showingRoom;
}

void Seance::printSeats(Database *database, int seatsInRow) {
    int row{0};
    int column{0};
    auto checkSeat =  dynamic_cast<CinemaRoom *>(this->getShowingRoom());

    for(int i = 1; i <= seatsInRow; i++){
        std::cout << i << " ";
    }
    std::cout << " " << std::endl << "– – – – – – – – – –" << std::endl;
    for (auto seat: checkSeat->getSeats()){

        std::string args[]{std::to_string(checkSeat->getId()), std::to_string(seat->getId())};

        std::vector<std::vector<std::string> *> *result = database->execute(QueryName::SEAT_SELECT_BY_ROOM_ID_AND_NUMBER_IN_ROOM, args);

        if (column == 10){
            std::cout << "| "<< ++row << std::endl;
            column = 0;
        }
        column++;

        std::cout << result->at(0)->at(2) << " ";

    }
    std::cout << "| "<< ++row << std::endl;
    std::cout << std::endl;
}

