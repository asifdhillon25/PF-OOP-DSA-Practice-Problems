#include <iostream>
#include <string>
#include<conio.h>
#include "calender.cpp"
using namespace std;

void end();
int main()
{
    Daytype object;

    char choice;
    do {
        cout<<"\tSelect a function to perform\n";
        cout<<"\t1: Set Day\n"
            <<"\t2: Show Current Day\n"
            <<"\t3: Show Next Day\n"
            <<"\t4: Show Previous Day\n"
            <<"\t5: Show with Choice no\n"
            <<"\t6: Exit\n";

        cout<<"Choose a number : ";
        cin>>choice;
        system("cls");


        switch (choice) {
            case '1':
            {
                object.Setday();
                cin.ignore();
                cin.get();
                system("cls");
                
            }
            break;
            case '2':
            {
                cout<<"Current day is : "<<object.GetCurrentday()<<endl;
                cout << "\n\tPress any key to continue...";
        		getch(); 
				system("cls");
				
            }
                break;
            case '3':
            {
                cout<<"Next day is : "<<object.GetNextday()<<endl;
                cout << "\n\tPress any key to continue...";
        		getch(); 
				system("cls");
            }
                break;
            case '4':
            {
                cout<<"Previous day is : "<<object.GetPreviousday()<<endl;
                 cout << "\n\tPress any key to continue...";
        		getch(); 
				system("cls");
            }
                break;
            case '5':
            {
            	int choice1;
            	cout<<"Enter a number to which you want to calculate\n";
       			cin>>choice1;
                cout<<"Day at your choice no is : "<<object.bychoice(choice1);
                 cout << "\n\tPress any key to continue...";
        		getch(); 
				system("cls");
            }
            break;
            case '6':
            {
                goto label1;
                 
                
            }
            default:
            	{
            		cout<<"invalid option\n";
            		cout << "\n\tPress any key to continue...";
        				getch(); 
					system("cls");
				}

        }


    }
   while(choice!='6' );


label1:
    end();





}

void end(){

    cout<<"Thanks for using my code\n"
    <<"Made by Muhammad Asif\n"
    <<"f2022266062\n";
}
