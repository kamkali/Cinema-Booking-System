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

        std::string args[] = {dynamic_cast<CinemaRoom *>(room)->getName(), "0", std::to_string(roomId)};

        Database::deleteResult(database->execute(QueryName::ROOM_UPDATE_BY_ID, args));
    } else{
        std::cout << "Return room object is only allowed to admin" << std::endl;
    }
}

ReturnRoom::ReturnRoom(Database *database, RoomFactory * roomPool, Room * room, std::string role): database(database),
roomPool(roomPool), room(room), role(std::move(role)) {

}
