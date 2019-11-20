//
// Created by Kamil Kaliś on 17/11/2019.
//

#include <iostream>
#include "DeleteMovieCommand.h"



void DeleteMovieCommand::execute() {
    if (role == "ROLE_ADMIN") {
        std::string args[] = {movieTitle};

        std::vector<std::vector<std::string> *> *checkMovie = DB->execute(MOVIE_SELECT_BY_NAME, args);

        if ((*checkMovie).empty()) {
            std::cout << "There is no movie of title " << movieTitle << std::endl;
        } else {
            std::string movieIdToDelete[] = {checkMovie->at(0)->at(0)};
            DB->execute(MOVIE_DELETE_BY_ID, movieIdToDelete);
        }

        Database::deleteResult(checkMovie);

    }else{
        std::cout << "User is not an admin and don't have permition to modify resource!" << std::endl;
    }
}

DeleteMovieCommand::DeleteMovieCommand(Database *db, const std::string &movieTitle, const std::string &role) : DB(db),
                                                                                                               movieTitle(
                                                                                                                       movieTitle),
                                                                                                               role(role) {}
