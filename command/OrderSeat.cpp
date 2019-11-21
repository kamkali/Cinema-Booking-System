//
// Created by piotr on 20.11.2019.
//

#include "OrderSeat.h"

void OrderSeat::execute() {
    int roomId = dynamic_cast<CinemaRoom *>(seance->getShowingRoom())->getId();

    std::string args[]{std::to_string(roomId), std::to_string(numberOfSeat)};

    std::vector<std::vector<std::string> *> *result = database->execute(QueryName::SEAT_SELECT_BY_ROOM_ID_AND_NUMBER_IN_ROOM, args);

    if(stoi(result->at(0)->at(2)) == 0){

        std::string argsUpdate[] = {std::to_string(userId), result->at(0)->at(0)};

        Database::deleteResult(database->execute(QueryName::SEAT_UPDATE_BY_ID, argsUpdate));

    } else{
        std::cout << "Seat is occupied" << std::endl;
    }

    Database::deleteResult(result);
}

OrderSeat::OrderSeat(Database *database, Seance *seance, int numberOfSeat, int userId) : database(database),
                                                                                         seance(seance),
                                                                                         numberOfSeat(numberOfSeat),
                                                                                         userId(userId) {}
