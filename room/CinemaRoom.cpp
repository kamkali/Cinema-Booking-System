#include <utility>

//
// Created by Piotr on 12.11.2019.
//

#include "CinemaRoom.h"


std::vector<Seat*> & CinemaRoom::getSeats() {
    return seats;
}

RoomDescription CinemaRoom::getDescription() {
    return  *description;
}

CinemaRoom::CinemaRoom(): id(0), Room() {
    description = nullptr;
}

int CinemaRoom::getId() const {
    return id;
}

void CinemaRoom::setId(int id) {
    CinemaRoom::id = id;
}

CinemaRoom::CinemaRoom(int id, std::string name,  std::vector<Seat *> &seats, const RoomDescription *description): id(id), name(std::move(name)), Room(), seats(seats) {
    this -> description = const_cast<RoomDescription *>(description);
}

const std::string &CinemaRoom::getName() const {
    return name;
}

void CinemaRoom::setName(const std::string &name) {
    CinemaRoom::name = name;
}
