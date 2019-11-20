//
// Created by Kamil Kaliś on 17/11/2019.
//

#include <iostream>
#include "ListMoviesCommand.h"

ListMoviesCommand::ListMoviesCommand(Database *db) : DB(db) {}

void ListMoviesCommand::execute() {
    std::vector<std::vector<std::string> *> *allMovies = DB->execute(MOVIE_SELECT_ALL);

    for (auto singleMovie: *allMovies) {
        std::string descriptionId[] = {singleMovie->at(6)};
        std::vector<std::vector<std::string> *> *movieDescription = DB->execute(DESCRIPTION_MOVIE_SELECT_BY_ID,
                                                                                descriptionId);

        auto description = new MovieDescription(movieDescription->at(0)->at(1));
        auto *movie = new Movie(singleMovie->at(1), singleMovie->at(2),
                                std::stoi(singleMovie->at(3)), std::stoi(singleMovie->at(4)),
                                std::stod(singleMovie->at(5)), *description);
        movies_vec.push_back(*movie);
    }
}

const std::vector<Movie> &ListMoviesCommand::getMoviesVec() const {
    return movies_vec;
}
