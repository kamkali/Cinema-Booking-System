#include <iostream>

//
// Created by Piotr on 12.11.2019.
//
#include "Movie.h"
#include "CinemaRoom.h"
#include "Seance.h"

int main(int argc, char * argv[]){


    MovieDescription descriptionMovie;


    Movie movie2("tyt", "autor", 1999, 123, 12344.5, descriptionMovie);

    std::vector<Seat> seats;
    RoomDescription * roomDescription = new RoomDescription(1,3, "XDD");
    CinemaRoom cinemaRoom(seats,  *roomDescription);
    std::cout << cinemaRoom.getDescription() << std::endl;

    Seance seans(movie2, cinemaRoom, time(nullptr));

    seans.playCommercial();

    return 0;
}
