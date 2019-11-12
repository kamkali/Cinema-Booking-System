//
// Created by Piotr on 12.11.2019.
//

#ifndef SIMPLE_EXAMPLE_ROOMFACTORY_H
#define SIMPLE_EXAMPLE_ROOMFACTORY_H

#include "Room.h"

class RoomFactory {
public:
    virtual Room & getInstance() = 0;
    virtual void returnInstance(Room & room) = 0;
};


#endif //SIMPLE_EXAMPLE_ROOMFACTORY_H
