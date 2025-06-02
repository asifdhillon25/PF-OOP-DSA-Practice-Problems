#include <iostream>
#include "sqlite/sqlite3.h"
#include "Sqllite.h"
#include <string>
using namespace std;


int main() {


	Sqllite myobj;

	myobj.CreateTable();
     string Name;

	char choice;
    do {
        // Display the menu
        std::cout << "SQLite Operations Menu" << std::endl;
        std::cout << "1. Add Data" << std::endl;
        std::cout << "2. Print All Data" << std::endl;
        std::cout << "3. Delete Data" << std::endl;
        std::cout << "4. Search Person Name" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        switch (choice)
        {
        case '1':
        {
            myobj.WriteData();
        }
        break;
        case '2':
        {
            // Print All Data
            myobj.PrintAllData();
        }

        break;
        case '3':
        {
            myobj.Delete();
        }

        break;
        case '4':
        {
            cout << "Enter Person name to Search\n";
            cin.ignore();
            getline(cin, Name);
            const char* name = Name.c_str();
            cout << "Printing Found Names......\n\n";
            myobj.Search(name);
        }

        break;
        case '5':
            // Exit the program
            std::cout << "Exiting the program." << std::endl;
            break;

        default:
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
      
        
       

        system("pause");
        cout << "Press any key to continue......\n";
        system("cls");

    } while (choice != '5');

}
