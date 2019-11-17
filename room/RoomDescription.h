//
// Created by Piotr on 12.11.2019.
//

#ifndef SIMPLE_EXAMPLE_ROOMDESCRIPTION_H
#define SIMPLE_EXAMPLE_ROOMDESCRIPTION_H

#include "../seance/Description.h"
#include <string>

class RoomDescription: public Description {
private:
    size_t number{};
    size_t floor{};
    std::string name;

public:
    RoomDescription() = default;
    RoomDescription(size_t number, size_t floor, std::string name);
    RoomDescription(const RoomDescription & roomDescription);
    std::string getDescription() override;

    size_t getNumber() const;

    size_t getFloor() const;

    const std::string &getName() const;
};


#endif //SIMPLE_EXAMPLE_ROOMDESCRIPTION_H
