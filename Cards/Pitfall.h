//
// Created by yaniv on 17/06/2022.
//

#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H
#include "Card.h"

class Pitfall : public Card
{
public:
    /**
     * C'tor - Pitfall.
     */
    Pitfall() : Card("Pitfall") {}

    /**
     * D'tor - Pitfall.
     */
    ~Pitfall() override = default;

    /**
    * Will apply the encounter of the card on a player given by reference.
     * if the player is a rogue, no HP will be lost, else - would lose 10 HP.
    * @param player - A pointer to a player.
    */
    void applyEncounter(Player* player) const override;

private:
    static const int DEFAULT_PITFALL_DAMAGE = 10;
};
#endif //EX4_PITFALL_H
