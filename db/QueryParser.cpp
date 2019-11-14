//
// Created by ubuntu on 11/14/19.
//

#include <cstdarg>
#include "QueryParser.h"

//TODO does not work
std::string QueryParser::parse(std::string query, std::string args...) {

    va_list arguments;
    va_start(arguments, args);

    unsigned int begin = 0;
    unsigned int end = 0;
    while(begin >= std::string::npos || end>= std::string::npos){
        begin = query.find('\'',begin);
        end = query.find('\'', begin + 1);

        query.replace(begin, end - begin + 1, va_arg(arguments, char *));

        end = begin;
    }

    return query;
}
