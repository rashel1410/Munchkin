//
// Created by yaniv on 13/06/2022.
//

#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H
#include "Battle.h"

class Vampire : public Battle
{
public:
    /**
     * C'tor
     */
    Vampire();

    /**
     * D'tor.
     */
    ~Vampire() override = default;

    /**
     * Will apply the encounter of the card on a player given by reference.
     * If a player loses to the vampire, he will lose 1 force point.
     * @param player
     */
    void applyEncounter(Player *player) const override;

    /**
     * Prints the card's details to a stream given.
     * @param os
     */
    void printInfo(std::ostream& os) const override;

    static const int VAMPIRE_LOOT = 2;
    static const int VAMPIRE_FORCE= 10;

};
#endif //EX4_VAMPIRE_H
