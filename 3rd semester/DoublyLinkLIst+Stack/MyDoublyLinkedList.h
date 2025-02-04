#pragma once
#include "DoublyLinkList.h"
#include <iostream>
using namespace std;

template<typename Type>
class Node
{
public:
	Type Data;
	Node<Type>* next;
	Node<Type>* prev;
	Node(Type Value) :Data(Value), next(nullptr),prev(nullptr) {}
};


template<typename Type>
class MyDoublyLinkedList :public DoublyLinkList<Type>
{
	Node<Type>* Head;
public:

	MyDoublyLinkedList() :Head(nullptr){}

	void insertAtFront(Type value)
	{
		Node<Type>* newnode = new Node<Type>(value);
		newnode->next = Head;
		if (Head != nullptr)
		{
			Head->prev = newnode;
		}
		
		Head = newnode;
		Head->prev = nullptr;
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
			newnode->prev = current;
			current->next = newnode;
		}


	}


	Type removeFromFront()
	{
		if (Head == nullptr)
		{
			cerr << "list is empty\n";
		}
		

		if (Head->next == nullptr) {
			//If there is only one node in the list
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
			temp = nullptr;
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

		Node<Type>* newnode = new Node<Type>(value);
		
		if (index == 0)
		{
			newnode->next = Head;
			if (Head != nullptr)
			{
				Head->prev = newnode;
			}
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
		current->next->prev = newnode;
		newnode->prev = current;
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


	Type getTotalSum()
	{
		Type sum = 0;
		Node<Type>* current = Head;

		while (current != nullptr)
		{
			sum += current->Data;
			current = current->next;
		}

		return sum;
	}

	void ReverseList()
	{
		Node<Type>* current = Head;
		Node<Type>* temp = nullptr;

		while (current != nullptr)
		{
			// Swap next and prev pointers of the current node
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;

			// Move to the next node
			current = current->prev;
		}

		// Update the head pointer to the last node (new first node after reversal)
		if (temp != nullptr)
		{
			Head = temp->prev;
		}
	}

	void removeDuplicates()
	{
		Node<Type>* current = Head;

		while (current != nullptr)
		{
			Node<Type>* temp = current;

			while (temp->next != nullptr)
			{
				if (current->Data == temp->next->Data)
				{
					Node<Type>* duplicate = temp->next;
					temp->next = temp->next->next;

					// Update the prev pointer of the next node, if it exists
					if (temp->next != nullptr)
					{
						temp->next->prev = temp;
					}

					delete duplicate;
				}
				else
				{
					temp = temp->next;
				}
			}

			current = current->next;
		}
	}


	void ShuffleMerge(MyDoublyLinkedList<Type>& other)
	{
		Node<Type>* current1 = Head;
		Node<Type>* current2 = other.Head;

		while (current1 != nullptr && current2 != nullptr)
		{
			Node<Type>* temp1 = current1->next;
			Node<Type>* temp2 = current2->next;

			current1->next = current2;
			current2->prev = current1;
			current2->next = temp1;

			if (temp1 != nullptr) {
				temp1->prev = current2;
			}

			current1 = temp1;
			current2 = temp2;
		}

		// it will continue taking nodes from the other list
		if (current1 == nullptr && current2 != nullptr)
		{
			while (current2 != nullptr)
			{
				Node<Type>* temp = current2->next;
				current2->next = nullptr;
				current2->prev = nullptr;
				insertAtEnd(current2->Data); 
				delete current2;
				current2 = temp;
			}
		}
		else if (current1 != nullptr && current2 == nullptr)
		{
			while (current1 != nullptr)
			{
				Node<Type>* temp = current1->next;
				current1->next = nullptr;
				current1->prev = nullptr;
				insertAtEnd(current1->Data); 
				delete current1;
				current1 = temp;
			}
		}

		// Empty  other list
		other.Head = nullptr;
	}

};

