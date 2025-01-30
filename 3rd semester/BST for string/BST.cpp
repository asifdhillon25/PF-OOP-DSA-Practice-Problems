#include "BST.h"

void BST::insert(string value) {
	Node* newNode = new Node(value);

	if (root == nullptr) {
		root = newNode;
		return;
	}

	Node* current = root;
	Node* parent = nullptr;

	while (current != nullptr) {
		parent = current;

		if (value < current->Data) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	if (value < parent->Data) {
		parent->left = newNode;
	}
	else {
		parent->right = newNode;
	}
}

void BST::makeEmpty() {
	root = makeEmptyRecursive(root);
}

Node* BST::makeEmptyRecursive(Node* node) {
	if (node == nullptr) {
		return nullptr;
	}

	// Post-order traversal
	makeEmptyRecursive(node->left);
	makeEmptyRecursive(node->right);

	// Delete the node
	delete node;

	return nullptr;
}

bool BST::deleteNode(string Value)
{
	if (root == nullptr)
	{
		// Tree is empty
		return false;
	}

	Node* current = root;
	Node* parent = nullptr;

	// Search for the node to delete
	while (current != nullptr && current->Data != Value)
	{
		parent = current;

		if (current->Data > Value)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	if (current == nullptr)
	{
		// Node with the specified value not found
		return false;
	}

	// Case 1: Node to be deleted has no children
	if (current->left == nullptr && current->right == nullptr)
	{
		if (parent == nullptr)
		{
			// Deleting the root node
			delete root;
			root = nullptr;
		}
		else
		{
			// Deleting a non-root node
			if (parent->left == current)
			{
				parent->left = nullptr;
			}
			else
			{
				parent->right = nullptr;
			}

			delete current;
		}
	}
	// Case 2: Node to be deleted has one child
	else if (current->left == nullptr || current->right == nullptr)
	{
		Node* child = (current->left != nullptr) ? current->left : current->right;

		if (parent == nullptr)
		{
			// Deleting the root node with one child
			delete root;
			root = child;
		}
		else
		{
			// Deleting a non-root node with one child
			if (parent->left == current)
			{
				parent->left = child;
			}
			else
			{
				parent->right = child;
			}

			delete current;
		}
	}
	// Case 3: Node to be deleted has two children
	else
	{
		// Find the in-order successor (smallest node in the right subtree)
		Node* successorParent = current;
		Node* successor = current->right;

		while (successor->left != nullptr)
		{
			successorParent = successor;
			successor = successor->left;
		}

		// Copy the value of the in-order successor to the current node
		current->Data = successor->Data;

		if (successorParent->left == successor)
		{
			successorParent->left = successor->right;
		}
		else
		{
			successorParent->right = successor->right;
		}

		delete successor;
	}
	return true;
}

bool BST::isEmpty()
{
	return (root == nullptr);
}

void BST::inOrder()
{
	stack<Node*> s;
	Node* current = root;

	while (current != nullptr || !s.empty())
	{
		while (current != nullptr)
		{
			s.push(current);
			current = current->left;
		}

		current = s.top();
		s.pop();

		cout << current->Data << " ";

		current = current->right;
	}
}

void BST::preOrder() {
	stack<Node*> s;
	Node* current = root;

	while (current != nullptr || !s.empty()) {
		while (current != nullptr) {
			cout << current->Data << " ";
			s.push(current);
			current = current->left;
		}

		current = s.top();
		s.pop();

		current = current->right;
	}
}

void BST::postOrder() {
	stack<Node*> s1, s2;
	s1.push(root);

	while (!s1.empty()) {
		Node* current = s1.top();
		s1.pop();
		s2.push(current);

		if (current->left != nullptr) {
			s1.push(current->left);
		}
		if (current->right != nullptr) {
			s1.push(current->right);
		}
	}

	while (!s2.empty()) {
		cout << s2.top()->Data << " ";
		s2.pop();
	}
}
