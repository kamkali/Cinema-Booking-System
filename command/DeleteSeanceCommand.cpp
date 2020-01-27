//
// Created by piotr on 20.11.2019.
//

#include "DeleteSeanceCommand.h"

#include <utility>
#include "ReturnRoomCommand.h"

void DeleteSeanceCommand::execute() {

    if(role == "ROLE_ADMIN") {

        std::string arg[] = {seanceName};

        std::vector<std::vector<std::string> *> *seance = database->execute(QueryName::SEANS_SELECT_BY_NAME, arg);

        int seanceId = std::stoi(seance->at(0)->at(0));

        Database::deleteResult(seance);

        std::string argSelectRoom[] = {std::to_string(seanceId)};

        std::vector<std::vector<std::string> *> *room = database->execute(QueryName::ROOM_SELECT_BY_SEANS_ID, argSelectRoom);

        int roomId = std::stoi(room->at(0)->at(0));

        Database::deleteResult(room);

        CinemaRoom * roomInstance = nullptr;

        for(unsigned int i = 0; i < occupiedRooms->size(); i++){
            roomInstance = dynamic_cast<CinemaRoom *>(occupiedRooms->at(i));
            if(roomInstance->getId() == roomId) {
                occupiedRooms->erase(occupiedRooms->begin()+i);
                break;
            }
        }

        if(roomInstance == nullptr) {
            std::cout << "Room instance does not exist in occupied rooms vector" << std::endl;
            return;
        }

        Command *command = new ReturnRoomCommand(database, roomPool, roomInstance, role);

        command->execute();

        std::string argDeleteSeance[] = {std::to_string(seanceId)};

        Database::deleteResult(database->execute(QueryName::SEANS_DELETE, argDeleteSeance));
    } else {
        std::cout << "User is not an admin" << std::endl;
    }
}

DeleteSeanceCommand::DeleteSeanceCommand(Database *database, std::string seanceName, RoomFactory *roomPool, std::vector<Room*> * occupiedRooms, std::string role)
        : database(database), seanceName(seanceName), roomPool(roomPool), occupiedRooms(occupiedRooms), role(std::move(role)) {}
