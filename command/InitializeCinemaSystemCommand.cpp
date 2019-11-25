//
// Created by piotr on 17.11.2019.
//

#include "InitializeCinemaSystemCommand.h"

#include <utility>

void InitializeCinemaSystemCommand::execute() {
    QueryLoader queryLoader;
    queryLoader.loadQueries();
    std::map<unsigned int, std::string> queries = queryLoader.getQueries();

    database = new Database(queries);
    database->initialize(databaseName);

    Database::deleteResult(database->execute(QueryName::USERS_CREATE));
    Database::deleteResult(database->execute(QueryName::MOVIES_CREATE));
    Database::deleteResult(database->execute(QueryName::ROOMS_CREATE));
    Database::deleteResult(database->execute(QueryName::SEATS_CREATE));
    Database::deleteResult(database->execute(QueryName::SEANSES_CREATE));
}

InitializeCinemaSystemCommand::InitializeCinemaSystemCommand(std::string databaseName): databaseName(std::move(databaseName)) {
    database = nullptr;
}

Database *InitializeCinemaSystemCommand::getDatabase() {
    return database;
}
