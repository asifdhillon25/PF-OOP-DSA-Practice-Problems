#include <iostream>
#include <conio.h>
#include "chekin.cpp"
#include "Saving.cpp"

//function prototypes
void end();
char AccountChoice();
void CurrentSwitch();
void SavingSwitch();

using namespace std;

int main() {

//loop and function to choose account
    char choice='0';
   do{
       choice= AccountChoice();
   } while (choice<'1' || choice>'2');




//Awakening function according to choice
   if(choice=='1')
   {
       CurrentSwitch();
   }
   else if(choice=='2')
   {

       SavingSwitch();
   }

   system("cls");




}











void end(){

    cout<<"Thanks for using my code\n"
        <<"Made by Muhammad Asif\n"
        <<"f2022266062\n";
        cout << "\n\tPress any key to continue...";
                getch();
                system("cls");
}

char AccountChoice()
{
    char ch;
    cout<<"***Welcome to UMT BANK***\n";
    cout<<"\n\tChoose type of account\n";
    cout<<"\t1: Current account\n";
    cout<<"\t2: Saving account\n";
    cin>>ch;
    system("cls");

    return ch;
}

char MainMenu()
{
    char choice2;
    cout << "\t  Main Menu\n";
    cout << "\t1: Check Balance\n"
         << "\t2: Withdraw Amount\n"
         << "\t3: Deposit Amount\n"
         << "\t4: Write Check\n"
         << "\t5: Account Detail\n"
         << "\t6: Post interest to account\n"
         << "\t7: Exit\n";

    cout<<"\n\tEnter your choice\n";
    cin>>choice2;
    system("cls");

    return choice2;
}

void SavingSwitch()
{
    char ch;
    SavingAccount saving;
    system("cls");


    do{
        ch=MainMenu();

        switch (ch) {
            case '1': {
                cout << "Your Balance is : "<<saving.GEtBalance()<<endl;
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");

            }
                break;
            case '2': {

                saving.Withdraw();
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");

            }
                break;
            case '3': {
                saving.Deposit();
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");
            }
                break;
            case '4': {
                cout<<"You cannot write check with saving account\n";
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");
            }
                break;
            case '5': {
                saving.PrintInfos();
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");
            }
                break;
            case '6': {

                saving.Postinterests();

                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");

            }
                break;
                
            case '7': {
            	
                end();
            }

            default:
            {
                cout<<"invalid option\n";
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");

            }

        }
    }while(ch!='7');

}


void CurrentSwitch()
{
    char ch;
    ChekingAccount checking;
    system("cls");


    do{
        ch=MainMenu();

        switch (ch) {
            case '1': {
                cout << "Your Balance is : " << checking.GEtBalance() << endl;
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");

            }
                break;
            case '2': {

                checking.Withdraw();
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");

            }
                break;
            case '3': {
                checking.Deposit();
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");
            }
                break;
            case '4': {
                checking.writecheck();
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");
            }
                break;
            case '5': {
                checking.PrintInfoc();
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");
            }
                break;
            case '6': {

                checking.Postinterestc();

                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");

            }
                break;
            case '7': {
                end();
            }
			
            default:
            {
                cout<<"invalid option\n";
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");

            }

        }
    }while(ch!='7');

}

