//
// Created by Kamil Kaliś on 12/11/2019.
//

#ifndef SIMPLE_EXAMPLE_MOVIE_H
#define SIMPLE_EXAMPLE_MOVIE_H

#include <string>
#include <ctime>
#include "../room/Room.h"

class Movie {
private:
    int id;
    std::string title;
    std::string director;
    int production_year;
    int price;
    double movie_length;
    std::string description;

public:
    Movie(int id, std::string title, std::string director, int productionYear, int price, double movieLength,
          std::string description);

    const std::string &getTitle() const;

    void printMovieInfo();

    int getId() const;

    void setId(int id);

};


#endif //SIMPLE_EXAMPLE_MOVIE_H
