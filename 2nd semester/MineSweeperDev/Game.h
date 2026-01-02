#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;


class Game {

    int Width;
     int Height;
    char minebox[10][10];
    int bombx[10];
    int bomby[10];
    int alpha=1;
    int alpha1=1;
    bool GameOver;
    int Row,Coloumn;
    int PenaltyCount=3;
    int BoxCount;
    int bombcount=0;
    int GoodBoxCount=0;

public:


    void initilizeArray();
    void ClearScreen(int x,int y);
    void  DrawBoard();
    void InitializBoxArray();
    void SetRow();
    void SetColoumn();
    int GetRow();
    int GetColoumn();
    void BoxChanger();
    void ShowgeneratedBomb();
    bool getGamestatus();
    void EasyMode();
    void MediumMode();
    void HardMode();
    int GetPenaltyCount();
    void ShowBombArray();
    void ShowScore();
    void SetBoxCount(int x);
    int GetBoxCount();
    int GetBombCount();
    int GetGoodBoxCount();
    void GameWon();
    void GameLose();

};



#endif //MINESWEEPER_GAME_H

