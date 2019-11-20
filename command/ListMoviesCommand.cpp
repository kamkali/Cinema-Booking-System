//
// Created by Kamil Kaliś on 17/11/2019.
//

#include <iostream>
#include "ListMoviesCommand.h"

ListMoviesCommand::ListMoviesCommand(Database *db) : DB(db) {}

void ListMoviesCommand::execute() {
    movies_vec.clear();
    std::vector<std::vector<std::string> *> *allMovies = DB->execute(MOVIE_SELECT_ALL);

    for (auto singleMovie: *allMovies) {

        auto *movie = new Movie(std::stoi(singleMovie->at(0)), singleMovie->at(1), singleMovie->at(2),
                                std::stoi(singleMovie->at(3)), std::stoi(singleMovie->at(4)),
                                std::stod(singleMovie->at(5)),singleMovie->at(6));
        movies_vec.push_back(*movie);

    }
    Database::deleteResult(allMovies);
}

const std::vector<Movie> &ListMoviesCommand::getMoviesVec() const {
    return movies_vec;
}
