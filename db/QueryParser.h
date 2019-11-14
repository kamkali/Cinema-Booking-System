//
// Created by ubuntu on 11/14/19.
//

#ifndef SIMPLE_EXAMPLE_QUERYPARSER_H
#define SIMPLE_EXAMPLE_QUERYPARSER_H

#include <string>

class QueryParser {
public:
    static std::string parse(std::string query, std::string args...);
};


#endif //SIMPLE_EXAMPLE_QUERYPARSER_H
