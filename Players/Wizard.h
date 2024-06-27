//
// Created by yaniv on 08/06/2022.
//

#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H
#include "Player.h"

class Wizard : public Player
{
public:
    /**
     * C'tor of Wizard class, will return a new instance of a Wizard (which is a player) of level 1, with 10 coins
     * 5 strength and full HP.
     * @param name - A string, 15 characters long maximum, English letters only.
     */
    explicit Wizard(std::string name) : Player(name) {}

    /**
     * D'tor of Wizard.
     */
    ~Wizard() override = default;

    /** heal - Increments the player's HP by the argument given.
     * Since the player is a Wizard, HP will be increased by double the argument given.
     * Note that the player's HP will not grow above his maxHP.
     *
     * @param HPToAdd - The HP amount to add.
     * @return - void
     */
    void heal(int HPToAdd) override;

protected:
    /**
     *
     * @param os
     */
    void printPlayer(std::ostream& os) const override;

};
#endif //EX4_WIZARD_H
