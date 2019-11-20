//
// Created by piotr on 20.11.2019.
//

#ifndef SIMPLE_EXAMPLE_DELETESEANCE_H
#define SIMPLE_EXAMPLE_DELETESEANCE_H


#include "Command.h"
#include "../db/Database.h"
#include "../seance/Seance.h"
#include "../room/RoomFactory.h"

class DeleteSeance: public Command {
private:
    Database * database;
    Seance * seance;
    RoomFactory * roomPool;
    std::string role;
public:
    DeleteSeance(Database *database, Seance *seance, RoomFactory *roomPool, std::string role);
    void execute() override;
};


#endif //SIMPLE_EXAMPLE_DELETESEANCE_H
