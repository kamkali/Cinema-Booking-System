//
// Created by piotr on 21.11.2019.
//

#ifndef SIMPLE_EXAMPLE_WORKFLOW_H
#define SIMPLE_EXAMPLE_WORKFLOW_H

#include <iostream>
#include <cassert>
#include "room/RoomFactory.h"
#include "command/Command.h"
#include "command/ListSeancesCommand.h"
#include "command/OrderSeat.h"

using namespace std;

void listSeances(Database *db, vector<Room *> occupiedRooms){
    Command * listSeances = new ListSeancesCommand(db, &occupiedRooms);
    listSeances->execute();
    auto castSeances = dynamic_cast<ListSeancesCommand *>(listSeances)->getSeanceVec();

    for (auto seance: *castSeances) {
        cout << "Seance id: " << seance->getId() << " Playing movie: " << seance->getShowingMovie()->getTitle() <<
             "in Room: " << dynamic_cast<CinemaRoom *>(seance->getShowingRoom())->getName() << endl;
    }
}

void listMovies(Database *db){
    Command * showMovies = new ListMoviesCommand(db);
    showMovies->execute();

    auto moviesList = dynamic_cast<ListMoviesCommand *>(showMovies)->getMoviesVec();
    for (auto movie: moviesList){
        movie.printMovieInfo();
    }
}

//void showAdminMenu(){
//    cout <<
//}

void showUserMenu(Database *db, vector<Room *> occupiedRooms, int seatsPerRow,int userId){
    int pick;
    bool menuDummy{true};
    while (menuDummy) {
        cout << "Welcome to the Kuglan'n'Kali Cinema! Please choose: \n(1) Show seances list \n(2) Show movies list "
                "\n(3) Exit\n" << endl;
        cout << "~: ";
        cin >> pick;
        assert(isnumber(pick));

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
                    assert(isnumber(pick));

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
                            assert(isnumber(seatNumberColumn));
                            cout << "~: ";
                            cin >> seatNumberRow;
                            assert(isnumber(seatNumberColumn));
                            Command * placeOrder = new OrderSeat(db, seance, (seatNumberRow*10+seatNumberColumn)-10, userId);
                            placeOrder->execute();
                            cout << "Order has been placed!" << endl;
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
