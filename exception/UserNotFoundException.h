//
// Created by piotr on 25.11.2019.
//

#ifndef SIMPLE_EXAMPLE_USERNOTFOUNDEXCEPTION_H
#define SIMPLE_EXAMPLE_USERNOTFOUNDEXCEPTION_H

#include <exception>

struct UserNotFoundException: public std::exception{
public:
    const char* what() const _NOEXCEPT{
        return "User has not been found!";
    }
};
#endif //SIMPLE_EXAMPLE_USERNOTFOUNDEXCEPTION_H
