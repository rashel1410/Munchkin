//
// Created by Rashel on 12/06/2022.
//

#include "Dragon.h"
#include "../utilities.h"

Dragon::Dragon() : Battle("Dragon", DEFAULT_FORCE, DEFAULT_LOOT, Player::DEFAULT_MAX_HP){}


void Dragon::printInfo(std::ostream& os) const
{
    printCardDetails(os,getName());
    printMonsterDetails(os,getForce(),getHpLossOnDefeat(), getLoot(), true);
    printEndOfCardDetails(os);
}
