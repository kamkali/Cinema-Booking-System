//
// Created by Piotr on 14.11.2019.
//

#ifndef SIMPLE_EXAMPLE_INITIALIZEDATABASEEXCEPTION_H
#define SIMPLE_EXAMPLE_INITIALIZEDATABASEEXCEPTION_H

#include <exception>

struct InitializeDatabaseException : public std::exception
{
    const char * what () const noexcept override
    {
        return "Initialized database error";
    }
};


#endif //SIMPLE_EXAMPLE_INITIALIZEDATABASEEXCEPTION_H
