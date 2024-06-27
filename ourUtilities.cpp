//
// Created by yaniv on 19/06/2022.
//

#include "ourUtilities.h"

bool isALetter(char character)
{
    IsBetween capital('A','Z');
    IsBetween lower('a', 'z');
    return (capital(character) || lower(character));
}

bool isValidName(std::string name)
{
    IsBetween is15CharactersMax(0,MAX_NAME_LENGTH);
    if(!is15CharactersMax(name.length()))
    {
        return false;
    }
    for(const char& c : name)
    {
        if(!isALetter(c))
        {
            return false;
        }
    }
    return true;
}


