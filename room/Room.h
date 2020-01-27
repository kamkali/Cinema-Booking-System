//
// Created by Piotr on 12.11.2019.
//

#ifndef SIMPLE_EXAMPLE_ROOM_H
#define SIMPLE_EXAMPLE_ROOM_H

#include <vector>
#include "../movie/Movie.h"
#include "Seat.h"

class Movie;

class Room{
public:
    Room() = default;

    virtual std::vector<Seat *> & getSeats() {
        std::vector<Seat *> a;
        return a;
    };
};

#endif //SIMPLE_EXAMPLE_ROOM_H

