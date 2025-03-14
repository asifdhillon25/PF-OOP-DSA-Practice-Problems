#pragma once
#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

template<typename Type>
class Node
{
public:
	Type Data;
	Node<Type>* next;
	Node(Type Value) :Data(Value), next(nullptr) {}
};


template<typename Type>
class MySinglyLinkedList:public SinglyLinkedList<Type>
{
	Node<Type>* Head;
public:

	void insertAtFront(Type value)
	{
		Node<Type>* newnode = new Node<Type>(value);
		newnode->next = Head;
		Head = newnode;
	}

	void insertAtEnd(Type value)
	{
		Node<Type>* newnode = new Node<Type>(value);
		if (Head == nullptr)
		{
			Head = newnode;
		}
		else
		{
			Node<Type>* current = Head;
			while (current ->next!= nullptr)
			{
				current = current->next;
			}
			current->next = newnode;
		}


	}
	Type removeFromFront()
	{
		if (Head == nullptr)
		{
			cerr << "llist is empty\n";
		}
		

		if (Head->next == nullptr) {
			// If there is only one node in the list
			Type data = Head->Data;
			delete Head;
			Head = nullptr;
			return data;
		}

		if (Head != nullptr)
		{
			Node<Type>* temp = Head;
			Head = Head->next;
			Type data = temp->Data;
			delete temp;
			return data;
		}
		
		
	}
	Type removeFromEnd()
	{
		if (Head != nullptr)
		{
			Node<Type>* temp = Head;
			while (temp->next->next!= nullptr)
			{
				temp = temp->next;
			}
			
			Type data = temp->next->Data;
			delete temp->next;
			temp->next = nullptr;
			return data;
		}

		cerr << "llist is empty\n";
	}
	bool insertAt(int index, Type value)
	{

		if (index < 0)
		{
			cout << "invalid index\n";
			return false;
		}

		Node* newnode = new Node<Type>(value);
		
		if (index == 0)
		{
			newnode->next = Head;
			Head = newnode;
			return true;
		}



		Node<Type>* current = Head;
		int currentIndex = 0;

		while (current != nullptr && currentIndex < index - 1) {
			current = current->next;
			currentIndex++;
		}

		// Check if the index is out of bounds
		if (current == nullptr) {
			cout << "Invalid index. Index exceeds the size of the list." << endl;
			delete newnode;
			return false;
		}

		// Insert the new node at the specified index
		newnode->next = current->next;
		current->next = newnode;

		return true;
	}


	bool Search(Type value)
	{
		
		if(Head==nullptr)
		{
			return false;
		}

		Node<Type>* current = Head;
		while (current != nullptr)
		{
			if (current->Data == value)
			{
				return true;

			}

			current = current->next;
		}

		return false;

	}
	void Display()
	{
		Node<Type>* current = Head;
		while (current != nullptr) {
			cout << current->Data << " ";
			current = current->next;
		}
		cout << endl;
	}

};

