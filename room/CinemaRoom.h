//
// Created by Piotr on 12.11.2019.
//

#ifndef SIMPLE_EXAMPLE_CINEMAROOM_H
#define SIMPLE_EXAMPLE_CINEMAROOM_H

#include <vector>
#include "Room.h"
#include "RoomDescription.h"

class CinemaRoom: public Room{
private:
    int id;
    std::string name;
    std::vector<Seat *> seats;
    RoomDescription * description;

public:
    CinemaRoom();
    CinemaRoom(int id, std::string name, std::vector<Seat *> & seats, const RoomDescription * description);

    std::vector<Seat *> & getSeats() override;

    RoomDescription getDescription() override;

    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    void setName(const std::string &name);
};


#endif //SIMPLE_EXAMPLE_CINEMAROOM_H
