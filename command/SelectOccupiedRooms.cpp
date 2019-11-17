//
// Created by piotr on 17.11.2019.
//

#include "SelectOccupiedRooms.h"
#include "../room/CinemaRoom.h"

void SelectOccupiedRooms::execute() {
    std::vector<std::vector<std::string> *> *resultRooms = database->execute(QueryName::ROOM_SELECT_OCCUPIED_ROOMS);

    std::vector<std::vector<std::string> *> *seatsResult;

    for(auto room:*resultRooms) {
            std::string roomId[] = {room->at(0)};

            seatsResult = database->execute(QueryName::SEAT_SELECT_BY_ROOM_ID, roomId);

            std::vector<Seat *> seats;

            for (auto seat : *seatsResult)
                seats.push_back(new Seat(stoi(seat->at(3)) / (seatsPerRow + 1) + 1, stoi(seat->at(3))));

            size_t index = room->at(1).find(' ');
            size_t number = std::stoi(room->at(1).substr(index + 1, std::string::npos));

            auto *roomDescription = new RoomDescription(number, number % 3, room->at(1));

            occupiedRooms.push_back(new CinemaRoom(seats, roomDescription));
    }
}

SelectOccupiedRooms::SelectOccupiedRooms(Database *database, size_t seatsPerRow): database(database), seatsPerRow(seatsPerRow) {
    occupiedRooms = std::vector<Room *>();
}

std::vector<Room *> SelectOccupiedRooms::getOccupiedRooms() {
    return occupiedRooms;
}
