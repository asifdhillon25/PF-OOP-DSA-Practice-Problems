


#include <iostream>
#include <cstdlib> // For system("pause") and system("cls")
#include <string>// For using string type
#include "RedBlack.h"
#include "RedBlack.cpp"
using namespace std;

enum {
    jan, feb, march
};


int main() {


    
    

    RedBlack<int> mytree;
    string choice;
    
    do {
        system("color 20");// system code for changing console background
        cout << "\tPress 1 to insert values in the tree (one by one)\n";
        cout << "\tPress 2 for searching a value from the tree\n";
        cout << "\tPress 3 for pre-order traversal NLR\n";
        cout << "\tPress 4 for in-order traversal LNR\n";
        cout << "\tPress 5 for post-order traversal LRN\n";
        cout << "\tPress 6 for pre-order traversal 2 NRL\n";
        cout << "\tPress 7 for in-order traversal 2 RNL\n";
        cout << "\tPress 8 for post-order traversal 2 RLN\n";
        cout << "\tPress 9 for displaying parent of a node present in Tree\n";
        cout << "\tPress 10 to read integer values from the file “input.txt” to create a red-black tree\n";
        cout << "\tPress 11 to delete all duplicate values from the tree\n";
        cout << "\tPress 12 to destroy the complete tree\n";
        cout << "\tPress 13 to EXIT\n";
        cout <<WHITE_COLOR<< "Enter your choice: ";
        cin >> choice;


        if (choice == "13") {
            cout << "Exiting the program. Goodbye!\n";
        }
        else {
            switch (stoi(choice)) {
            case 1:
                // Code for inserting values one by one
                int value;
                cout << "Enter Vallue to insert:  ";
                cin >> value;
                mytree.insert(value);
                break;
            case 2:
                // Code for searching a value in the tree
                int value1;
                cout << "Enter Vallue to search:  ";
                cin >> value1;
                if (mytree.Search(value1))
                {
                    cout << "***Value found!***\n";
                }
                else
                {
                    cout << "***Value not found!***\n";
                }

                break;
            case 3:
               
                mytree.preorder();
                cout << "\n";
                break;
            case 4:
                // Code for in-order traversal LNR
                mytree.inorder();
                cout << "\n";
                break;
            case 5:
                // Code for post-order traversal LRN
                mytree.postorder();
                cout << "\n";
                break;
            case 6:
                // Code for pre-order traversal 2 NRL
                mytree.preorder2();
                cout << "\n";
                break;
            case 7:
                // Code for in-order traversal 2 RNL
                mytree.inorder2();
                cout << "\n";

                break;
            case 8:
                // Code for post-order traversal 2 RLN
                mytree.postorder2();
                cout << "\n";
                break;
            case 9:
                // Code for displaying the parent of a node
                mytree.PrintRoot();
                cout << "\n";
                break;
            case 10:
                // Code for reading values from "input.txt" to create a red-black tree
                mytree.MakeTreeFromFile();
                cout << "\n";
                break;
            case 11:
                // Code for deleting duplicate values from the tree
                mytree.DeleteDuplicate();
                cout << "All duplicate value count has been reset succcessfully\n";
                break;
            case 12:
                // Code for destroying the complete tree
                mytree.DestroyTree();
                cout << "\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }

            system("pause");
            system("cls");
        }
    } while (choice != "13");

    return 0;

}