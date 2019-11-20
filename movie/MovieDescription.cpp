//
// Created by Kamil Kaliś on 12/11/2019.
//

#include "MovieDescription.h"

std::string MovieDescription::getDescription() {
    return description;
}

MovieDescription::MovieDescription(const std::string &description) : description(description) {}

void MovieDescription::setDescription(const std::string &description) {
    MovieDescription::description = description;
}

MovieDescription::MovieDescription() = default;
