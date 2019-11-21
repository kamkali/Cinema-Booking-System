//
// Created by Kamil Kaliś on 20/11/2019.
//

#ifndef SIMPLE_EXAMPLE_LISTSEANCESCOMMAND_H
#define SIMPLE_EXAMPLE_LISTSEANCESCOMMAND_H


#include "Command.h"
#include "../db/Database.h"
#include "../seance/Seance.h"

class ListSeancesCommand: public Command {
private:
    Database *DB;
    std::vector<Seance> seance_vec;
    int seatsPerRow;
    std::vector<Room*> occupiedRooms;

public:

    ListSeancesCommand(Database *db, int seatsPerRow, const std::vector<Room *> &occupiedRooms);

    void execute() override;

    const std::vector<Seance> &getSeanceVec() const;

};


#endif //SIMPLE_EXAMPLE_LISTSEANCESCOMMAND_H
