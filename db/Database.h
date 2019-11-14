//
// Created by ubuntu on 11/14/19.
//

#ifndef SIMPLE_EXAMPLE_DATABASE_H
#define SIMPLE_EXAMPLE_DATABASE_H
#include <string>
#include "../sqlite/sqlite3.h"

class Database {
private:
    sqlite3* DB;
public:
    void initialize(const std::string& name);
    void close();

};


#endif //SIMPLE_EXAMPLE_DATABASE_H
