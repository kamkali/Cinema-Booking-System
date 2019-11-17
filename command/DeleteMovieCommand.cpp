//
// Created by Kamil Kaliś on 17/11/2019.
//

#include <iostream>
#include "DeleteMovieCommand.h"


DeleteMovieCommand::DeleteMovieCommand(Database *db, const std::string &movieTitle) : DB(db), movieTitle(movieTitle) {}


void DeleteMovieCommand::execute() {
    std::string args[] = {movieTitle};

    std::vector<std::vector<std::string> *> *checkMovie = DB->execute(MOVIE_SELECT_BY_NAME, args);

    if ((*checkMovie).empty()){
        std::cout << "There is no movie of title " << movieTitle << std::endl;
    }else{
        std::string movieIdToDelete[] = {checkMovie->at(0)->at(0)};
        std::string movieDescriptionIdToDelete[] = {checkMovie->at(0)->at(6)};
        DB->execute(MOVIE_DELETE_BY_ID, movieIdToDelete);
        DB->execute(DESCRIPTION_MOVIE_DELETE_BY_ID,movieDescriptionIdToDelete);
    }
    Database::deleteResult(checkMovie);
}

