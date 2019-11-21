//
// Created by piotr on 21.11.2019.
//

#ifndef SIMPLE_EXAMPLE_WORKFLOW_H
#define SIMPLE_EXAMPLE_WORKFLOW_H
#define ADMIN "ROLE_ADMIN"
#include <iostream>
#include "command/SelectMovieCommand.h"

using namespace std;

void showAdminMenu(Database * database, RoomFactory * roomPool, vector<Room*> * occupiedRooms){

    int order;

    do {

        cout << "ADMIN MENU" << endl;
        cout << endl;
        cout << "1. Create movie" << endl;
        cout << "2. Delete movie" << endl;
        cout << "3. Create seance" << endl;
        cout << "4. Delete seance" << endl;
        cout << "0. End program" << endl;

        cout << "~: ";

        cin >> order;

        Command *command;
        Movie *movie;
        Room *room;

        string title, director, movieDescription;
        int productionYear;
        double price;
        double movieLength;
        string seanceName;

        switch (order) {
            case 1:
                cout << "Create movie" << endl;
                cout << endl;
                cout << "Title: ";
                cin >> title;
                cout << "Director: ";
                cin >> director;
                cout << "Production year: ";
                cin >> productionYear;
                cout << "Length: ";
                cin >> movieLength;
                cout << "Description: ";
                cin >> movieDescription;
                cout << "Price: ";
                cin >> price;

                command = new CreateMovieCommand(database, title, director, productionYear, price, movieLength,
                                                 movieDescription, ADMIN);
                command->execute();

                cout << "Movie has been created!" << endl;
                break;
            case 2:
                cout << "Delete movie" << endl;
                cout << endl;
                cout << "Title: ";
                cin >> title;

                command = new DeleteMovieCommand(database, title, ADMIN);
                command->execute();

                cout << "Movie has been deleted!" << endl;
                break;
            case 3:
                cout << "Create seance" << endl;
                cout << endl;
                cout << "Movie title: ";
                cin >> title;

                command = new SelectMovieCommand(database, title);
                command->execute();
                movie = dynamic_cast<SelectMovieCommand *>(command)->getMovie();

                cout << "Seance name: ";
                cin >> seanceName;

                room = roomPool->getInstance();
                occupiedRooms->push_back(room);

                command = new CreateSeance(database, seanceName, room, movie);
                command->execute();

                cout << "Seance has been created!" << endl;

                break;
            case 4:
                cout << "Delete seance" << endl;
                cout << endl;
                cout << "Seance name: ";
                cin >> seanceName;

                command = new DeleteSeance(database, seanceName, roomPool, occupiedRooms, ADMIN);
                command->execute();
                break;
            case 0:
                break;
            default:
                cout << "Choose proper option!" << endl;
                break;
        }

    }while(order != 0);
}



#endif //SIMPLE_EXAMPLE_WORKFLOW_H
