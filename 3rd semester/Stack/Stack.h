#pragma once
#include <iostream>
#include "List.h"
using namespace std;


template<typename Type>
class Stack:public List<Type>
{
public:

	Stack()
	{
		this->currentSize = 0;
		this->maxSize = 1;
		this->arr = new Type[this->maxSize];
	}

	Stack(const Stack& s) {
		this->maxSize = s.maxSize;
		this->currentSize = s.currentSize;
		this->arr = new Type[this->maxSize];
		for (int i = 0; i < this->currentSize; i++) {
			this->arr[i] = s.arr[i];
		}
	}

	


	bool empty()
	{
		if (this->currentSize <= 0)
		{
			return true;
		}
		return false;
	}


	int size()
	{
		return this->currentSize;
	}
		
	Type peek()
	{
		if (!empty())
		{
			return this->arr[this->currentSize - 1];

		}
		throw out_of_range("Stack is empty");
	}

	void push(Type element)
	{
		addElement(element);
		

	}
	
	Type pop()
	{
		
		return removeElement();
	}



	Type removeElement()
	{
		if (!empty())
		{
			this->currentSize--;
			return this->arr[this->currentSize];
			

		}

		throw out_of_range("Stack is empty");
	}


	bool full()
	{
		return (this->currentSize == this->maxSize);
	}

	void addElement(Type element)
	{
	
		
		if (full())
		{
			this->regrow();
		}
		this->arr[this->currentSize] = element;
		
		this->currentSize++;

	}


	
		
};

