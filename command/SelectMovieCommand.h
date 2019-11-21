//
// Created by piotr on 21.11.2019.
//

#ifndef SIMPLE_EXAMPLE_SELECTMOVIECOMMAND_H
#define SIMPLE_EXAMPLE_SELECTMOVIECOMMAND_H

#include "../command/Command.h"
#include "../db/Database.h"
#include "../movie/Movie.h"

class SelectMovieCommand: public Command {
private:
    Database * database;
    std::string title;
    Movie * movie;
public:
    SelectMovieCommand(Database *database, std::string title);
    void execute() override;

    Movie *getMovie() const;
};


#endif //SIMPLE_EXAMPLE_SELECTMOVIECOMMAND_H
