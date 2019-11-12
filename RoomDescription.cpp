#include <utility>

//
// Created by Piotr on 12.11.2019.
//

#include "RoomDescription.h"

RoomDescription::RoomDescription(size_t number, int floor, std::string name):number(number), floor(floor), name(std::move(name)) {

}

std::string RoomDescription::getDescription() {
    return "Room no. " + std::to_string(number) + ", floor: " + std::to_string(floor) + ", name: " + name + "\n";
}

RoomDescription::RoomDescription(const RoomDescription &roomDescription) {
    this->number = roomDescription.number;
    this->floor = roomDescription.floor;
    this->name = roomDescription.name;
}
