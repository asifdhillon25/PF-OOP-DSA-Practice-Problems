
#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
	Stack<int> Myobj;



	char choice;


	do
	{
		cout << "\t\tMENU\n"
			<< "\tPress 1 to add a new item to the stack\n"
			<< "\tPress 2 to remove and return the last element from the stack. \n"
			<< "\tPress 3 to display the stack\n"
			<< "\tPress 4 to display the top element of stack\n"
			<< "\t5: Exit  \n";

		cout << "enter choice: ";
		cin >> choice;
		cout << "\n\n\n";

		switch (choice)
		{
		case '1':
		{
			cout << "Enter value to push\n";
			int num; cin >> num;
			Myobj.Push(num);

		}

		break;
		case '2':
		{
			cout << "this value " << Myobj.Pop() << "has been popped\n";


		}
		break;

		case '3':
		{
			Myobj.display();
		}
		break;

		case '4':
		{
			cout << "Value at top is " << Myobj.Peek() << endl;
		}
		break;

		case '5':
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

	} while (choice != '5');
}