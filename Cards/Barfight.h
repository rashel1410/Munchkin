//
// Created by Rashel on 18/06/2022.
//
#include "Card.h"
#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

class Barfight : public Card
{
public:
    /**
     * C'tor - Barfight.
     */
    Barfight() : Card("Barfight"){}

    /**
     * D'tor - Barfight
     */
    ~Barfight() override = default;

    /**
     * Will apply the encounter of the card on a player given by reference.
     * @param player - A pointer to a player.
     */
    void applyEncounter(Player *player) const override;

private:
    static const int DEFAULT_HP_DECREASE = 10;
};

#endif //EX4_BARFIGHT_H
