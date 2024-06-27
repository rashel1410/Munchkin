//
// Created by yaniv on 07/05/2022.
//
#include <cassert>
#include "../ourUtilities.h"
#include "../Exception.h"
#include "Player.h"

/** C'tor - Player.
 * Will construct an object from the player class at level 1, with 10 coins and force level 5.
 * A name is a mandatory argument.
 *
 * @param name - A string literal containing the name of the player.
*/
Player::Player(std::string name) :
        m_coins(INITIAL_COINS),
        m_name(name),
        m_level(1),
        m_force(INITIAL_FORCE),
        m_maxHP(DEFAULT_MAX_HP),
        m_HP(DEFAULT_MAX_HP)
{
    if(!isValidName(name))
    {
        throw InvalidName();
    }
}

///** printInfo - Prints the player's details to screen in the following format:
//    * Player Details :
//    * Name: Gandalf
//    * Level: 1
//    * Force: 5
//    * HP: 300
//    * Coins: 0
//    *
//    */
//void Player::printInfo() const
//{
//    char* tempStr = new char[m_name.length()+1];
//    strcpy(tempStr, m_name.c_str());
//    printPlayerInfo(tempStr, m_level, m_force, m_HP, m_coins);
//    delete[] tempStr;
//}

/** levelUp -  Levels up a Player if the current level is under 10, otherwise does nothing.
 *
 * @return - void
*/
void Player::levelUp()
{
    assert(m_level > 0 && m_level <= MAX_PLAYER_LEVEL);
    if(m_level < MAX_PLAYER_LEVEL)
    {
        m_level++;
    }
}

/** getLevel - Returns the current level of a player.
     *
     * @return - Player's level.
     */
int Player::getLevel() const
{
    return m_level;
}

/** buff - Raises the object's force by the given value.
*
* @param forceAddition - The value by which the force will increase.
* @return - void
*/
void Player::buff(int forceAddition)
{
    if(forceAddition > 0)
    {
        m_force += forceAddition;
    }
}

/**
 * Reduces the player's force by the integer given as argument.
 * @param forceSubtraction
 */
void Player::nerf(int forceSubtraction)
{
    if(m_force > 0)
    {
        m_force -= forceSubtraction;
    }
    assert(m_force >= 0);
}

/** heal - Increments the player's HP by the argument given.
     * Note that the player's HP will not grow above his maxHP.
     *
     * @param HPToAdd - The HP amount to add.
     * @return - void
     */
void Player::heal(int HPToAdd)
{
    if(HPToAdd > 0)
    {
        m_HP += HPToAdd;
        if(m_HP > m_maxHP)
        {
            m_HP = m_maxHP;
        }
    }
}

/** damage - Lowers the player's HP by the amount given as the parameter.
*            If the  HP value is 0, does nothing.
*
* @param HPDecrease - The value by which the HP will be decreased.
* @return - void.
*/
void Player::damage(int HPDecrease)
{
    if(HPDecrease <= 0)
    {
        return;
    }
    m_HP -= HPDecrease;
    if(m_HP < 0)
    {
        m_HP = 0;
    }
}

/** isKnockedOut - Checks if the HP of the object (the player) has dropped to 0.
     *
     * @return - True if the HP is 0
     *           False else.
     */
bool Player::isKnockedOut() const
{
    if (m_HP == 0)
    {
        return true;
    }
    return false;
}

/** addCoins - Adding coins to the player.
*
* @param coinsToAdd - The value to be added to the player's coins.
*
* @return - void
*/
void Player::addCoins(int coinsToAdd)
{
    if(coinsToAdd <= 0)
    {
        return;
    }
    m_coins += coinsToAdd;
}

/** pay - If the object has the required amount to pay, the said amount will be withdrawn from it's coins.
     *        Otherwise no change would occur in the player's coins.
     *
     * @param amount - the amount needed to complete the payment.
     * @return True - If the payment had been completed (the player had enough coins).
     *         False -  else.
     */
bool Player::pay(int amount)
{
    assert(amount >= 0);
    if(amount >= 0)
    {
        if (m_coins >= amount)
        {
            m_coins -= amount;
            return true;
        }
        return false;
    }
    return true; //vacuously true.
}

/**
* Return the attack strength of the player.
*
* @return
*      strength - The current sum of Force and Level values
*/
int Player::getAttackStrength() const
{
    return m_level + m_force;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    player.printPlayer(os);
    return os;
}

/**
 * Getters
 */
std::string Player::getName() const
{
    return m_name;
}

int Player::getForce() const
{
    return m_force;
}

int Player::getHP() const
{
    return m_HP;
}
int Player::getCoins() const
{
    return m_coins;
}