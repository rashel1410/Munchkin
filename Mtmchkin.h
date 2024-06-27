#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <vector>
#include <queue>
#include <memory>
#include "Players/Player.h"
#include "Cards/Card.h"

static const int MINIMAL_TEAM = 2;
static const int MAX_TEAM = 6;

class Mtmchkin{

public:
    
    /**
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /**
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /**
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /**
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/**
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;


private:

    /**
     * Load the cards out of a given file
     */
    void loadCards(std::ifstream &source);


    std::vector<std::unique_ptr<Player>> m_activePlayers;
    std::vector<std::unique_ptr<Player>> m_losers;
    std::vector<std::unique_ptr<Player>> m_winners;
    std::queue<std::unique_ptr<Card>> m_cards;
    int m_numberOfRounds;

    static const int MINIMAL_DECK = 5;
    static const int GAME_WINING_LEVEL = 10;

};



#endif /* MTMCHKIN_H_ */

