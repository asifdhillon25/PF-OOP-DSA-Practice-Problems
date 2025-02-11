#include "RedBlack.h"

template<class Type>
void RedBlack<Type>::inorder1(Node<Type>* node)
{
	if (node == nullptr)
	{
		return;
	}
	inorder1(node->left);
	PrintNode(node);
	inorder1(node->right);
}

template<class Type>
void RedBlack<Type>::preorder1(Node<Type>* node)
{
	if (node == nullptr)
	{
		return;
	}
	PrintNode(node);
	preorder1(node->left);
	preorder1(node->right);
}

template<class Type>
void RedBlack<Type>::postorder1(Node<Type>* node)
{
	if (node == nullptr)
	{
		return;
	}
	postorder1(node->left);
	postorder1(node->right);
	PrintNode(node);
}

template<class Type>
void RedBlack<Type>::inorder2(Node<Type>* node)
{
	if (node == nullptr)
	{
		return;
	}

	inorder2(node->right);
	PrintNode(node);
	inorder2(node->left);
}

template<class Type>
void RedBlack<Type>::preorder2(Node<Type>* node)
{
	if (node == nullptr)
	{
		return;
	}
	PrintNode(node);
	preorder2(node->right);
	preorder2(node->left);
}

template<class Type>
void RedBlack<Type>::postorder2(Node<Type>* node)
{
	if (node == nullptr)
	{
		return;
	}

	postorder2(node->right);
	postorder2(node->left);
	PrintNode(node);
}

template<class Type>
void RedBlack<Type>::DeleteDuplicate(Node<Type>* node)
{


	if (node == nullptr)
	{
		return;
	}

	node->count = 1;
	DeleteDuplicate(node->right);
	DeleteDuplicate(node->left);


}


template<class Type>
Node<Type>* RedBlack<Type>::insert(Node<Type>* node, Type value)
{


	bool flag = false;

	if (node == nullptr)
	{
		Node<Type>* newnode = new Node<Type>(value);
		
		node = newnode;

	}
	else if (value < node->Data)
	{
		node->left = insert(node->left, value);
		node->left->parent = node;
		if (node != this->root)
		{
			if (node->colour == RED && node->left->colour == RED)
				flag = true;
		}
	}
	else if(value > node->Data){
		node->right = insert(node->right, value);
		node->right->parent = node;
		if (node != this->root) {
			if (node->colour == RED && node->right->colour == RED)
				flag = true;
		}

	}
	else
	{
		
		// Duplicate value, decide what action to take (e.g., ignore or update existing node)
		// For now, ignoring duplicate values
		std::cout << "Duplicate value: " << value << ". Increasing count" << std::endl;
		node->count++;
		return node;
	}
	


	// Perform rotations
	if (LeftLeft) {
		node = rotateLeft(node);
		node->colour = BLACK;
		node->left->colour = RED;
		LeftLeft = false;
	}
	else if (RightRight) {
		node = rotateRight(node);
		node->colour = BLACK;
		node->right->colour = RED;
		RightRight = false;
	}
	else if (RightLeft) {
		node->right = rotateRight(node->right);
		node->right->parent = node;
		node = rotateLeft(node);
		node->colour = BLACK;
		node->left->colour = RED;
		RightLeft = false;
	}
	else if (LeftRight) {
		node->left = rotateLeft(node->left);
		node->left->parent = node;
		node = rotateRight(node);
		node->colour = BLACK;
		node->right->colour = RED;
		LeftRight = false;
	}

	// Handle RED-RED conflicts
	if (flag) {
		if (node->parent->right == node) {
			if (node->parent->left == nullptr || node->parent->left->colour == BLACK) {
				if (node->left != nullptr && node->left->colour == RED)
					RightLeft = true;
				else if (node->right != nullptr && node->right->colour == RED)
					LeftLeft = true;
			}
			else {
				node->parent->left->colour = BLACK;
				node->colour = BLACK;
				if (node->parent != this->root)
					node->parent->colour = RED;
			}
		}
		else {
			if (node->parent->right == nullptr || node->parent->right->colour == BLACK) {
				if (node->left != nullptr && node->left->colour == RED)
					RightRight = true;
				else if (node->right != nullptr && node->right->colour == RED)
					LeftRight = true;
			}
			else {
				node->parent->right->colour = BLACK;
				node->colour = BLACK;
				if (node->parent != this->root)
					node->parent->colour = RED;
			}
		}
		flag = false;
	}
	return node;


}

template<class Type>
Node<Type>* RedBlack<Type>::rotateLeft(Node<Type>* node) {
	Node<Type>* x = node->right;
	Node<Type>* y = x->left;
	x->left = node;
	node->right = y;
	node->parent = x;
	if (y != nullptr)
		y->parent = node;
	return x;
}

template<class Type>
 Node<Type>* RedBlack<Type>::rotateRight(Node<Type>* node) {
	Node<Type>* x = node->left;
	Node<Type>* y = x->right;
	x->right = node;
	node->left = y;
	node->parent = x;
	if (y != nullptr)
		y->parent = node;
	return x;
}

 template<class Type>
 void RedBlack<Type>::PrintNode(Node<Type>* node)
 {
	 if (node->colour == RED)
	 {
		 cout << RED_TEXT << node->Data << " " << RESET_COLOR ;
	 }
	 else 
	 {
		 cout << Black_Text << node->Data << " " << RESET_COLOR ;
	 }
 }

template<class Type>
RedBlack<Type>::RedBlack():root(nullptr),LeftLeft(false),
RightRight(false),LeftRight(false),RightLeft(false)
{

}

template<class Type>
void RedBlack<Type>::MakeTreeFromFile()
{

	ifstream inputFile("input.txt");
	if (!inputFile.is_open()) {
		cerr << "Error opening file: " << endl;
		return;
	}
	int value;
	while (inputFile >> value)
	{
		insert(value);
	}
}

template<class Type>
void RedBlack<Type>::PrintRoot()
{
	if (root != nullptr)
	{
		PrintNode(root);
	}
	
}

template<class Type>
void RedBlack<Type>::insert(Type value)
{
	if (root == nullptr)
	{
		root = new Node<Type>(value);
		root->colour = BLACK;
	}
	else
	{
		root=insert(root, value);
	}
	
}

template<class Type>
void RedBlack<Type>::inorder()
{
	inorder1(root);
}

template<class Type>
void RedBlack<Type>::preorder()
{
	preorder1(root);
}

template<class Type>
void RedBlack<Type>::postorder()
{
	postorder1(root);
}

template<class Type>
void RedBlack<Type>::inorder2()
{
	inorder2(root);
}

template<class Type>
void RedBlack<Type>::preorder2()
{
	preorder2(root);
}

template<class Type>
void RedBlack<Type>::postorder2()
{
	postorder2(root);
}

template<class Type>
bool RedBlack<Type>::Search(Type value)
{
	bool flag = false;
	   Search(root, value, flag);
	   return flag;
}

template<class Type>
void RedBlack<Type>::DestroyTree()
{
	root = DestroyTree(root);
}

template<class Type>
void RedBlack<Type>::DeleteDuplicate()
{
	DeleteDuplicate(root);
}



template<class Type>
Node<Type>* RedBlack<Type>::Search(Node<Type>* node, Type val, bool& flag)
{
    // Base case: if the node is null
    if (node == nullptr)
    {
        flag = false;
        return nullptr;
    }

    // If the value is greater, search in the right 
    if (val > node->Data)
    {
        return Search(node->right, val, flag);
    }

    // If the value is smaller, search in the left 
    if (val < node->Data)
    {
        return Search(node->left, val, flag);
    }

    // If the value is found
    flag = true;
    return node;
}

template<class Type>
Node<Type>* RedBlack<Type>::DestroyTree(Node<Type>* node)
{
	if (node == nullptr) {
		return nullptr;
	}

	
	DestroyTree(node->left);
	DestroyTree(node->right);

	// Delete the node
	delete node;

	return nullptr;

}
