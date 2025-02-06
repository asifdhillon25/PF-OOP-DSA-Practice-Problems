#include <iostream>
#include "Queue.h"




void showQueue(Queue<int> s)
{

	while (!s.empty())
	{


		cout << s.dequeue() << endl;



	}

}


int main()
{
	Queue<int> Myobj;



	char choice;


	do
	{
		cout << "\t\tMENU\n"
			<< "\tPress 1 to add a new item to the Queue\n"
			<< "\tPress 2 to remove and return the last element from the Queue. \n"
			<< "\tPress 3 to return the size of the Queue\n"
			<< "\tPress 4 to display the Queue\n"
			<< "\tPress 5 to check if the Queue is empty\n"
			<< "\t6: Exit  \n";

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
			cout << "Current size of Queue is:" << Myobj.size();

		}
		break;
		case '4':
		{
			cout << "showing all elements\n";
			showQueue(Myobj);
		}
		break;
		case '5':
		{
			if (Myobj.empty())
			{
				cout << "Queue is empty\n";
			}
			else
			{
				cout << "Queue is not empty\n";
			}
		}
		break;

		case '6':
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

	} while (choice != '6');









}


