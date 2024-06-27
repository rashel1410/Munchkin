//
// Created by Yaniv on 16/06/2022.
//

#include "Merchant.h"
#include "../utilities.h"
#include "../ourUtilities.h"
#include <cassert>
#include <string>
#define HANDLE_INSUFFICIENT_COINS(operation) printMerchantInsufficientCoins(std::cout); \
                                  printMerchantSummary(std::cout, player->getName(), operation, 0);


/**
 * Will read an input from input stream and check that it is in the valid range.
 * @param finalUserChoice - When the user chooses a valid number, it would be stored in this parameter.
 * @return - A boolean indicating if the number was read successfully.
 */
static bool readNumberAndCheckIfLegal(int & finalUserChoice)
{
    std::string userInput;
    //   std::cin >> userInput;
    int userNumber;
    try
    {
        std::getline(std::cin, userInput);
        if(userInput.size() != 1)
        {
            return false;
        }
        userNumber = std::stoi(userInput);
    }
    catch (std::exception const & error) //not a number or too big
    {
        return false;
    }

    IsBetween merchantValidChoices((Merchant::DO_NOTHING), (Merchant::BUY_FORCE_BOOST));
    if(merchantValidChoices(userNumber))
    {
        finalUserChoice = userNumber;
        return true;
    }
    return false;
}

void Merchant::applyEncounter(Player *player) const
{
    int choice;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player->getName(), player->getCoins());
    while(!readNumberAndCheckIfLegal(choice))
    {
        printInvalidInput();
    }
    switch (choice)
    {
        case DO_NOTHING:
            printMerchantSummary(std::cout,player->getName(),DO_NOTHING,0);
            break;

        case BUY_HEALTH_POTION:
            if(player->pay(m_HPPotionCost))
            {
                player->heal(m_HPAdditionAmount);
                printMerchantSummary(std::cout, player->getName(), BUY_HEALTH_POTION, m_HPPotionCost);
            }
            else
            {
                HANDLE_INSUFFICIENT_COINS(BUY_HEALTH_POTION)
            }
            break;

        case BUY_FORCE_BOOST:
            if(player->pay(m_forceAdditionCost))
            {
                player->buff(m_forceAdditionAmount);
                printMerchantSummary(std::cout,player->getName(), BUY_FORCE_BOOST, m_forceAdditionCost);
            }
            else
            {
                HANDLE_INSUFFICIENT_COINS(BUY_FORCE_BOOST)
            }
            break;

        default:
            assert(choice == 0 || choice == 1 || choice == 2);
            throw std::runtime_error("Unexpectedly merchant read a none valid choice");
    }
}


#undef HANDLE_INSUFFICIENT_COINS
