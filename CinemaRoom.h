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
    Movie movie;
    std::vector<Seat> seats;
    RoomDescription description;

public:

    CinemaRoom(Movie movie, std::vector<Seat> seats, RoomDescription description);

    Movie getMovie() override;

    void setMovie(Movie movie) override;

    std::vector<Seat> & getSeats() override;

    Description getDescription() override;
};


#endif //SIMPLE_EXAMPLE_CINEMAROOM_H
