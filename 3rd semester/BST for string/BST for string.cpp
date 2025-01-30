#include <iostream>

#include "BST.h"  // Assuming you have a separate header file for your BST class

using namespace std;

int main() {

    BST bst;
    char choice;
    string value;

    do {
        cout << "Binary Search Tree Menu:" << endl;
        cout << "a. Insert a value" << endl;
        cout << "b. Delete a value" << endl;
        cout << "c. Inorder traversal" << endl;
        cout << "d. Preorder traversal" << endl;
        cout << "e. Postorder traversal" << endl;
        cout << "f. Make the tree empty" << endl;
        cout << "g. Check if tree is empty" << endl;
        cout << "h. Exit" << endl;
        cout << "i. print" << endl;
        cout << "Enter your choice (a-h): ";
        cin >> choice;

        switch (choice) {
        case 'a':
            cout << "Enter the value to insert: ";
            cin >> value;
            bst.insert(value);
            cout << "Value inserted successfully." << endl;
            break;

        case 'b':
            cout << "Enter the value to delete: ";
            cin >> value;
            if (bst.deleteNode(value)) {
                cout << "Value deleted successfully." << endl;
            }
            else {
                cout << "Value not found in the tree." << endl;
            }
            break;

        case 'c':
            cout << "Inorder traversal: ";
            bst.inOrder();
            cout << endl;
            break;

        case 'd':
            cout << "Preorder traversal: ";
            bst.preOrder();
            cout << endl;
            break;

        case 'e':
            cout << "Postorder traversal: ";
            bst.postOrder();
            cout << endl;
            break;

        case 'f':
            bst.makeEmpty();
            cout << "Tree is now empty." << endl;
            break;

        case 'g':
            if (bst.isEmpty()) {
                cout << "Tree is empty." << endl;
            }
            else {
                cout << "Tree is not empty." << endl;
            }
            break;

        case 'h':
            cout << "Exiting the program." << endl;
            break;
        case 'i':
            bst.printTreeHelper();
            break;

        default:
            cout << "Invalid choice. Please enter a character between 'a' and 'h'." << endl;
            break;
        }

        system("pause");
        system("cls");
    } while (choice != 'h');

    return 0;
}
