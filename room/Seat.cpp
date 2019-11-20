//
// Created by Piotr on 12.11.2019.
//

#include "Seat.h"

int Seat::getId() const {
    return id;
}

void Seat::setId(int id) {
    Seat::id = id;
}

Seat::Seat(int id, size_t row, size_t seatNumber): id(id), row(row), seatNumber(seatNumber) {

}
