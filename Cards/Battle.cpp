//
// Created by Rashel on 11/06/2022.
//
#include "Battle.h"
#include "../utilities.h"

Battle::Battle(std::string name, int force, int loot, int hpOnLoose) :
    Card(name),
    m_force(force),
    m_loot(loot),
    m_hpLossOnDefeat(hpOnLoose)
{}

void Battle::applyEncounter(Player* player) const
{
    if(player->getAttackStrength() >= getForce()) // Player won
    {
        player->levelUp();
        player->addCoins(getLoot());
        printWinBattle(player->getName(),this->getName());
    }
    else //Player lose
    {
        player->damage(getHpLossOnDefeat());
        printLossBattle(player->getName(), this->getName());
    }
}

/**
 * Getters of class Battle
 */
int Battle::getForce() const
{
    return m_force;
}

int Battle::getLoot() const
{
    return m_loot;
}

int Battle::getHpLossOnDefeat() const
{
    return m_hpLossOnDefeat;
}