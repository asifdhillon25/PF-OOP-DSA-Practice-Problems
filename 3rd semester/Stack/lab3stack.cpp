#include <iostream>
#include "Stack.h"




void showStack(Stack<int> s)
{
   
    while (!s.empty())
    {
        
        
            cout << s.pop() << endl;
            
        
        
    }
    
}


int main()
{
    Stack<int> Myobj;



	char choice;


	do
	{
		cout << "\t\tMENU\n"
			<< "\t1: Push Element\n"
			<< "\t2: Pop element\n"
			<< "\t3: Peek Element \n"
			<< "\t4: Show All Elements\n"
			<< "\t5: Check Empty \n"
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
			Myobj.push(num);

		}

		break;
		case '2':
		{
			cout << "this value " << Myobj.pop() << "has been popped\n";


		}
		break;
		case '3':
		{
			cout << "Top element value: " << Myobj.peek();

		}
		break;
		case '4':
		{
			cout << "showing all elements\n";
			showStack(Myobj);
		}
		break;
		case '5':
		{
			if (Myobj.empty())
			{
				cout << "stack is empty\n";
			}
			else
			{
				cout << "stack is not empty\n";
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


