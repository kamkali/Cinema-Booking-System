//
// Created by Piotr on 12.11.2019.
//

#include "CinemaRoomFactory.h"


CinemaRoomFactory::CinemaRoomFactory() {

    for(int i = 0; i < 10; i++)
    {
        std::vector<Seat> seats(100);

        RoomDescription description(i + 1, i % 3, "sala numer: " + std::to_string(i + 1));
        Room * room = new CinemaRoom(seats, description);
        freeRooms.push_back(*room);
    }
}

void CinemaRoomFactory::returnInstance(Room & room) {
    freeRooms.push_back(room);
}

Room &CinemaRoomFactory::getInstance() {
    Room room = freeRooms.pop_back();


    return room;
}
