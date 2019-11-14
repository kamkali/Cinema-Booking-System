//
// Created by ubuntu on 11/14/19.
//

#include "Database.h"

Database::Database(std::map<unsigned int, std::string> &queries):queries(queries) {
    DB = nullptr;
}

void Database::initialize(const std::string& name) {
    if(sqlite3_open(name.c_str(), &DB))
        throw "initialize error";
}

void Database::close() {
    sqlite3_close(DB);
}

void Database::execute(QueryName queryName, const std::string &args, ...) {

    std::string queryToExecute = QueryParser::parse(queries[queryName],  args);


//TODO execute
}

void Database::execute(QueryName queryName) {

    std::string queryToExecute = queries[queryName];

}
