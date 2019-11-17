//
// Created by piotr on 17.11.2019.
//

#ifndef SIMPLE_EXAMPLE_INITIALIZECINEMASYSTEM_H
#define SIMPLE_EXAMPLE_INITIALIZECINEMASYSTEM_H

#include "Command.h"
#include "../db/Database.h"
#include <string>
#include "../db/QueryLoader.h"

class InitializeCinemaSystem: public Command {
private:
    std::string databaseName;
    Database * database;
public:
    explicit InitializeCinemaSystem(std::string databaseName);
    void execute() override;
    Database * getDatabase();
};


#endif //SIMPLE_EXAMPLE_INITIALIZECINEMASYSTEM_H
