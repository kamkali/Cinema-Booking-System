#ifndef SIMPLE_EXAMPLE_DESCRIPTION_H
#define SIMPLE_EXAMPLE_DESCRIPTION_H

#include <string>

class Description {
public:
    Description() = default;

    virtual std::string getDescription() {
        return nullptr;
    }
};


#endif //SIMPLE_EXAMPLE_DESCRIPTION_H
