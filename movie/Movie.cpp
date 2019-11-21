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

void Movie::setTitle(const std::string &title) {
    Movie::title = title;
}

const std::string &Movie::getDirector() const {
    return director;
}

void Movie::setDirector(const std::string &director) {
    Movie::director = director;
}

int Movie::getProductionYear() const {
    return production_year;
}

void Movie::setProductionYear(int productionYear) {
    production_year = productionYear;
}

int Movie::getPrice() const {
    return price;
}

void Movie::setPrice(int price) {
    Movie::price = price;
}

double Movie::getMovieLength() const {
    return movie_length;
}

void Movie::setMovieLength(double movieLength) {
    movie_length = movieLength;
}


const std::string &Movie::getDescription() const {
    return description;
}

void Movie::setDescription(const std::string &description) {
    Movie::description = description;
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

