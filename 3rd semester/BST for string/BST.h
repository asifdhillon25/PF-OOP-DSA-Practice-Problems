#pragma once
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Node
{
public:

	Node* left;
	Node* right;
	string Data;

	Node(string data) :left(nullptr), right(nullptr), Data(data)
	{

	}
};
class BST
{

	
public:
	bool isEmpty();
	
	BST() :root(nullptr) {}
	void inOrder();
    void postOrder();
    void preOrder();
	bool deleteNode(string Value);
	void printTreeHelper()
	{
		printTreeHelper(root, 0);
	}
	void printTreeHelper(Node* root, int space) {
		if (root != nullptr) {
			space += 10;
			printTreeHelper(root->right, space);
			std::cout << std::endl;
			for (int i = 10; i < space; i++)
				std::cout << " ";
			std::cout << root->Data << std::endl;
			printTreeHelper(root->left, space);
		}
	}

	void insert(string value);
	void makeEmpty();

private:
	Node* root;
	Node* makeEmptyRecursive(Node* node);
};

