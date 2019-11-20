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

public:
    CreateMovieCommand(Database *db, const std::string &title, const std::string &director, int productionYear,
                       double price, double movieLength, const std::string &movieDescription, const std::string &role);

    void execute() override;

};


#endif //SIMPLE_EXAMPLE_CREATEMOVIECOMMAND_H
