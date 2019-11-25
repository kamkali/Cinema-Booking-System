//
// Created by piotr on 17.11.2019.
//

#include "InitializeRoomsCommand.h"

void InitializeRoomsCommand::execute() {
    std::vector<std::vector<std::string> *> *result = database->execute(QueryName::ROOM_SELECT_ALL);

    if((*result).empty()){

        for(size_t i = 1; i <= roomNumber; i++) {
            std::string arg[] = {"Room " + std::to_string(i), "0"};
            Database::deleteResult(database->execute(QueryName::ROOM_INSERT_BY_NAME, arg));

            result = database->execute(QueryName::ROOM_SELECT_BY_NAME, arg);
            size_t roomId = std::stoi((*result).at(0)->at(0));
            Database::deleteResult(result);

            for(size_t j = 1; j <= seatsNumber; j++) {
                std::string args[] = {std::to_string(roomId), "0", std::to_string(j)};
                Database::deleteResult(database->execute(QueryName::SEAT_INSERT, args));
            }
        }
    }

    result = database->execute(QueryName::ROOM_SELECT_ALL);

    std::vector<std::vector<std::string> *> *seatsResult;

    for(auto room:*result) {

        if (std::stoi(room->at(2)) == 0) {

            std::string roomId[] = {room->at(0)};

            seatsResult = database->execute(QueryName::SEAT_SELECT_BY_ROOM_ID, roomId);

            std::vector<Seat *> seats;

            for (auto seat : *seatsResult)
                seats.push_back(new Seat(stoi(seat->at(0)) ,stoi(seat->at(3)) / (seatsPerRow + 1) + 1, stoi(seat->at(3))));

            size_t index = room->at(1).find(' ');
            size_t number = std::stoi(room->at(1).substr(index + 1, std::string::npos));

            roomPool->returnInstance(new CinemaRoom(stoi(room->at(0)), room->at(1), seats, number, number % 3));
        }
    }
}

InitializeRoomsCommand::InitializeRoomsCommand(Database *database, size_t roomNumber, size_t seatsNumber, size_t rowsNumber):
        database(database), roomNumber(roomNumber), seatsNumber(seatsNumber), seatsPerRow(rowsNumber) {
    roomPool = new CinemaRoomFactory();
}

RoomFactory *InitializeRoomsCommand::getRoomPool() {
    return roomPool;
}
