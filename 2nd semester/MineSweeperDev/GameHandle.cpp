//
// Created by PC on 6/16/2023.
//

#include "GameHandle.h"



void GameHandle::Menu() {

    cout << "\n\n\t  Main Menu\n\n";
    cout << "\t1: Easy Mode 5x5\n\n"
         << "\t2: Medium Mode 7x7\n\n"
         << "\t3: Hard Mode 9x9\n\n";
    SetChoice();
}

void GameHandle::SetChoice() {

    cout<<"\tEnter Choice: ";cin>>Choice;

}

char GameHandle::GetChoice() {
    return Choice;
}

void GameHandle::SwitchCase() {

    do
    {
        Menu();
        switch (GetChoice()) {
            case '1':
            {
                EasyMode();
                SetBoxCount(25);

            }
                break;
            case '2':
            {
                MediumMode();
                SetBoxCount(49);

            }
                break;
            case '3':
            {
                HardMode();
                SetBoxCount(91);

            }
                break;
            default:
            {

                cout<<"\tInvalid Input\n\a";
                cout<<"\tPress any key to continue...\n";
                getch();
                system("cls");
            }
        }
    } while (GetChoice()<'1' || GetChoice()>'3');

}

void GameHandle::SetupGame() {

    SwitchCase();
    system("cls");
    initilizeArray();//bombx,bomby initializer
    InitializBoxArray();
    ShowgeneratedBomb();
    DrawBoard();
    cout<<"\t\n\nRemember The Positions\n";
    cout<<"\tPress any key to continue...\n";
    getch();
    InitializBoxArray();


    system("cls");

    do {

        DrawBoard();
        ShowScore();
        SetRow();
        SetColoumn();
        BoxChanger();
        if(getGamestatus())
        {
            system("cls");
            GameWon();
            cout<<"\n\n\tPress any key to continue...\n";
            getch();
            system("cls");
            break;
        }

        system("cls");
    } while (GetPenaltyCount()>0);

    if (GetPenaltyCount()<=0)
    {
        GameLose();
        cout<<"\n\n\tPress any key to continue...\n";
        getch();
    }

}

