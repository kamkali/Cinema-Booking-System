//
// Created by Piotr on 12.11.2019.
//

#ifndef SIMPLE_EXAMPLE_SEAT_H
#define SIMPLE_EXAMPLE_SEAT_H

#include <iostream>

class Seat {
private:
    size_t row;
    size_t seatNumber;

public:
    Seat() = default;
    Seat(size_t row, size_t seatNumber);

};


#endif //SIMPLE_EXAMPLE_SEAT_H
