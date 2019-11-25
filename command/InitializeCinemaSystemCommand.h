//
// Created by piotr on 17.11.2019.
//

#ifndef SIMPLE_EXAMPLE_INITIALIZECINEMASYSTEMCOMMAND_H
#define SIMPLE_EXAMPLE_INITIALIZECINEMASYSTEMCOMMAND_H

#include "Command.h"
#include "../db/Database.h"
#include <string>
#include "../db/QueryLoader.h"

class InitializeCinemaSystemCommand: public Command {
private:
    std::string databaseName;
    Database * database;
public:
    explicit InitializeCinemaSystemCommand(std::string databaseName);
    void execute() override;
    Database * getDatabase();
};


#endif //SIMPLE_EXAMPLE_INITIALIZECINEMASYSTEMCOMMAND_H
