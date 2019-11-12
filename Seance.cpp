//
// Created by Kamil Kaliś on 12/11/2019.
//

#include <iostream>
#include <fstream>
#include "Seance.h"

using namespace std;


Seance::Seance(const Movie &showingMovie, const CinemaRoom &showingRoom, time_t showingStart) : showingMovie(
        showingMovie), showingRoom(showingRoom), showingStart(showingStart) {}

Seance::~Seance() {

}

const Movie &Seance::getShowingMovie() const {
    return showingMovie;
}

void Seance::setShowingMovie(const Movie &showingMovie) {
    Seance::showingMovie = showingMovie;
}

const CinemaRoom &Seance::getShowingRoom() const {
    return showingRoom;
}

void Seance::setShowingRoom(const CinemaRoom &showingRoom) {
    Seance::showingRoom = showingRoom;
}

time_t Seance::getShowingStart() const {
    return showingStart;
}

void Seance::setShowingStart(time_t showingStart) {
    Seance::showingStart = showingStart;
}

void Seance::playCommercial() {
    cout<<"#########################  REKLAMA  #########################"<<endl;
    cout<<"#                    _                                      #"<<endl;
    cout<<"#                  -=\\`\\                                    #"<<endl;
    cout<<R"(#              |\ ____\_\__                                 #)"<<endl;
    cout<<R"(#            -=\c`""""""" "`)                               #)"<<endl;
    cout<<"#               `~~~~~/ /~~`\                                #"<<endl;
    cout<<"#                 -==/ /                                    #"<<endl;
    cout<<"#                   '-'                                     #"<<endl;
    cout<<"#                  _  _                                     #"<<endl;
    cout<<"#                 ( `   )_                                  #"<<endl;
    cout<<"#                (    )    `)                               #"<<endl;
    cout<<"#              (_   (_ .  _) _)                             #"<<endl;
    cout<<"#                                             _             #"<<endl;
    cout<<"#                                            (  )           #"<<endl;
    cout<<"#             _ .                         ( `  ) . )        #"<<endl;
    cout<<"#           (  _ )_                      (_, _(  ,_)_)      #"<<endl;
    cout<<"#         (_  _(_ ,)                                        #"<<endl;
    cout<<"LINIE LOTNICZE KUGLAN&KALI AIRLINES >>>>> KUP BILET NA STRONIE WWW.KUGLANKALIS.COM"<<endl;
}

