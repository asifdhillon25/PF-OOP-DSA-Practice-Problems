#pragma once
#include "MyDoublyLinkedList.h"

template<typename Type>
class Stack
{
	MyDoublyLinkedList<Type> Mylist;
public:
	void Push(Type Value)
	{
		Mylist.insertAtFront(Value);
	}

	Type Pop()
	{
		return Mylist.removeFromFront();
	}

	Type Peek()
	{
		Type data=Pop();
		Push(data);
		return data;

	}


	void display()
	{
		Mylist.Display();
	}


};

