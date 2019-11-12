//
// Created by Kamil Kaliś on 12/11/2019.
//

#ifndef SIMPLE_EXAMPLE_SEANCE_H
#define SIMPLE_EXAMPLE_SEANCE_H


#include "Movie.h"
#include "CinemaRoom.h"

class Seance {
private:
    Movie showingMovie;
    CinemaRoom showingRoom;
    time_t showingStart{};

public:
    Seance(const Movie &showingMovie, const CinemaRoom &showingRoom, time_t showingStart);

    const Movie &getShowingMovie() const;

    void setShowingMovie(const Movie &showingMovie);

    const CinemaRoom &getShowingRoom() const;

    void setShowingRoom(const CinemaRoom &showingRoom);

    time_t getShowingStart() const;

    void setShowingStart(time_t showingStart);

    void playCommercial();

    virtual ~Seance();
};


#endif //SIMPLE_EXAMPLE_SEANCE_H
