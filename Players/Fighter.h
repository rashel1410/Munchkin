//
// Created by Rashel on 08/06/2022.
//

#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H
#include "Player.h"

class Fighter : public Player
{
public:
    /**
     * C'tor of class Fighter
     *
     * @param name - A string name of the new player of type Fighter
     */
    explicit Fighter(std::string name) : Player(name) {}

    /**
     * D'tor of class Fighter
     */
    ~Fighter() override = default;

    /**
    * Return the attack strength of the player.
    *
    * @return
    *      strength - The sum of Force and Level values multiplied by 2
    */
    int getAttackStrength() const override;


protected:
    /**
     * A methods that prints the information of the Fighter
     * @param player
     */
    void printPlayer(std::ostream& os) const override;
};

#endif //EX4_FIGHTER_H
