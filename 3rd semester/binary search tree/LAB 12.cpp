#include <iostream>
#include "BinarySearchTree.h"
#include "Tree.h"
#include "BinarySearchTree.cpp"
#include "Tree.cpp"


int main() {
    char choice;
    BinarySearchTree<int> bst;

    do {
        cout << "-----------------------" << endl;
        cout << "Binary Search Tree Menu" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Inorder Traversal" << endl;
        cout << "4. Postorder Traversal" << endl;
        cout << "5. Preorder Traversal" << endl;
        cout << "6. Sum of All Nodes Less Than Root" << endl;
        cout << "7. Count Nodes Divisible by 2 or 3" << endl;
        cout << "8. Height of the Tree" << endl;
        cout << "9. Node Type Count" << endl;
        cout << "a. Right View" << endl;
        cout << "b. Left View" << endl;
        cout << "c. Mirror BST" << endl;
        cout << "0. Exit" << endl;
        cout << "-----------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            // Insert Node
            int value;
            cout << "Enter the value to insert: ";
            cin >> value;
            bst.insertNode(value);
            break;

        case '2':
            // Delete Node
            int deleteValue;
            cout << "Enter the value to delete: ";
            cin >> deleteValue;
            bst.deleteNode(deleteValue);
            break;

        case '3':
            // Inorder Traversal
            cout << "Inorder Traversal: ";
            bst.inOrderTraversal();
            cout << endl;
            break;

        case '4':
            // Postorder Traversal
            cout << "Postorder Traversal: ";
            bst.postOrderTraversal();
            cout << endl;
            break;

        case '5':
            // Preorder Traversal
            cout << "Preorder Traversal: ";
            bst.preOrderTraversal();
            cout << endl;
            break;

        case '6':
            // Sum of All Nodes Less Than Root
            cout << "Sum of All Nodes Less Than Root: " << bst.SumOfAllLessThanRoot() << endl;
            break;

        case '7':
            // Count Nodes Divisible by 2 or 3
            cout << "Count of Nodes Divisible by 2 or 3: " << bst.divisibelBy2oR3() << endl;
            break;

        case '8':
            // Height of the Tree
            cout << "Height of the Tree: " << bst.height() << endl;
            break;

        case '9':
            // Node Type Count
           
            bst.nodeTypecount();
            
            break;


        case 'a':
            // Node Type Count

            bst.RightView();

            break;

        case 'b':
            // Node Type Count

            bst.LeftView();

            break;

        case 'c':
            // Node Type Count

            bst.MirrorBst();

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

    return 0;
}
