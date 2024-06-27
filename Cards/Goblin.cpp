//
// Created by Rashel on 11/06/2022.
//

#include "Goblin.h"
#include "../utilities.h"
using std::ostream;

Goblin::Goblin() : Battle("Goblin", GOBLIN_FORCE, GOBLIN_LOOT, DEFAULT_HP_ON_LOSS){}


void Goblin::printInfo(ostream& os) const
{
    printCardDetails(os,getName());
    printMonsterDetails(os,getForce(),getHpLossOnDefeat(), getLoot(), false);
    printEndOfCardDetails(os);
}