#include <iostream>

//
// Created by Piotr on 12.11.2019.
//
#include "Movie.h"
#include "MovieDescription.h"
#include "Room.h"
#include "CinemaRoom.h"

int main(int argc, char * argv[]){
    MovieDescription opisFilmu;
    Room room();

    Movie film("tyt", "autor", 1999, 123, 12344.5, time(NULL), room, opisFilmu);
    return 0;
}
