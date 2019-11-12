//
// Created by Kamil Kaliś on 12/11/2019.
//

#ifndef SIMPLE_EXAMPLE_MOVIEDESCRIPTION_H
#define SIMPLE_EXAMPLE_MOVIEDESCRIPTION_H

#include "Description.h"

class MovieDescription : Description {
public:
    MovieDescription();

private:
    std::string getDescription() override;
};


#endif //SIMPLE_EXAMPLE_MOVIEDESCRIPTION_H
