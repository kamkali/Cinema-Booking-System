//
// Created by piotr on 17.11.2019.
//

#ifndef SIMPLE_EXAMPLE_SELECTOCCUPIEDROOMS_H
#define SIMPLE_EXAMPLE_SELECTOCCUPIEDROOMS_H


#include "Command.h"
#include "../db/Database.h"
#include "../room/Room.h"

class SelectOccupiedRooms: public Command {
private:
    Database * database;
    std::vector<Room *> occupiedRooms;
    size_t seatsPerRow;
public:
    explicit SelectOccupiedRooms(Database * database, size_t rowNumber);
    void execute() override;
    std::vector<Room *> getOccupiedRooms();
};


#endif //SIMPLE_EXAMPLE_SELECTOCCUPIEDROOMS_H
