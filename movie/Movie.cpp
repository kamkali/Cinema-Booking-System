#include <utility>

#include <utility>

#include <utility>

#include <utility>

#include <utility>

//
// Created by Kamil Kaliś on 12/11/2019.
//

#include <iostream>
#include "Movie.h"
#include "../room/Room.h"


const std::string &Movie::getTitle() const {
    return title;
}


void Movie::printMovieInfo() {
    std::cout << "Tytul:\t" << Movie::title << "\t\tRezyser:\t" << Movie::director << "\t\tRok produkcji:\t"
              << Movie::production_year << std::endl;
    std::cout << "Cena:\t" << Movie::price << "\t\tDlugosc filmu:\t" << Movie::movie_length << std::endl;
    std::cout << "Opis:\t" << Movie::description << std::endl;

}

Movie::Movie(int id, std::string title, std::string director, int productionYear, int price, double movieLength,
             std::string description) : id(id), title(std::move(title)), director(std::move(director)),
                                             production_year(productionYear),
                                             price(price), movie_length(movieLength),
                                             description(std::move(description)) {}

int Movie::getId() const {
    return id;
}

void Movie::setId(int id) {
    Movie::id = id;
}

