//
// Created by Kamil Kaliś on 17/11/2019.
//

#include <iostream>
#include "ListMoviesCommand.h"

ListMoviesCommand::ListMoviesCommand(Database *db) : DB(db) {}

void ListMoviesCommand::execute() {
    int i{0};
//TODO not working:
    std::vector<std::vector<std::string> *> *oneMovie = DB->execute(MOVIE_SELECT_BY_ID);
        if((*oneMovie).empty()){
            std::cout << "No movies in database" << std::endl;
        }else{
            std::vector<std::vector<std::string> *> *oneMovieDesc = DB->execute(DESCRIPTION_MOVIE_SELECT);

            while(i < oneMovie->size()){
                MovieDescription movieDesc;
                movieDesc.setDescription(oneMovieDesc->at(stoi(oneMovie->at(i)->at(6)))->at(1));

                auto *singleMovie = new Movie(oneMovie->at(i)->at(1),
                                              oneMovie->at(i)->at(2),
                                              stoi(oneMovie->at(i)->at(3)),
                                              stoi(oneMovie->at(i)->at(4)),
                                              stod(oneMovie->at(i)->at(5)),
                                              movieDesc);

                movies_vec.push_back(*singleMovie);
                i++;
            }
        }
}

const std::vector<Movie> &ListMoviesCommand::getMoviesVec() const {
    return movies_vec;
}
