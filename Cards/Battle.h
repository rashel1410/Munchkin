//
// Created by Rashel on 11/06/2022.
//

#include "Card.h"

#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H
class Battle : public Card
{
public:
    /**
     * C'tor of Battle class
     * @param force - The force of the card
     * @param loot - The amount of coins a player will win
     */
    explicit Battle(std::string name, int force, int loot, int hpOnLoose);

    /**
     * D'tor of class Battle
     */
    ~Battle() override = default;

    /**
     * Handling the player's encounter with the card:
     * Player wins if his attack force (level+force) is greater or equal to the dragon card's force = 25.
     * In that case the player's level increases by 1 and he gets the card's coins from this battle.
     * Otherwise, looses. In this case the player's health points are damaged by the card's health points damage value.
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player* player) const override;

    /**
     * Getters
     */
    int getForce() const;
    int getLoot() const;
    int getHpLossOnDefeat() const;

    static const int DEFAULT_HP_ON_LOSS = 10;

private:
    int m_force;  // The force of the monster
    int m_loot; // The profit you get when winning a battle
    int m_hpLossOnDefeat; // The amount of hp you lose when losing the battle

};
#endif //EX4_BATTLE_H
