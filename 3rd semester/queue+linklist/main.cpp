
#include <iostream>
#include "Queue.h"
using namespace std;
int main()
{
	Queue<int> Myobj;



	char choice;


	do
	{
		cout << "\t\tMENU\n"
			<< "\tPress 1 to add a new item to the Queue\n"
			<< "\tPress 2 to remove and return the last element from the queue. \n"
			<< "\tPress 3 to display the Queue\n"
			<< "\t4: Exit  \n";

		cout << "enter choice: ";
		cin >> choice;
		cout << "\n\n\n";

		switch (choice)
		{
		case '1':
		{
			cout << "Enter value to push\n";
			int num; cin >> num;
			Myobj.enqueue(num);

		}

		break;
		case '2':
		{
			cout << "this value " << Myobj.dequeue() << "has been popped\n";


		}
		break;
		
		case '3':
		{
			Myobj.display();
		}
		break;
		
		case '4':
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

	} while (choice != '4');

	
}
