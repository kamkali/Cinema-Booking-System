//
// Created by Kamil Kaliś on 12/11/2019.
//

#ifndef SIMPLE_EXAMPLE_SEANCE_H
#define SIMPLE_EXAMPLE_SEANCE_H


#include "../movie/Movie.h"
#include "../room/CinemaRoom.h"

class Seance {
private:
    int id;
    Movie * showingMovie;
    Room * showingRoom;
    time_t showingStart{};

public:
    Seance(int id, Movie * showMovie, Room * showingRoom, time_t showingStart);

    Movie *getShowingMovie() const;

    void setShowingMovie(Movie *showingMovie);

    Room *getShowingRoom() const;

    void setShowingRoom(Room *showingRoom);

    time_t getShowingStart() const;

    void setShowingStart(time_t showingStart);

    void playCommercial();

    int getId() const;

    void setId(int id);
};


#endif //SIMPLE_EXAMPLE_SEANCE_H
