#include "board.h"
#include <iostream>
#include "posdef.h"
#include "AI.h"

struct aimoves
{
    int moves = 0;

    int corner = 0;

    int finalmove = 0;

    bool defeated = 0;

    void incmove()
    {
        moves += 1;
    }
} AI;

//prints line break a bunch of times
void clearcon()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << "\n";
    }
    std::cout << "A B C for the Y value and 1 2 3 for X\nExample: B2 is the center square\nAI defeated = " << AI.defeated << "\nR to reset";
    for (int i = 0; i < 10; i++)
    {
        std::cout << "\n";
    }
    std::cout << "  1 2 3\nA #|#|#\nB #|#|#\nC #|#|#";
    for (int i = 0; i < 8; i++)
    {
        std::cout << "\n";
    }
}

//reads the values in the rows which get their value from posdef.h
void readboard()
{
    board row;

    clearcon();

    std::cout << row.aRow;
    std::cout << "-----\n";
    std::cout << row.bRow;
    std::cout << "-----\n";
    std::cout << row.cRow;
}

//if the player inputs a postion on the board and its blank this displays it
void awfullness(std::string ask)
{
    if (ask == "A1")
    {
        if (pos.A1 == "#")
        {
            pos.A1 = "X";
        }
    }
    if (ask == "A2")
    {
        if (pos.A2 == "#")
        {
            pos.A2 = "X";
        }
    }
    if (ask == "A3")
    {
        if (pos.A3 == "#")
        {
            pos.A3 = "X";
        }
    }
    //b colum
    if (ask == "B1")
    {
        if (pos.B1 == "#")
        {
            pos.B1 = "X";
        }
    }
    if (ask == "B2")
    {
        if (pos.B2 == "#")
        {
            pos.B2 = "X";
        }
    }
    if (ask == "B3")
    {
        if (pos.B3 == "#")
        {
            pos.B3 = "X";
        }
    }
    //c colum
    if (ask == "C1")
    {
        if (pos.C1 == "#")
        {
            pos.C1 = "X";
        }
    }
    if (ask == "C2")
    {
        if (pos.C2 == "#")
        {
            pos.C2 = "X";
        }
    }
    if (ask == "C3")
    {
        if (pos.C3 == "#")
        {
            pos.C3 = "X";
        }
    }
}

void checkb2()
{
    if (pos.B2 == "X") { AI.defeated = 1; }
}

//this is the AIs way of displaying its pos
void AIawfullness()
{

    /*
    
    Step 1
        X|#|#
        -----
        #|#|#
        -----
        #|#|#

    Step 2
        X|#|#
        -----
        #|#|#
        -----
        X|#|#
    Step 3
        check if space inbetween x's are filled

            if not
            X|#|#
            -----
            X|#|#
            -----
            X|#|#

            if it is 
            X|#|#
            -----
            #|#|#
            -----
            X|#|X
    Step 4
        check if any spaces are open
            X|#|#
            -----
            X|#|#
            -----
            X|#|X


            X|#|#
            -----
            #|#|#
            -----
            X|X|X
            

            X|#|#
            -----
            #|X|#
            -----
            X|#|X
    */

    //this uses a stratagy that can be beat, sometimes the AI can tell when the stratagy fails and switches over to random place ment
    while (!AI.defeated)
    {
        //this is will the first move
        if (AI.moves == 0)
        {
            while (1)
            {
                //picks a random corner so the startagy layout isnt the same everytime
                AI.corner = rand() % 4 + 1;
                //puts an O where the corner is, and then breaks the while loop
                if (AI.corner == 1 && pos.A1 == "#") { pos.A1 = "O"; break; }

                if (AI.corner == 2 && pos.A3 == "#") { pos.A3 = "O"; break; }

                if (AI.corner == 3 && pos.C1 == "#") { pos.C1 = "O"; break; }

                if (AI.corner == 4 && pos.C3 == "#") { pos.C3 = "O"; break; }

                //if the space is already filled the while loop gets run again and the rand function gets a new value for corner
            }
            //after it puts an O in the corner it increaments the AI move counter by 1
            AI.incmove();
            return;
        }
        //second move
        if (AI.moves == 1)
        {
            while (1)
            {
                //corner 1

                //checks for any open squares across from the corner on the X and Y axes
                if (AI.corner == 1 && pos.A3 == "#") { pos.A3 = "O"; break; }

                if (AI.corner == 1 && pos.C1 == "#") { pos.C1 = "O"; break; }
                //if neither are open the AI fails TODO: add better comment
                if (AI.corner == 1 && pos.A3 != "#" && pos.C1 != "#") { AI.defeated = true; break; }
                // corner 2

                if (AI.corner == 2 && pos.A1 == "#") { pos.A1 = "O"; break; }

                if (AI.corner == 2 && pos.C3 == "#") { pos.C3 = "O"; break; }

                if (AI.corner == 2 && pos.A1 != "#" && pos.C3 != "#") { AI.defeated = true; break; }
                //corner 3

                if (AI.corner == 3 && pos.A1 == "#") { pos.A1 = "O"; break; }

                if (AI.corner == 3 && pos.C3 == "#") { pos.C3 = "O"; break; }

                if (AI.corner == 3 && pos.A1 != "#" && pos.C3 != "#") { AI.defeated = true; break; }
                //corner 4

                if (AI.corner == 4 && pos.A3 == "#") { pos.A3 = "O"; break; }

                if (AI.corner == 4 && pos.C1 == "#") { pos.C3 = "O"; break; }

                if (AI.corner == 4 && pos.A3 != "#" && pos.C1 != "#") { AI.defeated = true; break; }
            }
            //see after first move while loop for description of AI.incmove function
            AI.incmove();
            return;
        }
        //third move
        if (AI.moves == 2)
        {
            while (1)
            {
                //if the oppenante doesnt break the line between the first corner and the adjacent it gets filled in so the AI wins

                //corner 1 lazy opp
                if (AI.corner == 1 && pos.C1 == "O" && pos.B1 == "#") { pos.B1 = "O"; break; }

                if (AI.corner == 1 && pos.A3 == "O" && pos.A2 == "#") { pos.A2 = "O"; break; }

                //corner 2 lazy opp
                if (AI.corner == 2 && pos.A1 == "O" && pos.A2 == "#") { pos.A2 = "O"; break; }

                if (AI.corner == 2 && pos.C3 == "O" && pos.B2 == "#") { pos.B2 = "O"; break; }

                //corner 3 lazy opp
                if (AI.corner == 3 && pos.A1 == "O" && pos.B1 == "#") { pos.B1 = "O"; break; }

                if (AI.corner == 3 && pos.C3 == "O" && pos.C2 == "#") { pos.C2 = "O"; break; }

                //corner 4 lazy opp
                if (AI.corner == 4 && pos.A3 == "O" && pos.B3 == "#") { pos.B3 = "O"; break; }

                if (AI.corner == 4 && pos.C1 == "O" && pos.C2 == "#") { pos.C2 = "O"; break; }

                //this checks if they filled in the center which makes this stratagy useless.
                checkb2();

                //if they do break the line you go on the horizontal line from either the corner or 2nd move


                //corner 1
                if (AI.corner == 1 && pos.C1 == "O" && pos.C3 == "#") { pos.C3 = "O"; AI.finalmove = 1; break; } //final senario 1

                if (AI.corner == 1 && pos.A3 == "O" && pos.C1 == "#") { pos.C1 = "O"; AI.finalmove = 2; break; } //final senario 2

                //corner 2
                if (AI.corner == 2 && pos.C3 == "O" && pos.C1 == "#") { pos.C1 = "O"; AI.finalmove = 3; break; } //final senario 3

                if (AI.corner == 2 && pos.A1 == "O" && pos.C3 == "#") { pos.C3 = "O"; AI.finalmove = 4; break; } //final senario 4

                //corner 3
                if (AI.corner == 3 && pos.A1 == "O" && pos.A3 == "#") { pos.A3 = "O"; AI.finalmove = 5; break; } //final senario 5

                if (AI.corner == 3 && pos.C3 == "O" && pos.A1 == "#") { pos.A1 = "O"; AI.finalmove = 6; break; } //final senario 6

                //corner 4
                if (AI.corner == 4 && pos.A3 == "O" && pos.A1 == "#") { pos.A1 = "O"; AI.finalmove = 7; break; } //final senario 7

                if (AI.corner == 4 && pos.C1 == "O" && pos.A3 == "#") { pos.A3 = "O"; AI.finalmove = 8; break; }  //final senario 8

                else { AI.defeated = true; break; }
            }
            AI.incmove();
            return;

        }
        //forth move
        if (AI.moves == 3)
        {
            //this uses a switch so we dont have to check with logic gates, it gets its value from part 2 of the third move
            switch (AI.finalmove)
            {
            case 1:
                //this checks if 2 points that would make a win for the AI if they are empty they are filled in
                if (pos.C2 == "#") { pos.C2 = "O"; break; }
                if (pos.B2 == "#") { pos.B2 = "O"; break; }
                //if both these points are filled in the AI switches to defeated
                else { AI.defeated = true; }
                break;
            case 2:
                if (pos.B1 == "#") { pos.B1 = "O"; break; }
                if (pos.B2 == "#") { pos.B2 = "O"; break; }
                else { AI.defeated = true; }
                break;
            case 3:
                if (pos.A2 == "#") { pos.A2 = "O"; break; }
                if (pos.B2 == "#") { pos.B2 = "O"; break; }
                else { AI.defeated = true; }
                break;
            case 4:
                if (pos.B2 == "#") { pos.B2 = "O"; break; }
                if (pos.B3 == "#") { pos.B3 = "O"; break; }
                else { AI.defeated = true; }
                break;
            case 5:
                if (pos.B2 == "#") { pos.B2 = "O"; break; }
                if (pos.A2 == "#") { pos.A2 = "O"; break; }
                else { AI.defeated = true; }
                break;
            case 6:
                if (pos.B1 == "#") { pos.B1 = "O"; break; }
                if (pos.B2 == "#") { pos.B2 = "O"; break; }
                else { AI.defeated = true; }
                break;
            case 7:
                if (pos.B2 == "#") { pos.B2 = "O"; break; }
                if (pos.A2 == "#") { pos.A2 = "O"; break; }
                else { AI.defeated = true; }
                break;
            case 8:
                if (pos.B2 == "#") { pos.B2 = "O"; break; }
                if (pos.B3 == "#") { pos.B3 = "O"; break; }
                else { AI.defeated = true; }
                break;

            }
        }
        //only 4th move sees this return
        return;
    }
    //random placement instead of calculated placement occurs when the stratagy has failed
    while (AI.defeated)
    {
        //check to see if the user is one move away
        /*
        
        //case 1
        XX#
        ###
        ###

        case 2
        #XX
        ###
        ###

        case 3
        ###
        XX#
        ###

        case 4
        ###
        #XX
        ###

        case 5
        ###
        ###
        XX#
        
        case 6
        ###
        ###
        #XX

        case 7
        X##
        #X#
        ###

        case 8
        ##X
        #X#
        ###

        case 9
        ###
        #X#
        X##
        
        case 10
        ###
        #X#
        ##X

        case 11
        ###
        #X#
        #X#

        case 12
        #X#
        #X#
        ###

        */

        //case 1
        if (pos.A1 == "X" && pos.A2 == "X") { pos.A3 = "O"; break; }
        //case 2
        if (pos.A2 == "X" && pos.A3 == "X") { pos.A1 = "O"; break; }
        //case 3
        if (pos.B1 == "X" && pos.B2 == "X") { pos.B3 = "O"; break; }
        //case 4
        if (pos.B2 == "X" && pos.B3 == "X") { pos.B1 = "O"; break; }
        //case 5
        if (pos.C1 == "X" && pos.C2 == "X") { pos.C3 = "O"; break; }
        //case 6
        if (pos.C3 == "X" && pos.C2 == "X") { pos.C1 = "O"; break; }
        //case 7
        if (pos.A1 == "X" && pos.A2 == "X") { pos.C3 = "O"; break; }
        //case 8
        if (pos.A3 == "X" && pos.B2 == "X") { pos.C1 = "O"; break; }
        //case 9
        if (pos.C1 == "X" && pos.B2 == "X") { pos.A3 = "O"; break; }
        //case 10
        if (pos.C3 == "X" && pos.B2 == "X") { pos.A1 = "O"; break; }
        //case 11
        if (pos.C2 == "X" && pos.B2 == "X") { pos.A2 = "O"; break; }
        //case 12
        if (pos.B2 == "X" && pos.A2 == "X") { pos.C2 = "O"; break; }

        //genarates a string that is one of the positions on the board
        std::string ask = AImove();

        if (ask == "A1")
        {
            if (pos.A1 == "#")
            {
                pos.A1 = "O";
                break;
            }
        }
        if (ask == "A2")
        {
            if (pos.A2 == "#")
            {
                pos.A2 = "O";
                break;
            }
        }
        if (ask == "A3")
        {
            if (pos.A3 == "#")
            {
                pos.A3 = "O";
                break;
            }
        }
        //b colum
        if (ask == "B1")
        {
            if (pos.B1 == "#")
            {
                pos.B1 = "O";
                break;
            }
        }
        if (ask == "B2")
        {
            if (pos.B2 == "#")
            {
                pos.B2 = "O";
                break;
            }
        }
        if (ask == "B3")
        {
            if (pos.B3 == "#")
            {
                pos.B3 = "O";
                break;
            }
        }
        //c colum
        if (ask == "C1")
        {
            if (pos.C1 == "#")
            {
                pos.C1 = "O";
                break;
            }
        }
        if (ask == "C2")
        {
            if (pos.C2 == "#")
            {
                pos.C2 = "O";
                break;
            }
        }
        if (ask == "C3")
        {
            if (pos.C3 == "#")
            {
                pos.C3 = "O";
                break;
            }
        }
        //if these all fail there is another random number genarated.
    }
}

/*

##X !
##X !
##X !

XXX !
### !
### !

X## !
X## !
X## !

### !
### !
XXX !

### !
XXX !
### !

##X
#X#
X##

X##
#X#
##X

#X#
#X#
#X#


*/

//this tests to see if theres any winning paterns for the player
bool testwin()
{
    if (pos.A3 == "X" && pos.B3 == "X" && pos.C3 == "X") { return true; }

    if (pos.A1 == "X" && pos.A2 == "X" && pos.A3 == "X") { return true; }

    if (pos.A1 == "X" && pos.B1 == "X" && pos.C1 == "X") { return true; }

    if (pos.C1 == "X" && pos.C2 == "X" && pos.C3 == "X") { return true; }

    if (pos.B1 == "X" && pos.B2 == "X" && pos.B3 == "X") { return true; }

    if (pos.A3 == "X" && pos.B2 == "X" && pos.C1 == "X") { return true; }

    if (pos.A1 == "X" && pos.B2 == "X" && pos.C3 == "X") { return true; }

    if (pos.A2 == "X" && pos.B2 == "X" && pos.C2 == "X") { return true; }

    return false;
}
//this tests to see if theres any winning paterns for the AI
bool AIwin()
{
    if (pos.A3 == "O" && pos.B3 == "O" && pos.C3 == "O") { return true; }

    if (pos.A1 == "O" && pos.A2 == "O" && pos.A3 == "O") { return true; }

    if (pos.A1 == "O" && pos.B1 == "O" && pos.C1 == "O") { return true; }

    if (pos.C1 == "O" && pos.C2 == "O" && pos.C3 == "O") { return true; }

    if (pos.B1 == "O" && pos.B2 == "O" && pos.B3 == "O") { return true; }

    if (pos.A3 == "O" && pos.B2 == "O" && pos.C1 == "O") { return true; }

    if (pos.A1 == "O" && pos.B2 == "O" && pos.C3 == "O") { return true; }

    if (pos.A2 == "O" && pos.B2 == "O" && pos.C2 == "O") { return true; }

    return false;
}
//this sets the pos back to the original state
void clearboard()
{
    //sets all AI struct to 0
    AI.moves = 0;
    AI.defeated = 0;
    AI.finalmove = 0;
    AI.corner = 0;

    pos.A1 = "#";
    pos.A2 = "#";
    pos.A3 = "#";
    pos.B1 = "#";
    pos.B2 = "#";
    pos.B3 = "#";
    pos.C1 = "#";
    pos.C2 = "#";
    pos.C3 = "#";
}

bool checktie()
{
    //if the entire board is filled up but nobody won its a tie, AD NOTE: must be used AFTER win check
    if (pos.A1 != "#" && pos.A2 != "#" && pos.A3 != "#" && pos.B1 != "#" && pos.B2 != "#" && pos.B3 != "#" && pos.C1 != "#" && pos.C2 != "#" && pos.C3 != "#")
    { return true; }

    else { return false;  }
}