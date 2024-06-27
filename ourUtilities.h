//
// Created by yaniv on 19/06/2022.
//

#ifndef EX4_OURUTILITIES_H
#define EX4_OURUTILITIES_H

#include <string>

class IsBetween
{
private:
    int m_lower;
    int m_upper;
public:
    IsBetween(int lower, int upper):
        m_lower(lower),
        m_upper(upper)
    {}
    bool operator()(int check) const
    {
        return (check >= m_lower && check <= m_upper);
    }
};


bool isALetter(char character);

/**
 * Validates the name of the card -
 * Maximum 15 chars long, no spaces, english letters only
 * @param name - The card name to validate
 * @return - true if valid, false if not
 */
bool isValidName(std::string name);

static const int MAX_NAME_LENGTH = 15;

#endif //EX4_OURUTILITIES_H
