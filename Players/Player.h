//
// Created by yaniv on 07/05/2022.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H
#include <string>

const int MAX_PLAYER_LEVEL = 10;

class Player{
public:
    /** C'tor - Player.
     * Will construct an object from the player class at level 1, with 10 coins and force level 5.
     * A name is a mandatory argument.
     *
     * @param name - A string literal containing the name of the player.
    */
    explicit Player(std::string name);

    /** Copy C'tor of Player class
     *
     * @param player - The new Player will be created out of the values of this player given by reference.
     * @return
     *      A new instance of Player.
     */
    Player(const Player& player) = default;

    /** Assignment operator of Player class.
     *
     * Modifies the values of this Player by copying a given Player's values.
     *
     * @param player - The player which values will be copied to the existing Player.
     * @return - A reference to the assigned player.
     */
    Player& operator=(const Player&) = default;

    /**
     * D'tor of Player class.
     *
    */
    virtual ~Player() = default;

    /** levelUp -  Levels up a Player if the current level is under 10, otherwise does nothing.
     * @return - void
    */
    void levelUp();


    /** buff - Raises the object's force by the given value.
    *
    * @param forceAddition - The value by which the force will increase.
    * @return - void
    */
    void buff(int forceAddition);

    void nerf(int forceSubtraction);

    /** heal - Increments the player's HP by the argument given.
     * Note that the player's HP will not grow above his maxHP.
     *
     * @param HPToAdd - The HP amount to add.
     * @return - void
     */
    virtual void heal(int HPToAdd);

    /** damage - Lowers the player's HP by the amount given as the parameter.
    *            If the  HP value is 0, do nothing.
    *
    * @param HPDecrease - The value by which the HP will be decreased.
    * @return - void.
    */
    void damage(int HPDecrease);

    /** isKnockedOut - Checks if the HP of the object (the player) has dropped to 0.
     *
     * @return - True if the HP is 0
     *           False else.
     */
    bool isKnockedOut() const;

    /** addCoins - Adding coins to the player.
    *
    * @param coinsToAdd - The value to be added to the player's coins.
    *
    * @return - void
    */
    virtual void addCoins(int coinsToAdd);

    /** pay - If the object has the required amount to pay, the said amount will be withdrawn from it's coins.
     *        Otherwise no change would occur in the player's coins.
     *
     * @param amount - the amount needed to complete the payment.
     * @return True - If the payment had been completed (the player had enough coins).
     *         False -  else.
     */
    bool pay(int amount);

    /**
    * Return the attack strength of the player.
    *
    * @return
    *      strength - The current sum of Force and Level values
    */
    virtual int getAttackStrength() const;

    /*
     * Getters
     */
    std::string getName() const;
    int getForce() const;
    int getHP() const;
    int getCoins() const;
    int getLevel() const;

protected:
    /**
     * A method will define the printing per inherited class
     * @param player - An instance of Player should be printed
     */
    virtual void printPlayer(std::ostream& os) const = 0;

    /**
     *
     * @param os
     * @param player
     * @return
     */
    friend std::ostream& operator<<(std::ostream& os, const Player& player);


private:
    int m_coins;//A non-negative int.
    std::string m_name; //A string written in english letters only, no spaces.
    int m_level; //An int from [1,10].
    int m_force;
    int m_maxHP;
    int m_HP; //An int from [0, maxHP].

public:
    static const int DEFAULT_MAX_HP = 100;
    static const int INITIAL_FORCE = 5;
    static const int INITIAL_COINS = 10;
    static const int MULTIPLY = 2;
};


#endif //EX2_PLAYER_H


