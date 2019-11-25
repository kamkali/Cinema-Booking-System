//
// Created by piotr on 17.11.2019.
//

#ifndef SIMPLE_EXAMPLE_RETURNROOMCOMMAND_H
#define SIMPLE_EXAMPLE_RETURNROOMCOMMAND_H


#include "Command.h"
#include "../db/Database.h"
#include "../room/RoomFactory.h"

class ReturnRoomCommand: public Command {
private:
    Database * database;
    RoomFactory * roomPool;
    Room * room;
    std::string role;
public:
    ReturnRoomCommand(Database * database, RoomFactory * roomPool, Room * room, std::string role);
    void execute() override;
};


#endif //SIMPLE_EXAMPLE_RETURNROOMCOMMAND_H
