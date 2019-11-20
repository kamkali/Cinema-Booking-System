//
// Created by piotr on 20.11.2019.
//

#include "DeleteSeance.h"

#include <utility>
#include "ReturnRoom.h"

void DeleteSeance::execute() {

    if(role == "ROLE_ADMIN") {
        Command *command = new ReturnRoom(database, roomPool, seance->getShowingRoom(), role);

        command->execute();

        std::string arg[] = {std::to_string(seance->getId())};

        Database::deleteResult(database->execute(QueryName::SEANS_DELETE, arg));
    } else {
        std::cout << "User is not an admin" << std::endl;
    }
}

DeleteSeance::DeleteSeance(Database *database, Seance *seance, RoomFactory *roomPool, std::string role)
        : database(database), seance(seance), roomPool(roomPool), role(std::move(role)) {}
