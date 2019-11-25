//
// Created by piotr on 17.11.2019.
//

#include "InitializeAdminAccountCommand.h"

#include <utility>

void InitializeAdminAccountCommand::execute() {
    std::string args[] = {username};

    std::vector<std::vector<std::string> *> *result = database->execute(QueryName::USER_SELECT_BY_NAME, args);

    if((*result).empty()){

        std::string creationArgs[] = {std::move(username), std::move(password), "ROLE_ADMIN"};

        database->execute(QueryName::USER_INSERT, creationArgs);
    }

    Database::deleteResult(result);
}

InitializeAdminAccountCommand::InitializeAdminAccountCommand(Database * db, std::string username, std::string password): database(db), username(std::move(username)), password(std::move(password)) {
}

