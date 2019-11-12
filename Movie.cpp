#include <utility>

#include <utility>

//
// Created by Kamil Kaliś on 12/11/2019.
//

#include <iostream>
#include "Movie.h"
#include "Room.h"

Movie::Movie(std::string title, std::string director, int productionYear, int price, double movieLength,
             time_t sessionStart, MovieDescription description) : title(std::move(title)),
                                                                                           director(std::move(director)),
                                                                                           production_year(
                                                                                                   productionYear),
                                                                                           price(price),
                                                                                           movie_length(movieLength),
                                                                                           session_start(sessionStart),
                                                                                           description(std::move(description)) {

}

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

time_t Movie::getSessionStart() const {
    return session_start;
}

void Movie::setSessionStart(time_t sessionStart) {
    session_start = sessionStart;
}

const MovieDescription &Movie::getDescription() const {
    return description;
}

void Movie::setDescription(const MovieDescription &description) {
    Movie::description = description;
}

void Movie::printMovieInfo() {
    std::cout << "Tytul: " << Movie::title << ", Rezyser: " << Movie::director << ", Rok produkcji: "
              << Movie::production_year;
    std::cout << ", Cena: " << Movie::price << ", Dlugosc filmu: " << Movie::movie_length << ", Start o godz: "
              << Movie::session_start;
    std::cout << ", Opis: " << Movie::description.getDescription()
              << std::endl;

}

