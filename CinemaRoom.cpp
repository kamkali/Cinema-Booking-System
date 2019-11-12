//
// Created by Piotr on 12.11.2019.
//

#include "CinemaRoom.h"


std::vector<Seat> & CinemaRoom::getSeats() {
    return seats;
}


CinemaRoom::CinemaRoom(std::vector<Seat> & seats, const RoomDescription& description): Room(), seats(seats), description(description) {
}

Description CinemaRoom::getDescription() {
    return  description;
}

CinemaRoom::CinemaRoom(): Room() {

}
