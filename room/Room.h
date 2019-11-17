//
// Created by Piotr on 12.11.2019.
//

#ifndef SIMPLE_EXAMPLE_ROOM_H
#define SIMPLE_EXAMPLE_ROOM_H

#include <vector>
#include "../movie/Movie.h"
#include "Seat.h"
#include "../seance/Description.h"
#include "RoomDescription.h"

class Movie;

class Room{
public:
    Room() = default;

    virtual std::vector<Seat *> & getSeats() {};
    virtual RoomDescription getDescription() {};
};

#endif //SIMPLE_EXAMPLE_ROOM_H

