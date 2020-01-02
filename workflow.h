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
#include "command/OrderSeatCommand.h"
#include "command/SelectMovieCommand.h"

using namespace std;

void listSeances(Database *db, vector<Room *> occupiedRooms){
    Command * listSeances = new ListSeancesCommand(db, &occupiedRooms);
    listSeances->execute();
    auto castSeances = dynamic_cast<ListSeancesCommand *>(listSeances)->getSeanceVec();

    string movieTitle;

    for (auto seance: *castSeances) {
        if(seance->getShowingMovie() == nullptr)
            movieTitle = "NULL";
        else
            movieTitle = seance->getShowingMovie()->getTitle();

        cout << "Seance id:\t" << seance->getId() << "\t\tPlaying movie:\t" << movieTitle <<
             "\t\tRoom:\t" << dynamic_cast<CinemaRoom *>(seance->getShowingRoom())->getName() << endl;
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


void showAdminMenu(Database * database, RoomFactory * roomPool, vector<Room*> * occupiedRooms) {

    int order{};
    string orderString;

    do {

        cout << "ADMIN MENU" << endl;
        cout << endl;
        cout << "(1) Create movie" << endl;
        cout << "(2) Delete movie" << endl;
        cout << "(3) List movies" << endl;
        cout << "(4) Create seance" << endl;
        cout << "(5) Delete seance" << endl;
        cout << "(6) List seances" << endl;
        cout << "(0) End program" << endl;

        cout << "~: ";

        try {
            cin >> orderString;
            order = stoi(orderString);
        }catch (invalid_argument & exc){
            cerr << "invalid argument: pick proper argument" << endl;
            continue;
        }

        Command *command;
        Movie *movie;
        Room *room;

        string title, director, movieDescription, seanceName, productionYear_s, price_s, movieLength_s;
        int productionYear;
        double price;
        double movieLength;


        switch (order) {
            case 1:
                cout << "Create movie" << endl;
                cout << endl;
                cout << "Title: ";
                cin >> title;
                cout << "Director: ";
                cin >> director;
                cout << "Description: ";
                cin >> movieDescription;

                try {
                    cout << "Production year: ";
                    cin >> productionYear_s;
                    productionYear = stoi(productionYear_s);
                }catch (invalid_argument & exc){
                    cerr << "invalid argument: pick proper argument" << endl;
                    continue;
                }
                try {
                    cout << "Length: ";
                    cin >> movieLength_s;
                    movieLength = stod(movieLength_s);
                }catch (invalid_argument & exc){
                    cerr << "invalid argument: pick proper argument" << endl;
                    continue;
                }
                try {
                    cout << "Price: ";
                    cin >> price_s;
                    price = stod(price_s);
                }catch (invalid_argument & exc){
                    cerr << "invalid argument: pick proper argument" << endl;
                    continue;
                }

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
            case 4:
                cout << "Create seance" << endl;
                cout << endl;
                cout << "Movie title: ";
                cin >> title;

                command = new SelectMovieCommand(database, title);
                command->execute();
                movie = dynamic_cast<SelectMovieCommand *>(command)->getMovie();

                if(movie == nullptr){
                    cout << "There is no movie of this title" << endl;
                    break;
                }

                cout << "Seance name: ";
                cin >> seanceName;

                room = roomPool->getInstance();
                occupiedRooms->push_back(room);

                command = new CreateSeanceCommand(database, seanceName, room, movie);
                command->execute();

                cout << "Seance has been created!" << endl;

                break;
            case 5:
                cout << "Delete seance" << endl;
                cout << endl;
                cout << "Seance name: ";
                cin >> seanceName;

                command = new DeleteSeanceCommand(database, seanceName, roomPool, occupiedRooms, ADMIN);
                command->execute();
                break;
            case 6:
                listSeances(database, *occupiedRooms);
                break;
            case 0:
                break;
            case 3:
                listMovies(database);
                break;
            default:
                cout << "Choose proper option!" << endl;
                break;
        }

    } while (order != 0);
}

void showUserMenu(Database *db, vector<Room *> occupiedRooms, int seatsPerRow,int userId){
    int pick{};
    string orderString;
    bool menuDummy{true};
    while (menuDummy) {
        cout << "Welcome to the Kuglan'n'Kali Cinema! Please choose: \n(1) Show seances list \n(2) Show movies list "
                "\n(3) Exit\n" << endl;
        cout << "~: ";

        try {
            cin >> orderString;
            pick = stoi(orderString);
        }catch (invalid_argument & exc){
            cerr << "invalid argument: pick proper argument" << endl;
            continue;
        }

        if (pick == 1) {
            Command * listSeances = new ListSeancesCommand(db, &occupiedRooms);
            listSeances->execute();
            auto castSeances = dynamic_cast<ListSeancesCommand *>(listSeances)->getSeanceVec();

            for (auto seance: *castSeances){
                cout << "Seance id:\t"  << seance->getId() << "\t\tPlaying movie:\t" << seance->getShowingMovie()->getTitle() <<
                "\t\tRoom:\t" << dynamic_cast<CinemaRoom *>(seance->getShowingRoom())->getName() << endl;

                bool seanceDummy{true};
                while (seanceDummy)
                {
                    cout << "Options: \n(1) Print movie info\n(2) Print seats\n(3) Place order\n(4) continue\n(5) exit\n" << endl;
                    cout << "~: ";

                    try {
                        cin >> orderString;
                        pick = stoi(orderString);
                    }catch (invalid_argument & exc){
                        cerr << "invalid argument: pick proper argument" << endl;
                        break;
                    }

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

                            Command * placeOrder = new OrderSeatCommand(db, seance, (seatNumberRow * 10 + seatNumberColumn) - 10, userId);
                            placeOrder->execute();
                            cout << "Order has been placed!" << endl;
                        }
                            break;
                        case 5:
                            menuDummy = false;
                        case 4:
                            seanceDummy = false;
                            break;
                        default:
                            cout << "Choose proper option!" << endl;
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
        } else{
            cout << "Choose proper option!" << endl;
        }
    }
}



#endif //SIMPLE_EXAMPLE_WORKFLOW_H
