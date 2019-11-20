//
// Created by Piotr on 12.11.2019.
//

#ifndef SIMPLE_EXAMPLE_CINEMAROOM_H
#define SIMPLE_EXAMPLE_CINEMAROOM_H

#include <vector>
#include "Room.h"

class CinemaRoom: public Room{
private:
    int id;
    std::string name;
    std::vector<Seat *> seats;
    size_t number{};
    size_t floor{};

public:
    CinemaRoom();
    CinemaRoom(int id, std::string name, std::vector<Seat *> & seats, size_t number, size_t floor);

    std::vector<Seat *> & getSeats() override;

    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    void setName(const std::string &name);

    void setSeats(const std::vector<Seat *> &seats);

    size_t getNumber() const;

    void setNumber(size_t number);

    size_t getFloor() const;

    void setFloor(size_t floor);
};


#endif //SIMPLE_EXAMPLE_CINEMAROOM_H
