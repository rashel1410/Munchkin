//
// Created by Rashel on 12/06/2022.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H
#include "Battle.h"

class Dragon : public Battle
{

public:
    /**
     * C'tor of Dragon class which is an instance of a battle Card
     */
    Dragon();

    /**
     * D'tor of Dragon class
     */
    ~Dragon() override = default;

    /**
     * Prints the details of the Dragon card
     * @param os - The ostream.
     */
    void printInfo(std::ostream& os) const override;

    static const int DEFAULT_FORCE = 25;
    static const int DEFAULT_LOOT = 1000;
    static const int MAX_HP_ON_LOSS = 100;
};
#endif //EX4_DRAGON_H
