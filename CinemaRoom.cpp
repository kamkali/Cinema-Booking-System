//
// Created by Piotr on 12.11.2019.
//

#include "CinemaRoom.h"


Movie CinemaRoom::getMovie() {
    return movie;
}

std::vector<Seat> & CinemaRoom::getSeats() {
    return seats;
}


CinemaRoom::CinemaRoom(Movie movie, std::vector<Seat> seats, RoomDescription description): movie(movie), seats(seats), description(description) {

}

Description CinemaRoom::getDescription() {
    return description;
}

void CinemaRoom::setMovie(Movie movie) {
    this->movie = movie;
}
