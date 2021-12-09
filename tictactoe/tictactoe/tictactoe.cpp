// tictactoe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "board.h"
#include "cons.h"
#include "AI.h"

int main()
{
    while (1)
    {
        //clears the board for use
        clearboard();


        //seeds the rand function in the AI.cpp
        srand(time(NULL));
        //intize move request
        std::string move;

        while (1)
        {
            //this is the function that takes the AI move request and displays the O on the board
            AIawfullness();
            //this peaks at all square values and reads them
            readboard();
            //if the board has AI winning positions then you lose
            if (AIwin())
            {
                std::cout << "you lose!!\nPlay again? y or n\n";
                char yorn;
                std::cin >> yorn;
                //this breaks out to the other while loop and clears the board
                if (yorn == 'y') { clearboard();  break; }
                //this reutrns main loop
                if (yorn == 'n') return 1;
            }
            //gets the value for move request
            std::cin >> move;
            if (move == "R") { clearboard();  break; }
            //this is the function that takes the move request and displays it on the board
            awfullness(move);
            //this displays the new board values
            readboard();
            //if the board has your winning positions then you win
            if (testwin())
            {

                std::cout << "You win!!\nPlay again? y or n\n";
                char yorn;
                std::cin >> yorn;
                //this breaks out to the other while loop and clears the board
                if (yorn == 'y') { clearboard();  break; }
                //this reutrns main loop
                if (yorn == 'n') return 1;

            }
            if (checktie())
            {
                std::cout << "Tie!!!\nPlay again? y or n\n";
                char yorn;
                std::cin >> yorn;
                //this breaks out to the other while loop and clears the board
                if (yorn == 'y') { clearboard();  break; }
                //this reutrns main loop
                if (yorn == 'n') return 1;

            }
        }
    }
}
