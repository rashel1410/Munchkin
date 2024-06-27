//
// Created by Rashel on 14/06/2022.
//

#include "Treasure.h"
#include "../utilities.h"

Treasure::Treasure() : Card("Treasure") {}

void Treasure::applyEncounter(Player *player) const
{
    player->addCoins(COINS_TO_ADD);
    printTreasureMessage();
}
