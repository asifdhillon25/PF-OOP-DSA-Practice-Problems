#pragma once

#include "MySinglyLinkedList.h"
#include <iostream>
using namespace std;


template<typename Type>
class Queue
{
	MySinglyLinkedList<Type> MyList;
public:

	void enqueue(Type Value)
	{
		MyList.insertAtFront(Value);
	}
	Type dequeue()
	{
		return MyList.removeFromEnd();
	 }
	Type Peek()
	{
		Type Data = MyList.removeFromEnd();
		MyList.insertAtEnd(Data);
		return Data;

	}
		
	void display()
	{
		MyList.Display();
		}


};

