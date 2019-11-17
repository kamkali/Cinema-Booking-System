//
// Created by Kamil Kaliś on 12/11/2019.
//

#ifndef SIMPLE_EXAMPLE_MOVIEDESCRIPTION_H
#define SIMPLE_EXAMPLE_MOVIEDESCRIPTION_H

#include "../seance/Description.h"

class MovieDescription : public Description {
private:
    std::string description;

public:
    MovieDescription();

    void setDescription(const std::string &description);

    MovieDescription(const std::string &description);

    std::string getDescription() override;
};


#endif //SIMPLE_EXAMPLE_MOVIEDESCRIPTION_H
