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
    Movie *showingMovie;
    Room *showingRoom;


public:
    Seance(int id, Movie *showMovie, Room *showingRoom);

    Movie *getShowingMovie() const;

    void setShowingMovie(Movie *showingMovie);

    Room *getShowingRoom() const;

    void setShowingRoom(Room *showingRoom);

    void playCommercial();

    int getId() const;

    void setId(int id);
};


#endif //SIMPLE_EXAMPLE_SEANCE_H
