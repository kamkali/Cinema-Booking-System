//
// Created by Piotr on 12.11.2019.
//

#ifndef SIMPLE_EXAMPLE_DESCRIPTION_H
#define SIMPLE_EXAMPLE_DESCRIPTION_H

#include <string>

class Description {
public:
    virtual std::string getDescription() {
        return nullptr;
    }
};


#endif //SIMPLE_EXAMPLE_DESCRIPTION_H
