//
// Created by ubuntu on 11/14/19.
//

#include "Database.h"

void Database::initialize(const std::string& name) {
    if(sqlite3_open(name.c_str(), &DB))
        throw "initialize error";
}

void Database::close() {
    sqlite3_close(DB);
}
