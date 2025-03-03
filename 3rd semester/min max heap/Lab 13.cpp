
#include <iostream>
#include"MinHeap.h"
#include <iostream>
using namespace std;



int main()
{
    char choice;
    MinHeap  MyMinHeap;

    do {

        cout << "-----------------------" << endl;
        cout << "MinHeap & MaxHeap Menu" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Insert MinHeap" << endl;
        cout << "2. Print MinHeap" << endl;
        cout << "3. Get MinHeap root" << endl;
        cout << "0. Exit" << endl;
        cout << "-----------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':

            int value;
            cout << "Enter the value to insert: ";
            cin >> value;
            MyMinHeap.insert(value);
            break;

        case '2':

            MyMinHeap.Print();
            break;
        case '3':

            cout<<MyMinHeap.getMin();
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
