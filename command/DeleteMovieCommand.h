//
// Created by Kamil Kaliś on 17/11/2019.
//

#ifndef SIMPLE_EXAMPLE_DELETEMOVIECOMMAND_H
#define SIMPLE_EXAMPLE_DELETEMOVIECOMMAND_H


#include "../db/Database.h"
#include "Command.h"
#include <string>


class DeleteMovieCommand: public Command {
private:
    Database *DB;
    std::string movieTitle;
    std::string role;

public:
    DeleteMovieCommand(Database *db, const std::string &movieTitle, const std::string &role);

    void execute() override;
};


#endif //SIMPLE_EXAMPLE_DELETEMOVIECOMMAND_H
