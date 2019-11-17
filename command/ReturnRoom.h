//
// Created by piotr on 17.11.2019.
//

#ifndef SIMPLE_EXAMPLE_RETURNROOM_H
#define SIMPLE_EXAMPLE_RETURNROOM_H


#include "Command.h"
#include "../db/Database.h"
#include "../room/RoomFactory.h"

class ReturnRoom: public Command {
private:
    Database * database;
    RoomFactory * roomPool;
    Room * room;
    std::string role;
public:
    ReturnRoom(Database * database, RoomFactory * roomPool, Room * room, std::string role);
    void execute() override;
};


#endif //SIMPLE_EXAMPLE_RETURNROOM_H
