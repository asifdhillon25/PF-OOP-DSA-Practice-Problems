
#ifndef MINESWEEPER_GAMEHANDLE_H
#define MINESWEEPER_GAMEHANDLE_H
#include "Game.h"
#include <iostream>
using namespace std;
class GameHandle: public Game{
    char Choice;

public:

    void Menu ();
    char GetChoice();
    void SetChoice();
    void SwitchCase();
    void SetupGame();


};


#endif //MINESWEEPER_GAMEHANDLE_H

