#include <utility>

//
// Created by Piotr on 12.11.2019.
//

#include "CinemaRoom.h"


std::vector<Seat*> & CinemaRoom::getSeats() {
    return seats;
}

int CinemaRoom::getId() const {
    return id;
}

void CinemaRoom::setId(int id) {
    CinemaRoom::id = id;
}


const std::string &CinemaRoom::getName() const {
    return name;
}

void CinemaRoom::setName(const std::string &name) {
    CinemaRoom::name = name;
}

void CinemaRoom::setSeats(const std::vector<Seat *> &seats) {
    CinemaRoom::seats = seats;
}

size_t CinemaRoom::getNumber() const {
    return number;
}

void CinemaRoom::setNumber(size_t number) {
    CinemaRoom::number = number;
}

size_t CinemaRoom::getFloor() const {
    return floor;
}

void CinemaRoom::setFloor(size_t floor) {
    CinemaRoom::floor = floor;
}

CinemaRoom::CinemaRoom(): id(0) {

}

CinemaRoom::CinemaRoom(int id, std::string name, std::vector<Seat *> &seats, size_t number, size_t floor): id(id), name(std::move(name)), seats(seats), number(number), floor(floor) {

}
