//
// Created by Kamil Kaliś on 17/11/2019.
//

#include "RegisterUserCommand.h"

#define ROLE_USER "ROLE_USER"

#include <utility>

RegisterUserCommand::RegisterUserCommand(Database *db, const std::string &username, const std::string &password)
        : DB(db), username(username), password(password) {}


void RegisterUserCommand::execute() {
    std::string args[] = {username};

    std::vector<std::vector<std::string> *> *result = DB->execute(USER_SELECT_BY_NAME, args);

    if ((*result).empty()) {
        std::string create[] = {std::move(username), std::move(password), ROLE_USER};

        DB->execute(USER_INSERT, create);
    }
    Database::deleteResult(result);
}
