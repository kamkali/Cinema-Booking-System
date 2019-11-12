#include <iostream>

//
// Created by Piotr on 12.11.2019.
//
#include "Movie.h"
#include "CinemaRoom.h"
#include "RoomFactory.h"
#include "CinemaRoomFactory.h"


int main(int argc, char * argv[]){

    RoomFactory * roomFactory = new CinemaRoomFactory();

    Room room = roomFactory->getInstance();

    std::cout << room.getDescription();


    return 0;
}
