//
// Created by Kamil Kaliś on 17/11/2019.
//

#ifndef SIMPLE_EXAMPLE_CREATEMOVIECOMMAND_H
#define SIMPLE_EXAMPLE_CREATEMOVIECOMMAND_H


#include "Command.h"
#include "../db/Database.h"
#include "../movie/Movie.h"
#include <string>

class CreateMovieCommand: public Command {
private:
    Database *DB;
    std::string title;
    std::string director;
    int production_year;
    double price;
    double movie_length;
    std::string movieDescription;
    std::string role;
    Movie *createdMovie;

public:
    CreateMovieCommand(Database *db, std::string title, std::string director, int productionYear,
                       double price, double movieLength, std::string movieDescription, std::string role);

    void execute() override;

    Movie *getCreatedMovie() const;
};


#endif //SIMPLE_EXAMPLE_CREATEMOVIECOMMAND_H
