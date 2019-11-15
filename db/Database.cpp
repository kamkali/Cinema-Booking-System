//
// Created by ubuntu on 11/14/19.
//

#include "Database.h"
#include <iostream>
#include "../exception/InitializeDatabaseException.h"

static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);

    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
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

void Database::execute(QueryName queryName, const std::string args[]) {

    std::string queryToExecute = QueryParser::parse(queries[queryName], args);

    std::cout << queryToExecute << std::endl;

    char ** msg;

    sqlite3_exec(DB, queryToExecute.c_str(), nullptr, nullptr, nullptr);


//TODO execute
}

void Database::execute(QueryName queryName) {

    std::string queryToExecute = queries[queryName];

    sqlite3_exec(DB, queryToExecute.c_str(), nullptr, nullptr, nullptr);
}
