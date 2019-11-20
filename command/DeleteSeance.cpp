//
// Created by piotr on 20.11.2019.
//

#include "DeleteSeance.h"

#include <utility>
#include "ReturnRoom.h"

void DeleteSeance::execute() {

    if(role == "ROLE_ADMIN") {
        Movie *movie = seance->getShowingMovie();

        std::string args[] = {std::to_string(movie->getId())};

        Database::deleteResult(database->execute(QueryName::MOVIE_DELETE_BY_ID, args));

        Command *command = new ReturnRoom(database, roomPool, seance->getShowingRoom(), role);

        command->execute();
    } else {
        std::cout << "User is not an admin" << std::endl;
    }
}

DeleteSeance::DeleteSeance(Database *database, Seance *seance, RoomFactory *roomPool, std::string role)
        : database(database), seance(seance), roomPool(roomPool), role(std::move(role)) {}
