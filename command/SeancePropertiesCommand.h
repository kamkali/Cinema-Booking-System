//
// Created by Kamil Kaliś on 21/11/2019.
//

#ifndef SIMPLE_EXAMPLE_SEANCEPROPERTIESCOMMAND_H
#define SIMPLE_EXAMPLE_SEANCEPROPERTIESCOMMAND_H


#include "../db/Database.h"
#include "../seance/Seance.h"
#include "Command.h"

class SeancePropertiesCommand: public Command {
private:
    Database *DB;
    int seanceId;
    std::vector<Room *> occupiedRooms;
    size_t seatsPerRow;
    Seance *seance;

public:
    SeancePropertiesCommand(Database *db, int seanceId, const std::vector<Room *> &occupiedRooms, size_t seatsPerRow);

    void execute() override;

    Seance *getSeance() const;

};


#endif //SIMPLE_EXAMPLE_SEANCEPROPERTIESCOMMAND_H
