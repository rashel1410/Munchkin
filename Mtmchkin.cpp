//
// Created by Rashel on 14/06/2022.
//
#include "Mtmchkin.h"
#include "utilities.h"
#include <string>
#include <fstream>
#include "Cards/Dragon.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"
#include "Cards/Goblin.h"
#include "Cards/Fairy.h"
#include "Cards/Pitfall.h"
#include "Cards/Barfight.h"
#include "Cards/Merchant.h"
#include "Players/Wizard.h"
#include "Players/Rogue.h"
#include "Players/Fighter.h"
#include "ourUtilities.h"

using std::ifstream;
using std::ofstream;
using std::string;
using std::cin;

/*
 * static declarations
 */
static std::unique_ptr<Player> getPlayer();
static int getTeamSize();
static std::unique_ptr<Player> createRelevantPlayerByJob(const string &name, const string &job);


Mtmchkin::Mtmchkin(const string &fileName) :
        m_numberOfRounds(0)
{
    printStartGameMessage();
    ifstream source(fileName);
    if (!source)
    {
        throw DeckFileNotFound();
    }

    loadCards(source);

    int teamSize = getTeamSize();
    for(int i = 0; i < teamSize; ++i)
    {
        printInsertPlayerMessage();
        while(true)
        {
            try
            {
                std::unique_ptr<Player> player = getPlayer();
                m_activePlayers.push_back(std::move(player));
                break;
            }
            catch (InvalidName& error)
            {
                printInvalidName();
            }
            catch (InvalidClass& error)
            {
                printInvalidClass();
            }
        }
    }
}

void Mtmchkin::loadCards(std::ifstream &source)
{
    string line;
    int lineCounter = 0;
    while (getline(source, line, '\n'))
    {
        lineCounter++;
        if (line == "Goblin")
        {
            m_cards.push(std::unique_ptr<Card>(new Goblin()));
        }
        else if (line == "Vampire")
        {
            m_cards.push(std::unique_ptr<Card>(new Vampire()));
        }
        else if (line == "Dragon")
        {
            m_cards.push(std::unique_ptr<Card>(new Dragon()));
        }
        else if (line == "Fairy")
        {
            m_cards.push(std::unique_ptr<Card>(new Fairy()));
        }
        else if (line == "Barfight")
        {
            m_cards.push(std::unique_ptr<Card>(new Barfight()));
        }
        else if (line == "Pitfall")
        {
            m_cards.push(std::unique_ptr<Card>(new Pitfall()));
        }
        else if (line == "Treasure")
        {
            m_cards.push(std::unique_ptr<Card>(new Treasure()));
        }
        else if (line == "Merchant")
        {
            m_cards.push(std::unique_ptr<Card>(new Merchant()));
        }
        else
        {
            throw DeckFileFormatError(std::to_string(lineCounter));
        }
    }
    if (m_cards.size() < MINIMAL_DECK)
    {
        throw DeckFileInvalidSize();
    }
}

/**
 * Get a valid team size from the user
 * @return - The team size
 */
static int getTeamSize()
{
    int size = 0;
    string input;
    bool notValid = true;
    IsBetween teamSizeBetween2And6(MINIMAL_TEAM,MAX_TEAM);
    while (notValid)
    {
        printEnterTeamSizeMessage();
        try
        {
            std::getline(std::cin, input);
            size = std::stoi(input);
        }
        catch (const std::exception &e)
        {
            printInvalidTeamSize();
            notValid = true;
            continue;
        }
        notValid = !teamSizeBetween2And6(size);
        if (notValid)
        {
            printInvalidTeamSize();
        }
    }
    return size;
}

/**
 * Gets a name and a job and creates a player instance of the class given as the job with the given name.
 * @param name - The name of the player to be created.
 * @param job - The class of the player to be created.
 * @return - A unique ptr of a new instance of a player.
 */
static std::unique_ptr<Player> createRelevantPlayerByJob(const string &name, const string &job);

/**
 * Creates a new player from the wanted class dynamically given from the user.
 * @return A unique ptr to the new player instance.
 */
static std::unique_ptr<Player> getPlayer()
{
    string userInput, name, job;
    try
    {
        std::getline(std::cin, userInput);
    }
    catch (std::exception& error)
    {
        error.what();
    }
    std::string delimiter = " ";
    name = userInput.substr(0, userInput.find(delimiter));
    if(!isValidName(name))
    {
        throw InvalidName();
    }
    job = userInput.substr(userInput.find(delimiter)+1);

    return createRelevantPlayerByJob(name, job);
}


/**
 * Creates a player with by a name given from the matching player class given as a string.
 * @param name - A string with the wanted name.
 * @param job - A string of the class name of the wanted player.
 * @return - A unique pointer to a new player.
 */

static std::unique_ptr<Player> createRelevantPlayerByJob(const string &name, const string &job)
{

    if (job == "Wizard")
    {
        return std::unique_ptr<Player>(new Wizard(name));
    }
    if (job == "Rogue")
    {
        return std::unique_ptr<Player>(new Rogue(name));
    }
    if (job == "Fighter")
    {
        return std::unique_ptr<Player>(new Fighter(name));
    }
    throw InvalidClass();
}

bool Mtmchkin::isGameOver() const
{
    return m_activePlayers.empty();
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_numberOfRounds;
}

void Mtmchkin::playRound()
{
    printRoundStartMessage(getNumberOfRounds() + 1);
    for(std::vector<std::unique_ptr<Player>>::iterator currentPlayer = m_activePlayers.begin();
        currentPlayer != m_activePlayers.end(); ++currentPlayer) {
        printTurnStartMessage(currentPlayer->get()->getName());

        m_cards.front()->applyEncounter(currentPlayer->get());
        m_cards.push(std::move(m_cards.front()));
        m_cards.pop();
    }

    std::vector<std::unique_ptr<Player>>::iterator currentPlayer = m_activePlayers.begin();
    while(currentPlayer != m_activePlayers.end())
    {
        if(currentPlayer->get()->isKnockedOut())
        {
            m_losers.push_back(std::move((*currentPlayer)));
            currentPlayer = m_activePlayers.erase(currentPlayer);
        }
        else if(currentPlayer->get()->getLevel() == GAME_WINING_LEVEL) //Player had won the game.
        {
            m_winners.push_back(std::move(*currentPlayer));
            currentPlayer = m_activePlayers.erase(currentPlayer);
        }
        else
        {
            ++currentPlayer;
        }
    }

    m_numberOfRounds++;
    if(this->isGameOver())
    {
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const
{
    int ranking = 1;
    printLeaderBoardStartMessage();
    unsigned int numberOfWinners = m_winners.size();
    for(unsigned int i = 0; i < numberOfWinners; i++)
    {
        printPlayerLeaderBoard(ranking++, *m_winners[i]);
    }

    unsigned int numberOfActivePlayers = m_activePlayers.size();
    for(unsigned int i = 0; i < numberOfActivePlayers; i++)
    {
        printPlayerLeaderBoard(ranking++, *m_activePlayers[i]);
    }

    unsigned int numberOfLosers = m_losers.size();
    for(int i = numberOfLosers-1; i >= 0; i--)
    {
        printPlayerLeaderBoard(ranking++, *m_losers[i]);
    }
}
