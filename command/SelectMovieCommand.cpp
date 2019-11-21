//
// Created by piotr on 21.11.2019.
//

#include "SelectMovieCommand.h"

#include <utility>

void SelectMovieCommand::execute() {
    std::string arg[] = {title};
    std::vector<std::vector<std::string> *> *movieList = database->execute(QueryName::MOVIE_SELECT_BY_NAME, arg);

    std::string titleOfMovie, director, movieDescription;
    int productionYear;
    double price;
    double movieLength;
    int id;

    id = std::stoi(movieList->at(0)->at(0));
    titleOfMovie = movieList->at(0)->at(1);
    director = movieList->at(0)->at(2);
    productionYear = std::stoi(movieList->at(0)->at(3));
    price = std::stoi(movieList->at(0)->at(4));
    movieLength = std::stof(movieList->at(0)->at(5));
    movieDescription = movieList->at(0)->at(6);

    movie = new Movie(id, titleOfMovie, director, productionYear, price, movieLength, movieDescription);
}

SelectMovieCommand::SelectMovieCommand(Database *database, std::string title) : database(database),
                                                                                       title(std::move(title)) {
    movie = nullptr;
}

Movie *SelectMovieCommand::getMovie() const {
    return movie;
}
