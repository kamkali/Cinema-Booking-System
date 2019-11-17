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
    std::vector<Seat *> seats;
    RoomDescription * description;

public:
    CinemaRoom();
    CinemaRoom( std::vector<Seat *> & seats, const RoomDescription * description);

    std::vector<Seat *> & getSeats() override;

    RoomDescription getDescription() override;
};


#endif //SIMPLE_EXAMPLE_CINEMAROOM_H
