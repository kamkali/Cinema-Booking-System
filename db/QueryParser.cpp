//
// Created by ubuntu on 11/14/19.
//

#include <cstdarg>
#include "QueryParser.h"



std::string QueryParser::parse(std::string query, const std::string args[]) {
    unsigned int i = 0;
    unsigned int begin = 0;
    unsigned int end = 0;

    while(begin < query.size()){
        begin = query.find('\'', begin);
        end = query.find('\'', begin + 1);

        if(begin == std::string::npos || end == std::string::npos)
            break;

        query.replace(begin, end - begin + 1, args[i]);
        begin += args[i].size();
        i++;
    }

    return query;
}
