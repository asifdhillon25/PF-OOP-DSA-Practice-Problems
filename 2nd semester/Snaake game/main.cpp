#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;

//Variables
const int Width=20;
const int Height=20;
int x,y;
int TailX[100]; int TailY[100];
int TailLength;
int Score;
int FruitX,FruitY;
bool GameOver;
bool InvalidCoord;
enum Direction {Stop=0,LEFT,RIGHT,UP,DOWN};
Direction dir;

void ClearScreen(){

    COORD CursorPosition;

    CursorPosition.X=0;
    CursorPosition.Y=0;

    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),CursorPosition);
}

void Setup()
{
    srand(time(0));
    x=Width/2;
    y=Height/2;
    GameOver=false;
    dir=Stop;
    FruitX=rand()%Width;
    FruitY=rand()%Height;
    Score=0;

}

void Draw(){

    ClearScreen();

    for (int i = 0; i < Width+2; ++i) {

        cout<<'-';
    }
    cout<<endl;


    for (int i = 0; i < Height; ++i) {

        for (int j = 0; j < Width; ++j) {
            if(j==0)
            {
                cout<<'|';
            }

            if (i==x && j==y)
            {
                cout<<'@';
            }
            else if(i==FruitX && j==FruitY)
            {
                cout<<'*';
            }
            else
            {
                bool PrintTail=false;
                for (int k = 0; k < TailLength; ++k) {

                    if(TailX[k]==i && TailY[k]==j)
                    {
                        cout<<'o';
                        PrintTail=true;
                    }
                }
                if(!PrintTail)
                {
                    cout<<' ';
                }

                if(j==Width-1)
                {
                    cout<<'|';
                }
            }
        }
    cout<<endl;

    }
    for (int i = 0; i < Width+2; i++)
    {
        cout << '-';
    }

    cout << endl;
    cout << endl;
    cout << "Score: " << Score << endl;

}
void Input()
{
    // Changes snake's direction depending on the button pressed and doesn't allow player to change direction in invalid way
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'a':
                if (dir != DOWN)
                    dir = UP;
                break;
            case 'w':
                if (dir != RIGHT)
                    dir = LEFT;
                break;
            case 'd':
                if (dir != UP)
                    dir = DOWN;
                break;
            case 's':
                if (dir != LEFT)
                    dir = RIGHT;
                break;
            case 'k':
                GameOver = true;
                break;
        }

    }
}

void Logic()
{
	
	
    
    int prevY=TailY[0];
    int prevX=TailX[0];
    int PrevX2,PrevY2;
    TailX[0]=x;
	TailY[0]=y;
    
    

    for (int i = 1; i <TailLength ; ++i) {

        PrevX2=TailX[i];
        PrevY2=TailY[i];
        TailX[i]=prevX;
        TailY[i]=prevY;
        prevX=PrevX2;
        prevY=PrevY2;
        
        
    }

    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;

    }



    for(int i=0;i<TailLength;i++)
    {
        if (TailX[i]==x && TailY[i]==y)
        {
            GameOver= true;
        }
    }

    if(x==FruitX && y==FruitY)
    {
        Score++;
        FruitX=rand()%Width;
        FruitY=rand()%Height;

        for (int i=0;i<TailLength;) {
            InvalidCoord=false;
            if(TailX[i]==FruitX && TailY[i]==FruitY)
            {
                InvalidCoord=true;
                FruitX=rand()%Width;
                FruitY=rand()%Height;
                break;
            }
            if(!InvalidCoord)
            {
                i++;
            }
        }
        TailLength++;
    }


    if (y >= Height)
        y = 0;
    else if (y < 0)
        y = Height - 1;
    if (x >= Width)
        x = 0;
    else if (x < 0)
        x = Width - 1;
}



int main() {


    Setup();
    while (!GameOver) // Game mainloop
    {
        Draw();
        if (dir == UP || DOWN)
            Sleep(20); // Helps to equate vertical snake movement speed and horizontal speed
        Sleep(25);
        Input();
        Logic();

    }

    return 0;





}
