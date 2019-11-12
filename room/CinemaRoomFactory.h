//
// Created by Piotr on 12.11.2019.
//

#ifndef SIMPLE_EXAMPLE_CINEMAROOMFACTORY_H
#define SIMPLE_EXAMPLE_CINEMAROOMFACTORY_H

#include <queue>
#include "RoomFactory.h"
#include "CinemaRoom.h"

class CinemaRoomFactory: public RoomFactory {
private:
    std::queue<Room *> freeRooms;

public:
    CinemaRoomFactory();
    Room * getInstance() override;
    void returnInstance(Room * room) override;

};


#endif //SIMPLE_EXAMPLE_CINEMAROOMFACTORY_H
