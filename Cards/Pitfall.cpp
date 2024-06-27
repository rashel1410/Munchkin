//
// Created by yaniv on 17/06/2022.
//

#include "../Players/Player.h"
#include "../Players/Rogue.h"
#include "Pitfall.h"
#include "../utilities.h"

void Pitfall::applyEncounter(Player *player) const
{
    const Rogue* tempRogue = dynamic_cast<const Rogue*>(player);
    if(!tempRogue) //If the conversion failed, tempRogue is nullptr thus the if body will be performed.
                   //Else, the player is a rogue then we do nothing.
    {
        player->damage(DEFAULT_PITFALL_DAMAGE);
    }
    printPitfallMessage(tempRogue);
}
