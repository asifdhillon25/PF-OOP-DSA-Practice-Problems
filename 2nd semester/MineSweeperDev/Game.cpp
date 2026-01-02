#ifndef MINESWEEPER_GAME_CPP
#define MINESWEEPER_GAME_CPP

#include "Game.h"



void Game::initilizeArray() {

    int random=Width-1;
    srand(time(0));
    for(int i=0;i<Width;i++)
    {
        bombx[i]=rand()%random+1;
        bomby[i]=rand()%random+1;


    }

}

void Game::ClearScreen(int x,int y) {

    COORD CursorPosition;

    CursorPosition.X=x;
    CursorPosition.Y=y;

    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),CursorPosition);
}








void Game:: DrawBoard()
{
    alpha=1;
    alpha1=1;
    for(int j=0;j<Width;j++)
    {
        if(j==0)//loop to print first line from 1
        {
            cout<<' '<<' ';
        }
        else
            cout<<j<<' ';
    }
    cout<<endl;


    for(int i=0;i<Height;i++)
    {
        for(int j=0;j<Width;j++)
        {
            if(j==0)//loop to print vertical row no,s
            {
                cout<<alpha<<' ';alpha++;
            }

        }

        for(int k=1;k<Width;k++)
        {

            cout<<minebox[i][k]<<' ';
        }



        for(int j=0;j<Width;j++)
        {
            if(j==Width-1)
            {
                cout<<alpha1;alpha1++;
            }

        }



        cout<<endl;


    }
    for(int j=0;j<Width;j++)
    {
        if(j==0)
        {
            cout<<' '<<' ';
        }
        else
            cout<<j<<' ';
    }
    cout<<endl;
}

void Game::InitializBoxArray() {

    for (int i = 0; i < 10; ++i) {

        for (int j = 0; j <10 ; ++j) {

            minebox[i][j]='X';
        }

    }
}

void Game::SetRow() {
    cout<<"Enter Row no: ";
    cin>>Row;

}

void Game::SetColoumn() {

    cout<<"Enter Coloumn no: ";
    cin>>Coloumn;

}

int Game::GetRow() {
    return Row;
}

int Game::GetColoumn() {
    return Coloumn;
}

void Game::BoxChanger() {

    bool check=false;

    for (int i = 0; i < Width; ++i) {
        if(bombx[i]==GetRow() && bomby[i]==GetColoumn())
        {
            minebox[GetRow()-1][GetColoumn()]='*';
            GameOver= true;
            check =true;
            PenaltyCount--;
            cout<<"\a";
        }
    }

    if(!check)
    {
        GoodBoxCount++;
        minebox[GetRow()-1][GetColoumn()]='O';
    }

}

void Game::ShowgeneratedBomb() {


    for (int i = 0; i < Width; ++i) {

            minebox[bombx[i]-1][bomby[i]]='*';
            bombcount++;
    }

}

bool Game::getGamestatus() {

    if(GoodBoxCount==(GetBoxCount()-GetBombCount()))
    {
        return true;
    }
    return false;
}

void Game::EasyMode() {
    Width=6;Height=5;
}

void Game::MediumMode() {
    Width=8;Height=7;
}

void Game::HardMode() {
    Width=10;Height=9;
}

int Game::GetPenaltyCount() {
    return PenaltyCount;
}

void Game::ShowBombArray() {

    for (int i = 0; i < Width; ++i) {
        cout<<bombx[i]<<"  "<<bomby[i]<<endl;
    }
}

void Game::ShowScore() {

    char heartsymbol='a';
    heartsymbol+=162;
    ClearScreen(22,1);
    cout<<"Your Lives: ";
    for (int i = 0; i < GetPenaltyCount(); ++i) {
        cout<<heartsymbol<<' ';
    }

    cout<<endl;
        
	ClearScreen(22,3);
    cout<<"Enter corresponding Row and\n";
    ClearScreen(22,4);
    cout<<"Coloumn no to open A box\n";
    ClearScreen(0,12);
}

void Game::SetBoxCount(int x) {
    BoxCount=x;
}

int Game::GetBoxCount() {
    return BoxCount;
}

int Game::GetBombCount() {
    return bombcount;
}

int Game::GetGoodBoxCount() {
    return GoodBoxCount;
}

void Game::GameWon() {
    char x='a';
    x+=165;
    cout<<"\a\n\n\n\t"<<x<<x<<x<<"Congratulations"<<x<<x<<x<<endl;
    cout<<"\t   ***"<<"You Won***"<<endl;
}

void Game::GameLose() {
    char x='a';
    x+=163;
    cout<<"\a\n\n\n\t"<<x<<x<<x<<"Try Next Time"<<x<<x<<x<<endl;
    cout<<"\t   ***"<<"You Lose***"<<endl;
}
#endif //MINESWEEPER_GAME_cpp
