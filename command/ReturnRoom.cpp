//
// Created by piotr on 17.11.2019.
//

#include "ReturnRoom.h"
#include "../room/CinemaRoom.h"

#include <utility>

void ReturnRoom::execute() {
    if(role == "ROLE_ADMIN") {
        roomPool->returnInstance(room);

        std::string arg[] = {dynamic_cast<CinemaRoom *>(room)->getName()};

        std::vector<std::vector<std::string> *> *result = database->execute(QueryName::ROOM_SELECT_BY_NAME, arg);

        size_t roomId = std::stoi((*result).at(0)->at(0));

        Database::deleteResult(result);

        std::string seatSelectArg[] = {std::to_string(roomId)};

        std::vector<std::vector<std::string> *> *seatsInRoom = database->execute(QueryName::SEAT_SELECT_BY_ROOM_ID, seatSelectArg);

        std::string * seatUpdateArgs;

        for(auto seat:*seatsInRoom){

            seatUpdateArgs = new std::string[4];

            seatUpdateArgs[0] = std::to_string(roomId);
            seatUpdateArgs[1] = "0";
            seatUpdateArgs[2] = seat->at(3);
            seatUpdateArgs[3] = std::to_string(roomId);

            Database::deleteResult(database->execute(QueryName::SEAT_UPDATE_BY_ROOM_ID, seatUpdateArgs));

            delete[] seatUpdateArgs;
        }

        Database::deleteResult(seatsInRoom);

        std::string args[] = {dynamic_cast<CinemaRoom *>(room)->getName(), "0", std::to_string(roomId)};

        Database::deleteResult(database->execute(QueryName::ROOM_UPDATE_BY_ID, args));
    } else{
        std::cout << "Return room object is only allowed to admin" << std::endl;
    }
}

ReturnRoom::ReturnRoom(Database *database, RoomFactory * roomPool, Room * room, std::string role): database(database),
roomPool(roomPool), room(room), role(std::move(role)) {

}
