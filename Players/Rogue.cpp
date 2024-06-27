//
// Created by yaniv on 07/06/2022.
//

#include "Rogue.h"
#include "../utilities.h"

/**
 * An add coins method for the rogue player type, a rogue will gain twice the given amount.
 * @param coinsToAdd - The number of coins to add before multiplication.
 */
void Rogue::addCoins(int coinsToAdd)
{
    this->Player::addCoins(MULTIPLY * coinsToAdd);
}

void Rogue::printPlayer(std::ostream& os) const
{
    printPlayerDetails(os, getName(),"Rogue" ,
                       getLevel(), getForce(), getHP(), getCoins());
}
