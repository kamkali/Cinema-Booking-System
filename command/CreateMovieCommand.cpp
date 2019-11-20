//
// Created by Kamil Kaliś on 17/11/2019.
//

#include <iostream>
#include "CreateMovieCommand.h"


void CreateMovieCommand::execute() {
    if (role == "ROLE_ADMIN") {
        std::string checkArg[] = {title};

        std::vector<std::vector<std::string> *> *checkMovie = DB->execute(MOVIE_SELECT_BY_NAME, checkArg);

        createdMovie = new Movie(std::stoi(checkMovie->at(0)->at(0)), checkMovie->at(0)->at(1),
                                 checkMovie->at(0)->at(2), std::stoi(checkMovie->at(0)->at(3)),
                                 std::stoi(checkMovie->at(0)->at(4)), std::stod(checkMovie->at(0)->at(5)),
                                 checkMovie->at(0)->at(6));

        if ((*checkMovie).empty()) {
            std::string args[] = {title, director, std::to_string(production_year),
                                  std::to_string(price), std::to_string(movie_length), movieDescription};

            std::vector<std::vector<std::string> *> *result = DB->execute(MOVIE_INSERT, args);

            std::vector<std::vector<std::string> *> *savedId = DB->execute(MOVIE_SELECT_ALL);

            createdMovie = new Movie(std::stoi(savedId->at(0)->at(0)), title, director, production_year, price,
                                     movie_length, movieDescription);

            Database::deleteResult(result);
            Database::deleteResult(savedId);
        } else {
            std::cout << "Movie record already exists in database!" << std::endl;
        }
    } else {
        std::cout << "User is not an admin" << std::endl;
    }


}

CreateMovieCommand::CreateMovieCommand(Database *db, const std::string &title, const std::string &director,
                                       int productionYear, double price, double movieLength,
                                       const std::string &movieDescription, const std::string &role) : DB(db),
                                                                                                       title(title),
                                                                                                       director(
                                                                                                               director),
                                                                                                       production_year(
                                                                                                               productionYear),
                                                                                                       price(price),
                                                                                                       movie_length(
                                                                                                               movieLength),
                                                                                                       movieDescription(
                                                                                                               movieDescription),
                                                                                                       role(role) {}

Movie *CreateMovieCommand::getCreatedMovie() const {
    return createdMovie;
}
