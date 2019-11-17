#include <utility>

//
// Created by Piotr on 12.11.2019.
//

#include "CinemaRoom.h"


std::vector<Seat*> & CinemaRoom::getSeats() {
    return seats;
}


CinemaRoom::CinemaRoom(std::vector<Seat *> & seats, const RoomDescription * description): Room(), seats(seats) {
    this -> description = const_cast<RoomDescription *>(description);
}

std::string CinemaRoom::getDescription() {
    return  description->getDescription();
}

CinemaRoom::CinemaRoom(): Room() {
    description = nullptr;
}
