//this is where some of the AI functions are, there are more on cons.cpp
//this is due to issues with the pos struct

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>       // string

std::string AImove()
{
	//intilize the intmoves
	int yintmove = 0, xintmove = 0;
	//intilize the string moves
	std::string ymove, xmove;
	
	//x

	//makes the x move into a string
	xintmove = rand() % 3 + 1;

	if (xintmove == 1)
	{
		xmove = "1";
	}
	if (xintmove == 2)
	{
		xmove = "2";
	}
	if (xintmove == 3)
	{
		xmove = "3";
	}

	//y

	yintmove = rand() % 3 + 1;

	//makes the y move into a string with a number
	if (yintmove == 1)
	{
		ymove = "A";
	}
	if (yintmove == 2)
	{
		ymove = "B";
	}
	if (yintmove == 3)
	{
		ymove = "C";
	}

	std::string final = ymove + xmove;
	return final;
}