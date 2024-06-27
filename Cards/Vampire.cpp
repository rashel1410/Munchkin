//
// Created by yaniv on 13/06/2022.
//

#include "Vampire.h"
#include "../utilities.h"

Vampire::Vampire() : Battle("Vampire", VAMPIRE_FORCE, VAMPIRE_LOOT, DEFAULT_HP_ON_LOSS){}

void Vampire::applyEncounter(Player *player) const
{
    bool VampireWonBattle = player->getAttackStrength() < VAMPIRE_FORCE;
    Battle::applyEncounter(player);
    if (VampireWonBattle)
    {
        player->nerf(1);
    }
}

void Vampire::printInfo(std::ostream &os) const
{
    printCardDetails(os,getName());
    printMonsterDetails(os,getForce(),getHpLossOnDefeat(), getLoot(), false);
    printEndOfCardDetails(os);
}
