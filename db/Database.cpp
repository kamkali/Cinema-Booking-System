//
// Created by ubuntu on 11/14/19.
//

#include "Database.h"
#include <iostream>
#include "../exception/InitializeDatabaseException.h"

static std::vector<std::vector<std::string> *> *latestResults;

static int callback(void *data, int argc, char **argv, char **azColName) {

    latestResults->push_back(new std::vector<std::string>());

    for (int i = 0; i < argc; i++)
        latestResults->back()->push_back(argv[i] ? argv[i] : "NULL");

    return 0;
}

Database::Database(std::map<unsigned int, std::string> &queries):queries(queries) {
    DB = nullptr;
}

void Database::initialize(const std::string& name) {
    if(sqlite3_open(name.c_str(), &DB))
        throw InitializeDatabaseException(); //TODO add exception
}

void Database::close() {
    sqlite3_close(DB);
}

std::vector<std::vector<std::string> *> *Database::execute(QueryName queryName, const std::string args[]) {

    std::string queryToExecute = QueryParser::parse(queries[queryName], args);

    latestResults = new std::vector<std::vector<std::string> *>();

    sqlite3_exec(DB, queryToExecute.c_str(), callback, nullptr, nullptr);

    return latestResults;
}

std::vector<std::vector<std::string> *> *Database::execute(QueryName queryName) {

    std::string queryToExecute = queries[queryName];

    latestResults = new std::vector<std::vector<std::string> *>();

    sqlite3_exec(DB, queryToExecute.c_str(), callback, nullptr, nullptr);

    return latestResults;
}

void Database::deleteResult(std::vector<std::vector<std::string> *> *result) {

    for (auto i : *result)
        delete i;

    delete result;
}
