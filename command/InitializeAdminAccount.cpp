//
// Created by piotr on 17.11.2019.
//

#include "InitializeAdminAccount.h"

#include <utility>

void InitializeAdminAccount::execute() {
    std::string args[] = {username};

    std::vector<std::vector<std::string> *> *result = database->execute(QueryName::USER_SELECT_BY_NAME, args);

    if((*result).empty()){

        std::string creationArgs[] = {std::move(username), std::move(password), "ROLE_ADMIN"};

        database->execute(QueryName::USER_INSERT, creationArgs);
    }

    Database::deleteResult(result);
}

InitializeAdminAccount::InitializeAdminAccount(Database * db, std::string username, std::string password): database(db), username(std::move(username)), password(std::move(password)) {
}

