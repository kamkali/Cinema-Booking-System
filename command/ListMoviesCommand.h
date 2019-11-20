//
// Created by Kamil Kaliś on 17/11/2019.
//

#ifndef SIMPLE_EXAMPLE_LISTMOVIESCOMMAND_H
#define SIMPLE_EXAMPLE_LISTMOVIESCOMMAND_H


#include "../db/Database.h"
#include "../movie/Movie.h"
#include "Command.h"

class ListMoviesCommand: public Command {
private:
    Database *DB;
    std::vector<Movie> movies_vec;

public:
    ListMoviesCommand(Database *db);

    const std::vector<Movie> &getMoviesVec() const;

    void execute() override;

};


#endif //SIMPLE_EXAMPLE_LISTMOVIESCOMMAND_H
