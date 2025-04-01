#include <iostream>
#include "Binary.h"

using namespace std;

int main() {
    Binary binary;
    char choice;

    do {
        cout << "Binary File Menu" << endl;
        cout << "1. Write data to file" << endl;
        cout << "2. Read data from file" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        system("cls");

        switch (choice) {
        case '1':
            binary.Write();
            cout << "Data written to file." << endl;
            break;
        case '2':
            binary.Read();
            break;
        case '3':
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        system("pause");
        cout << "\nPress any key to continue......";
        system("cls");

    } while (choice != '3');


    

    return 0;
}



