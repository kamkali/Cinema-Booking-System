//
// Created by Kamil Kaliś on 20/11/2019.
//

#include "ListSeansesCommand.h"

ListSeansesCommand::ListSeansesCommand(Database *db, const std::vector<Seance> &seanceVec) : DB(db),
                                                                                             seance_vec(seanceVec) {}

const std::vector<Seance> &ListSeansesCommand::getSeanceVec() const {
    return seance_vec;
}

void ListSeansesCommand::execute() {
    seance_vec.clear();
    std::vector<std::vector<std::string> *> *allSeances = DB->execute(SEANS_SELECT_ALL);

}
