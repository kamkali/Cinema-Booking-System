//
// Created by Kamil Kaliś on 17/11/2019.
//

#include <iostream>
#include <utility>
#include "CreateMovieCommand.h"


void CreateMovieCommand::execute() {
    if (role == "ROLE_ADMIN") {
        std::string checkArg[] = {title};

        std::vector<std::vector<std::string> *> *checkMovie = DB->execute(MOVIE_SELECT_BY_NAME, checkArg);



        if ((*checkMovie).empty()) {
            std::string args[] = {title, director, std::to_string(production_year),
                                  std::to_string(price), std::to_string(movie_length), movieDescription};

            std::vector<std::vector<std::string> *> *result = DB->execute(MOVIE_INSERT, args);

            std::vector<std::vector<std::string> *> *savedId = DB->execute(MOVIE_SELECT_ALL);

            Database::deleteResult(result);
            Database::deleteResult(savedId);
        }
    } else {
        std::cout << "User is not an admin" << std::endl;
    }


}

CreateMovieCommand::CreateMovieCommand(Database *db, std::string title, std::string director,
                                       int productionYear, double price, double movieLength,
                                       std::string movieDescription, std::string role) : DB(db),
                                                                                                       title(std::move(title)),
                                                                                                       director(std::move(
                                                                                                               director)),
                                                                                                       production_year(
                                                                                                               productionYear),
                                                                                                       price(price),
                                                                                                       movie_length(
                                                                                                               movieLength),
                                                                                                       movieDescription(std::move(
                                                                                                               movieDescription)),
                                                                                                       role(std::move(role)) {}

