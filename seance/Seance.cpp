#include <utility>

#include <utility>

//
// Created by Kamil Kaliś on 12/11/2019.
//

#include <iostream>
#include <fstream>
#include "Seance.h"

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

