//
// Created by Kamil Kaliś on 20/11/2019.
//

#ifndef SIMPLE_EXAMPLE_LISTSEANSESCOMMAND_H
#define SIMPLE_EXAMPLE_LISTSEANSESCOMMAND_H


#include "Command.h"
#include "../db/Database.h"
#include "../seance/Seance.h"

class ListSeansesCommand: public Command {
private:
    Database *DB;
    std::vector<Seance> seance_vec;

public:
    ListSeansesCommand(Database *db, const std::vector<Seance> &seanceVec);

    void execute() override;

    const std::vector<Seance> &getSeanceVec() const;
};


#endif //SIMPLE_EXAMPLE_LISTSEANSESCOMMAND_H
