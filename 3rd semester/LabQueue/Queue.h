#pragma once
#include <iostream>
#include "List.h"
using namespace std;


template<typename Type>
class Queue:public List<Type>
{

public:

	Queue()
	{
		this->maxSize = 1;
		this->currentSize = 0;
		this->arr = new Type[this->maxSize];
	}


	Queue(const Queue& s) {
		this->maxSize = s.maxSize;
		this->currentSize = s.currentSize;
		this->arr = new Type[this->maxSize];
		for (int i = 0; i < this->currentSize; i++) {
			this->arr[i] = s.arr[i];
		}
	}


	int size()
	{
		return this->currentSize;
	}

	void enqueue(Type element)
	{
		addElement(element);
	}

	Type dequeue()
	{
		return removeElement();

	}
		
	bool empty()
		{
			if (this->currentSize <= 0)
			{
				return true;
			}
			return false;
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

			if (empty())
			{
				this->arr[this->currentSize] = element;
				this->currentSize++;
			}
			else
			{
				
				Rotate(this->arr, this->currentSize);
				this->currentSize++;
				this->arr[0] = element;
			}
		
		}



		void Rotate(Type arr[], int curntsize)
		{
			for (int i = curntsize; i >= 0; i--)
			{
				arr[i] = arr[i - 1];
			}
			
		}

};

