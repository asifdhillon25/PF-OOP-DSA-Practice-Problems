#include <iostream>
#include "Queue.h"
using namespace std;

void display(Queue <int> myQ)
{



	while (!myQ.empty())
	{
		cout << myQ.dequeue() << " ";
	}

	cout << endl;
}


Queue<int> reverseQueue(Queue<int> myobj)
{

	Queue<int> temp1(myobj);
	Queue<int> temp2;

	for (int i = 0; i < myobj.size(); i++)
	{
		temp1 = myobj;
		for (int j = 1; j < myobj.size() - i; j++)
		{

			temp1.dequeue();
		}


		display(temp1);
		cout << endl;

		if (!temp1.empty())
		{
			temp2.enqueue(temp1.dequeue());
		}
	}

	return temp2;
}




int main()
{

	Queue <int> myobj;

	for (int i = 1; i <= 5; i++)
	{
		myobj.enqueue(i);
	}


	cout << "before" << endl;
	display(myobj);

	myobj = reverseQueue(myobj);
	cout << "after " << endl;
	display(myobj);


}