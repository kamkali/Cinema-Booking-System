//
// Created by Kamil Kaliś on 17/11/2019.
//

#ifndef SIMPLE_EXAMPLE_REGISTERUSERCOMMAND_H
#define SIMPLE_EXAMPLE_REGISTERUSERCOMMAND_H


#include "Command.h"
#include "../db/Database.h"

class RegisterUserCommand : public Command {
private:
    Database *DB;
    std::string username;
    std::string password;

public:
    RegisterUserCommand(Database *db, const std::string &username, const std::string &password);

    void execute() override;

};


#endif //SIMPLE_EXAMPLE_REGISTERUSERCOMMAND_H
