#pragma once
#include "board.h"

//this creates an instance of the struct val struct
val pos;

//this is the board struct which gets its value off of the pos stuct
struct board
{
    std::string aRow = pos.A1 + "|" + pos.A2 + "|" + pos.A3 + "\n";
    std::string bRow = pos.B1 + "|" + pos.B2 + "|" + pos.B3 + "\n";
    std::string cRow = pos.C1 + "|" + pos.C2 + "|" + pos.C3 + "\n";
};