//
// Created by Rashel on 14/06/2022.
//
#include "Card.h"
#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

class Treasure : public Card
{
public:
    /**
     * C'tor of Treasure class which is an instance of a Card
     */
     Treasure();

    /**
    * D'tor of Treasure class
    */
     ~Treasure() override = default;

    /**
    * Handling the player's encounter with the card:
    * Treasures the player with 10 coins.
    * @param player - The player.
    * @return
    *      void
   */
     void applyEncounter(Player* player) const override;

     static const int COINS_TO_ADD = 10;
};

#endif //EX4_TREASURE_H
