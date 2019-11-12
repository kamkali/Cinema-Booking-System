//
// Created by Kamil Kaliś on 12/11/2019.
//

#ifndef SIMPLE_EXAMPLE_SEANCE_H
#define SIMPLE_EXAMPLE_SEANCE_H


#include "../movie/Movie.h"
#include "../room/CinemaRoom.h"

class Seance {
private:
    Movie showingMovie;
    CinemaRoom showingRoom;
    time_t showingStart{};

public:
    Seance(Movie showMovie, CinemaRoom showingRoom, time_t showingStart);

    const Movie &getShowingMovie() const;

    void setShowingMovie(const Movie &showingMovie);

    const CinemaRoom &getShowingRoom() const;

    void setShowingRoom(const CinemaRoom &showingRoom);

    time_t getShowingStart() const;

    void setShowingStart(time_t showingStart);

    void playCommercial();
};


#endif //SIMPLE_EXAMPLE_SEANCE_H
