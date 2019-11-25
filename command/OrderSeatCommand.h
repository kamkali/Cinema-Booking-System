//
// Created by piotr on 20.11.2019.
//

#ifndef SIMPLE_EXAMPLE_ORDERSEATCOMMAND_H
#define SIMPLE_EXAMPLE_ORDERSEATCOMMAND_H


#include "Command.h"
#include "../db/Database.h"
#include "../seance/Seance.h"

class OrderSeatCommand: public Command {
private:
    Database * database;
    Seance * seance;
    int numberOfSeat;
    int userId;
public:
    OrderSeatCommand(Database *database, Seance *seance, int numberOfSeat, int userId);

    void execute() override;
};


#endif //SIMPLE_EXAMPLE_ORDERSEATCOMMAND_H
