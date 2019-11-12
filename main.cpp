#include <iostream>

//
// Created by Piotr on 12.11.2019.
//
#include "Movie.h"
#include "CinemaRoom.h"
#include "RoomFactory.h"
#include "CinemaRoomFactory.h"


int main(int argc, char * argv[]){

//    std::vector<Seat> seats;
//
//    RoomDescription * description = new RoomDescription(1, 2, "abc");
//
//    Room * room = new CinemaRoom(seats, *description);
//
//    std::cout<<room->getDescription()<<std::endl;




    auto * roomFactory = new CinemaRoomFactory();

    std::cout<<roomFactory->getInstance()->getDescription()<<std::endl;

    Room * room;


    room = roomFactory->getInstance();


    roomFactory->returnInstance(room);

    std::cout<<roomFactory->getInstance()->getDescription()<<std::endl;





    return 0;
}
