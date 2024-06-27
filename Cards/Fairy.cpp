//
// Created by yaniv on 17/06/2022.
//
//
#include "Fairy.h"
#include "../utilities.h"
#include "../Players/Wizard.h"


void Fairy::applyEncounter(Player *player) const
{
    const Wizard* tempWizard = dynamic_cast<Wizard*>(player);
    if(tempWizard)
    {
        player->heal(DEFAULT_HP_INCREASE);
    }
    printFairyMessage(tempWizard);
}



