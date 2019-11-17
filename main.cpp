#include <iostream>

//
// Created by Piotr on 12.11.2019.
//
#include <iostream>
#include "movie/Movie.h"
#include "room/CinemaRoom.h"
#include "room/RoomFactory.h"
#include "room/CinemaRoomFactory.h"
#include "db/Database.h"
#include "sqlite/sqlite3.h"
#include "db/QueryLoader.h"
#include "command/Command.h"
#include "command/InitializeAdminAccount.h"
#include "command/InitializeCinemaSystem.h"
#include "command/RegisterUserCommand.h"
#include "command/LoginUserCommand.h"

int main(int argc, char *argv[]) {

    Command *command = new InitializeCinemaSystem("cinema");

    command->execute();

    Database *database = dynamic_cast<InitializeCinemaSystem *>(command)->getDatabase();

    command = new InitializeAdminAccount(database, "admin", "admin");

    command->execute();

    Command *userRegister = new RegisterUserCommand(database, "janko123", "jaknoPass123");
    userRegister->execute();

    Command *logUser = new LoginUserCommand(database, "janko123", "jaknoPass123");
//    Command *logUser = new LoginUserCommand(database, "janko123", "wrongPass");

    logUser->execute();

    bool loggedUser = dynamic_cast<LoginUserCommand *>(logUser)->isLogged();
    if (!loggedUser)
        std::cout << "Cannot log user" << std::endl;

    database->close();
}
