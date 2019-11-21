//
// Created by piotr on 21.11.2019.
//

#ifndef SIMPLE_EXAMPLE_WORKFLOW_H
#define SIMPLE_EXAMPLE_WORKFLOW_H
#define ADMIN "ROLE_ADMIN"
#include <iostream>
#include <cassert>
#include "room/RoomFactory.h"
#include "command/Command.h"
#include "command/ListSeancesCommand.h"
#include "command/OrderSeat.h"
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
void listSeances(Database *db, vector<Room *> occupiedRooms){
    Command * listSeances = new ListSeancesCommand(db, &occupiedRooms);
    listSeances->execute();
    auto castSeances = dynamic_cast<ListSeancesCommand *>(listSeances)->getSeanceVec();

    for (auto seance: *castSeances) {
        cout << "Seance id: " << seance->getId() << " Playing movie: " << seance->getShowingMovie()->getTitle() <<
             "in Room: " << dynamic_cast<CinemaRoom *>(seance->getShowingRoom())->getName() << endl;
    }
}

//void showAdminMenu(){
//    cout <<
//}

void showUserMenu(Database *db, RoomFactory* roomPool, vector<Room *> occupiedRooms, int seatsPerRow,int userId){
    //order Seats at Seance
    int pick;
    bool menuDummy{true};
    while (menuDummy) {
        cout << "Welcome to the Kuglan'n'Kali Cinema! Please choose: \n(1) Show seances list \n(2) Show movies list "
                "\n(3) Exit\n" << endl;
        cout << "~: ";
        cin >> pick;

        if (pick == 1) {
            Command * listSeances = new ListSeancesCommand(db, &occupiedRooms);
            listSeances->execute();
            auto castSeances = dynamic_cast<ListSeancesCommand *>(listSeances)->getSeanceVec();

            for (auto seance: *castSeances){
                cout << "Seance id: "  << seance->getId() << " Playing movie: " << seance->getShowingMovie()->getTitle() <<
                "in Room: " << dynamic_cast<CinemaRoom *>(seance->getShowingRoom())->getName() << endl;

                bool seanceDummy{true};
                while (seanceDummy)
                {
                    cout << "Options: \n(1) Print movie info\n(2) Print seats\n(3) Place order\n(4) continue\n(5) exit\n" << endl;
                    cout << "~: ";

                    cin >> pick;

                    switch(pick)
                    {
                        case 1:
                        {
                            seance->getShowingMovie()->printMovieInfo();
                        }
                            break;
                        case 2:
                        {
                            seance->printSeats(db, seatsPerRow);
                        }
                            break;
                        case 3:
                        {
                            int seatNumberRow, seatNumberColumn;
                            seance->printSeats(db, seatsPerRow);

                            cout << "Please pick a free seat(Column, then Row): \n" << endl;
                            cout << "~: ";
                            cin >> seatNumberColumn;
                            cout << "~: ";
                            cin >> seatNumberRow;
                            Command * placeOrder = new OrderSeat(db, seance, (seatNumberRow*10+seatNumberColumn)-10, userId);
                            placeOrder->execute();
                        }
                            break;
                        case 5:
                            menuDummy = false;
                        case 4:
                            seanceDummy = false;
                            break;
                    }
                }

            }

        } else if (pick == 2) {
            Command * showMovies = new ListMoviesCommand(db);
            showMovies->execute();

            auto moviesList = dynamic_cast<ListMoviesCommand *>(showMovies)->getMoviesVec();
            for (auto movie: moviesList){
                movie.printMovieInfo();
            }
        } else if (pick == 3) {
            menuDummy = false;
        }
    }
}



#endif //SIMPLE_EXAMPLE_WORKFLOW_H
