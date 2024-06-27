//
// Created by yaniv on 17/06/2022.
//

#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H
#include "Card.h"

class Fairy : public Card
{
public:
    /**
    * C'tor of Fairy class which is an instance of a battle Card.
    */
    Fairy() : Card("Fairy") {}

    /**
    * D'tor of Fairy class
    */
    ~Fairy() override = default;

    /**
    * Will apply the encounter of the card on a player given by reference.
    * @param player - A pointer to a player.
    */
    void applyEncounter(Player *player) const override;

private:
    static const int DEFAULT_HP_INCREASE = 10;
};

#endif //EX4_FAIRY_H
