//
// Created by Rashel on 11/06/2022.
//

#include "Battle.h"

#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H
class Goblin : public Battle
{
public:
    /**
     * C'tor of Goblin class which is an instance of a Card
     */
    Goblin();

    /**
     * D'tor of Goblin class
     */
    ~Goblin() override = default;


    /**
     * Prints the details of the Goblin card
     * @param os - The ostream.
     */
    void printInfo(std::ostream& os) const override;

    static const int GOBLIN_FORCE = 6;
    static const int GOBLIN_LOOT = 2;
};

#endif //EX4_GOBLIN_H
