#include <iostream>

//
// Created by Piotr on 12.11.2019.
//
#include "Movie.h"
#include "CinemaRoom.h"

int main(int argc, char * argv[]){


    MovieDescription descriptionMovie;


    Movie movie2("tyt", "autor", 1999, 123, 12344.5, time(nullptr), descriptionMovie);

    std::vector<Seat> seats(10);
    RoomDescription * roomDescription = new RoomDescription(1,3, "XDD");
    CinemaRoom cinemaRoom(seats,  *roomDescription);
    std::cout << cinemaRoom.getDescription().getDescription() << std::endl;

    return 0;
}
