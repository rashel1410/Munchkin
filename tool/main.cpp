//
// Created by yaniv on 20/06/2022.
//

#include <iostream>
#include "Mtmchkin.h"
#include "Exception.h"
int main()
{
    try
    {
        Mtmchkin game("../deck.txt");
        while(!game.isGameOver())
        {
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch(std::exception &exception)
    {
        std::cout << exception.what();
    }
    return 0;
}
