
#include <iostream>
#include"MaxHeap.h"
#include <iostream>
#include "MaxHeap.h"
using namespace std;



int main()
{
    char choice;
    MaxHeap  MyMaxHeap;

    do {

        cout << "-----------------------" << endl;
        cout << "MinHeap & MaxHeap Menu" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Insert MaxHeap" << endl;
        cout << "2. Print MaxHeap" << endl;
        cout << "3. Get MaxHeap root" << endl;
        cout << "0. Exit" << endl;
        cout << "-----------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':

            int value;
            cout << "Enter the value to insert: ";
            cin >> value;
            MyMaxHeap.insert(value);
            break;

        case '2':

            MyMaxHeap.Print();
            break;
        case '3':

           cout << MyMaxHeap.getMin();
            break;
        case '0':
            // Exit
            cout << "Exiting the program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        system("pause");
        system("cls");
    } while (choice != '0');
}
