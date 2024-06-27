//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "../Players/Player.h"


class Card {
public:
    /**
     * C'tor of Card class
     *
     * @param name - The name of the card.
     * @return
     *      A new instance of Card.
    */
    explicit Card(std::string name);


    /**
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player* player) const = 0;


    /**
     * Prints the card info to a given output stream
     * @param os - an output stream to print to
     * @return
     *      void
    */
    virtual void printInfo(std::ostream& os) const;

    /**
     * Output operator - prints the card details.
     * @param os - an output stream to print to
     * @param card - an instance of a Card which details will be printed
     * @return - an output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

    /**
     * Getters
     */
    std::string getName() const;


    /*
     *  Default copy c'tor, d'tor and =() operator.
     */

    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;


private:
    std::string m_name;
};


#endif //EX2_Card_H
