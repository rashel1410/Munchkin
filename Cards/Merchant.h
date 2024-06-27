//
// Created by Yaniv on 16/06/2022.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H
#include "Card.h"

class Merchant : public Card
{
public:
    /**
     * C'tor - Merchant.
     */
    Merchant() :
            Card("Merchant"),
            m_forceAdditionCost(DEFAULT_FORCE_ADDITION_PRICE),
            m_HPPotionCost(DEFAULT_HP_ADDITION_PRICE),
            m_forceAdditionAmount(DEFAULT_FORCE_ADDITION),
            m_HPAdditionAmount(DEFAULT_HP_ADDITION)
        {}

    /**
     * D'tor - Merchant.
     */
    ~Merchant() override = default;

    /**
    * Will start the interactive encounter of the merchant.
    * @param player - A pointer to a player.
    */
    void applyEncounter(Player *player) const override;

    static const int DO_NOTHING = 0;
    static const int BUY_HEALTH_POTION = 1;
    static const int BUY_FORCE_BOOST = 2;

private:
    static const int DEFAULT_HP_ADDITION = 1;
    static const int DEFAULT_FORCE_ADDITION = 1;
    static const int DEFAULT_HP_ADDITION_PRICE = 5;
    static const int DEFAULT_FORCE_ADDITION_PRICE = 10;

    int m_forceAdditionCost;
    int m_HPPotionCost;
    int m_forceAdditionAmount;
    int m_HPAdditionAmount;

};
#endif //EX4_MERCHANT_H