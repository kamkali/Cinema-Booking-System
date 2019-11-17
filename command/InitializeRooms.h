//
// Created by piotr on 17.11.2019.
//

#ifndef SIMPLE_EXAMPLE_INITIALIZEROOMS_H
#define SIMPLE_EXAMPLE_INITIALIZEROOMS_H

#include "Command.h"
#include "../db/Database.h"
#include "../room/RoomFactory.h"
#include "../room/CinemaRoomFactory.h"

class InitializeRooms: public Command {
private:
    Database * database;
    size_t roomNumber;
    size_t seatsNumber;
    size_t seatsPerRow;
    RoomFactory * roomPool;

public:
    InitializeRooms(Database * database, size_t roomNumber, size_t seatsNumber, size_t rowsNumber);
    void execute() override;
    RoomFactory * getRoomPool();

};


#endif //SIMPLE_EXAMPLE_INITIALIZEROOMS_H
