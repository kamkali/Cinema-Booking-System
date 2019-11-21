//
// Created by Kamil Kaliś on 17/11/2019.
//

#include "LoginUserCommand.h"

LoginUserCommand::LoginUserCommand(Database *db, const std::string &username, const std::string &password) : DB(db),
                                                                                                             username(
                                                                                                                     username),
                                                                                                             password(
                                                                                                                     password) {}

void LoginUserCommand::execute() {
    std::string args[] = {username};

    std::vector<std::vector<std::string> *> *result = DB->execute(USER_SELECT_BY_NAME, args);

    if (result->at(0)->at(2) == password) {
        Logged = true;
        userId = std::stoi(result->at(0)->at(0));
    }
    else
        Logged = false;

    if(result->at(0)->at(3) == "ROLE_ADMIN")
        isAdmin = true;

    Database::deleteResult(result);
}

bool LoginUserCommand::isLogged() const {
    return Logged;
}

int LoginUserCommand::getUserId() const {
    return userId;
}

bool LoginUserCommand::isUserAdmin() const {
    return isAdmin;
}

