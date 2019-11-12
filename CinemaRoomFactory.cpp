//
// Created by Piotr on 12.11.2019.
//
#include <iostream>
#include "CinemaRoomFactory.h"


CinemaRoomFactory::CinemaRoomFactory() {

    for(int i = 0; i < 10; i++)
    {
        std::vector<Seat> seats(100);

        RoomDescription description(i + 1, i % 3, "sala numer: " + std::to_string(i + 1));
        Room * room = new CinemaRoom(seats, description);
        freeRooms.push(room);
    }
}

void CinemaRoomFactory::returnInstance(Room * room) {
    freeRooms.push(room);
}

Room * CinemaRoomFactory::getInstance() {
    if(!freeRooms.empty()){
        Room * room = freeRooms.front();
        freeRooms.pop();
        return room;
    } else
        return nullptr;
}
