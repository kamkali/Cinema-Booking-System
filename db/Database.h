//
// Created by ubuntu on 11/14/19.
//

#ifndef SIMPLE_EXAMPLE_DATABASE_H
#define SIMPLE_EXAMPLE_DATABASE_H
#include <string>
#include "../sqlite/sqlite3.h"
#include "QueryLoader.h"
#include "QueryParser.h"
#include <vector>

class Database {
private:
    sqlite3* DB;
    std::map<unsigned int, std::string> queries;
public:
    explicit Database(std::map<unsigned int, std::string>& queries);
    void initialize(const std::string& name);
    void close();

    std::vector<std::vector<std::string> *> *execute(QueryName queryName);

    std::vector<std::vector<std::string> *> *execute(QueryName queryName, const std::string args[]);

};


#endif //SIMPLE_EXAMPLE_DATABASE_H
