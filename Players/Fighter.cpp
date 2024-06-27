//
// Created by Rashel on 08/06/2022.
//

#include "Fighter.h"
#include "../utilities.h"

int Fighter::getAttackStrength() const
{
    return MULTIPLY * getForce() + getLevel();
}

void Fighter::printPlayer(std::ostream& os) const
{
    printPlayerDetails(os, getName(),"Fighter" ,
                       getLevel(), getForce(), getHP(), getCoins());
}
