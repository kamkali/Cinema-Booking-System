//
// Created by ubuntu on 11/14/19.
//

#include <cstdarg>
#include "QueryParser.h"



std::string QueryParser::parse(std::string query, const std::string args[]) {
    unsigned int i = 0;
    unsigned long beginSingle = 0;
    unsigned long beginDouble = 0;
    unsigned long endSingle = 0;
    unsigned long endDouble = 0;

    while (beginSingle < query.size()) {
        beginSingle = query.find('\'', beginSingle);
        beginDouble = query.find('"', beginDouble);

        if (beginSingle < beginDouble) {
            endSingle = query.find('\'', beginSingle + 1);

            if (beginSingle == std::string::npos || endSingle == std::string::npos)
                break;

            query.replace(beginSingle, endSingle - beginSingle + 1, args[i]);
            beginSingle += args[i].size();
            beginDouble = beginSingle;
        } else {
            endDouble = query.find('"', beginDouble + 1);

            if (beginDouble == std::string::npos || endDouble == std::string::npos)
                break;

            query.replace(beginDouble + 1, endDouble - beginDouble - 1, args[i]);
            beginDouble += args[i].size() + 2;
            beginSingle = beginDouble;
        }

        i++;
    }

    return query;
}
