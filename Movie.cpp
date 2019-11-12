//
// Created by Kamil Kaliś on 12/11/2019.
//

#include <iostream>
#include "Movie.h"

Movie::Movie(const std::string &title, const std::string &director, int productionYear, int price, double movieLength,
             time_t sessionStart, const Room &room, const MovieDescription &description) : title(title),
                                                                                           director(director),
                                                                                           production_year(
                                                                                                   productionYear),
                                                                                           price(price),
                                                                                           movie_length(movieLength),
                                                                                           session_start(sessionStart),
                                                                                           room(room),
                                                                                           description(description) {

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

const Room &Movie::getRoom() const {
    return room;
}

void Movie::setRoom(const Room &room) {
    Movie::room = room;
}

const MovieDescription &Movie::getDescription() const {
    return description;
}

void Movie::setDescription(const MovieDescription &description) {
    Movie::description = description;
}

Movie::~Movie() = default;


void Movie::printMovieInfo() {
    std::cout << "Tytul: " << Movie::title << ", Rezyser: " << Movie::director << ", Rok produkcji: "
              << Movie::production_year;
    std::cout << ", Cena: " << Movie::price << ", Dlugosc filmu: " << Movie::movie_length << ", Start o godz: "
              << Movie::session_start;
    std::cout << ", W pokoju: " << Movie::room.getRoomName() << ", Opis: " << Movie::description.getDescription()
              << std::endl;

}

