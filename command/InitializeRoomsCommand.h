//
// Created by piotr on 17.11.2019.
//

#ifndef SIMPLE_EXAMPLE_INITIALIZEROOMSCOMMAND_H
#define SIMPLE_EXAMPLE_INITIALIZEROOMSCOMMAND_H

#include "Command.h"
#include "../db/Database.h"
#include "../room/RoomFactory.h"
#include "../room/CinemaRoomFactory.h"

class InitializeRoomsCommand: public Command {
private:
    Database * database;
    size_t roomNumber;
    size_t seatsNumber;
    size_t seatsPerRow;
    RoomFactory * roomPool;

public:
    InitializeRoomsCommand(Database * database, size_t roomNumber, size_t seatsNumber, size_t rowsNumber);
    void execute() override;
    RoomFactory * getRoomPool();

};


#endif //SIMPLE_EXAMPLE_INITIALIZEROOMSCOMMAND_H
