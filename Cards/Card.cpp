//
// Created by 97252 on 11/06/2022.
//

#include "Card.h"
#include "../Exception.h"
#include "../ourUtilities.h"
#include "../utilities.h"

using std::string;
using std::ostream;

/**
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
Card::Card(string name) :
        m_name(name)
{
    if(!isValidName(name))
    {
        throw InvalidName();
    }
}

ostream& operator<<(ostream& os, const Card& card)
{
    card.printInfo(os);
    return os;
}

std::string Card::getName() const {return m_name;}


void Card::printInfo(std::ostream &os) const
{
    printCardDetails(os, getName());
    printEndOfCardDetails(os);
}
