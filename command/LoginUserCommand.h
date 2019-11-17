//
// Created by Kamil Kaliś on 17/11/2019.
//

#ifndef SIMPLE_EXAMPLE_LOGINUSERCOMMAND_H
#define SIMPLE_EXAMPLE_LOGINUSERCOMMAND_H


#include "../db/Database.h"
#include "Command.h"

class LoginUserCommand : public Command {
private:
    Database *DB;
    std::string username;
    std::string password;
    bool Logged;

public:
    LoginUserCommand(Database *db, const std::string &username, const std::string &password);

    void execute() override;

    bool isLogged() const;
};





#endif //SIMPLE_EXAMPLE_LOGINUSERCOMMAND_H
