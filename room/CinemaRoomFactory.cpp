//
// Created by Piotr on 12.11.2019.
//
#include <iostream>
#include "CinemaRoomFactory.h"


CinemaRoomFactory::CinemaRoomFactory() {
    freeRooms = std::queue<Room *>();
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
