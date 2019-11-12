//
// Created by Kamil Kaliś on 12/11/2019.
//

#ifndef SIMPLE_EXAMPLE_MOVIE_H
#define SIMPLE_EXAMPLE_MOVIE_H

#include <string>
#include <ctime>
#include "Room.h"
#include "MovieDescription.h"

class Movie {
private:
    std::string title;
    std::string director;
    int production_year;
    int price;
    double movie_length;
    time_t session_start;
    Room room;
    MovieDescription description;



public:


    Movie(const std::string &title, const std::string &director, int productionYear, int price, double movieLength,
          time_t sessionStart, const Room &room, const MovieDescription &description);

    virtual ~Movie();

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const std::string &getDirector() const;

    void setDirector(const std::string &director);

    int getProductionYear() const;

    void setProductionYear(int productionYear);

    int getPrice() const;

    void setPrice(int price);

    double getMovieLength() const;

    void setMovieLength(double movieLength);

    time_t getSessionStart() const;

    void setSessionStart(time_t sessionStart);

    const Room &getRoom() const;

    void setRoom(const Room &room);

    const MovieDescription &getDescription() const;

    void setDescription(const MovieDescription &description);
};


#endif //SIMPLE_EXAMPLE_MOVIE_H
