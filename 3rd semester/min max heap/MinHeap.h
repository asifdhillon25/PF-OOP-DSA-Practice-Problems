#pragma once
#include <iostream>
using namespace std;
#include "Heap.h"
class MinHeap:public Heap
{
		int* arr;
		int capacity;
		int current;

public:

	MinHeap()
	{
		current = 1;
		capacity = 10;
		arr = new int[capacity];
	}


	int* regrow() {
		capacity *= 2;
		int* newArr = new int[capacity];
		for (int i = 1; i < current-1; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		return arr;
	}

	bool empty()
	{
		return current <= 1 ? true : false;
	}


	bool full()
	{
		return(current == capacity);
	}

	void insert(int data)
	{
		if (full())
		{
			regrow();
		}

		if (current == 1)
		{
			arr[current] = data;
			current++;
		}
		else
		{
			int parentindex = current / 2;
			int parentdata = arr[parentindex];

			if (parentdata > data)
			{
				arr[current] = parentdata;
				arr[parentindex] = data;
				current++;

			}
			else
			{
				arr[current] = data;
				current++;
			}
			
		}


	}

	int getMin()
	{	
		if (!empty())
		{
			return arr[1];
		}
		else
		{
			cerr << "empty list\n";
		}
	}

	void Print()
	{
		if (!empty())
		{
			for (int i = 1; i < current ; i++)
			{
				cout << arr[i]<<" ";
			}
		}
	}

};

