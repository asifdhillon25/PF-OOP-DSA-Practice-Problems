#include <iostream>
#include<conio.h>
#include "Swimming pool.cpp"
using namespace std;

void end();




int main() {
    SwimmingPool object1;
    system("cls");

    char choice;
    
    do {
        cout << "\tSelect a function to perform\n";
        cout << "\t1: Water needed to fill an empty pool\n"
             << "\t2: Water needed to fill a partially filled pool\n"
             << "\t3: Time needed to fill an empty pool\n"
             << "\t4: Time needed to fill a partially filled pool\n"
             << "\t5: Time needed to drain an empty pool\n"
             << "\t6: Time needed to drain a partially filled pool\n"
             << "\t7: Exit\n";

        cout << "Choose a number : ";
        cin >> choice;
        system("cls");


        switch (choice) {
            case '1': {
                cout << "Water needed to fill an empty pool is : "
                     << object1.Amountofwaterforemptypool() << " Gallons\n";
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");

            }
                break;
            case '2': {
                float volume;
                cout << "Enter the amount of volume already present in gallons : ";
                cin >> volume;
                cout << "Water needed to fill a partially filled pool is : "
                     << object1.Amountofwaterforhalffillpool(volume) << " Gallons\n";
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");

            }
                break;
            case '3': {
                cout << "Time needed to fill an empty pool is : "
                     << object1.TimeforEmptyPool() << " Minutes\n";
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");
            }
                break;
            case '4': {
                float volume;
                cout << "Enter the amount of volume already present in gallons : ";
                cin >> volume;
                cout << "Time needed to fill a partially filled pool is : "
                     << object1.TimeforpartiallyfilledPool(volume) << " Minutes\n";
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");
            }
                break;
            case '5': {
                cout << "Time needed to drain an empty pool is : "
                     << object1.TimeforEmptyPool() << " Minutes\n";
                cout << "\n\tPress any key to continue...";
                getch();
                system("cls");
            }
                break;
            case '6': {
                float volume;
                cout << "Enter the amount of volume already present in gallons : ";
                cin >> volume;
                cout << "Time needed to drain a partially filled pool is : "
                     << object1.TimeforpartiallyfilledPool(volume) << " Minutes\n";
                

            }
                break;
            case '7': {
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
    while(choice!='7' );


    label1:
    end();





}

void end(){

    cout<<"Thanks for using my code\n"
        <<"Made by Muhammad Asif\n"
        <<"f2022266062\n";
}


