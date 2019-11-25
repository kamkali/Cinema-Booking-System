//
// Created by piotr on 19.11.2019.
//

#ifndef SIMPLE_EXAMPLE_CREATESEANCECOMMAND_H
#define SIMPLE_EXAMPLE_CREATESEANCECOMMAND_H


#include "Command.h"
#include "../db/Database.h"
#include "../seance/Seance.h"

class CreateSeanceCommand: public Command {
private:
    Database * database;
    Seance * seance;
    Room * room;
    Movie * movie;
    std::string name;

public:
    CreateSeanceCommand(Database * database, std::string name, Room * room, Movie * movie);
    void execute() override;
    Seance * getSeance();
};


#endif //SIMPLE_EXAMPLE_CREATESEANCECOMMAND_H
