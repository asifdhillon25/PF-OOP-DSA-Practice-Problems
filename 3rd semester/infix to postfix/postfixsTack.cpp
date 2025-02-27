

#include <iostream>
#include "Stack.h"
#include "string"
#include "Myfunctions.h"
using namespace std;

int main()
{
   
    Stack <char> StackAprnd;

    char operators[4] = { '-','+','*','/' };


    char choice;
    do
    {
        cout<< "\t\tMENU\n"
            << "\t1: To check Equation \n"
            << "\t2: Exit  \n";

        cout << "\nenter choice: ";
        cin >> choice;
        
        cout << "\n\n\n";

        switch (choice)
        {
        case '1':
        {
            cout << "Enter equation to see its postfix form \n";
            cout << "*****Accepted Equation Form: a+45-6*3  or (((a+b)*(c-e))/(f+g))  etc*****\n\n";

            string Tocheck;
            cin >> Tocheck;
           cout<<"\n Postfix form: "<< CalculatePostfix(Tocheck, StackAprnd, operators)<<endl;

        }

        break;
        case '2':
        {
            
           cout << "Thanks for using\n";
        }

        break;
        default:
        {
            cout << "Invalid Input\n";
        }


        cout << "\n\n\n";
        }


        cin.get();
        cin.ignore();
        system("cls");

    } while (choice != '2');


}



