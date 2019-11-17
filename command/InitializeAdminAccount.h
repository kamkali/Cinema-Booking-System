//
// Created by piotr on 17.11.2019.
//

#ifndef SIMPLE_EXAMPLE_INITIALIZEADMINACCOUNT_H
#define SIMPLE_EXAMPLE_INITIALIZEADMINACCOUNT_H

#include <string>
#include "Command.h"
#include "../db/Database.h"

class InitializeAdminAccount: public Command {
private:
    Database * database;
    std::string username;
    std::string password;
public:
    InitializeAdminAccount(Database * db, std::string username, std::string password);
    void execute() override;
};


#endif //SIMPLE_EXAMPLE_INITIALIZEADMINACCOUNT_H
