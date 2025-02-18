#include "BinarySearchTree.h"


template<class Type>
BinarySearchTree<Type>::BinarySearchTree() : root(nullptr) {}

template<class Type>
void BinarySearchTree<Type>::MirrorBst()
{
    MirrorBst(root);
}

template<class Type>
Node<Type>* BinarySearchTree<Type>::insertNode(Node<Type>* node, Type val) {
    if (node == nullptr) {
        Node<Type>* newnode = new  Node<Type>(val);
        return newnode;
    }

    if (val < node->data) {
        node->left = insertNode(node->left, val);
    }
    else if (val > node->data) {
        node->right = insertNode(node->right, val);
    }

    return node;
}

template<class Type>
void BinarySearchTree<Type>::inorderTraversal(Node<Type>* node) {
    if (node != nullptr) {
        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }
}

template<class Type>
Node<Type>* BinarySearchTree<Type>::findMin(Node<Type>* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template<class Type>
Node<Type>* BinarySearchTree<Type>::deleteNode(Node<Type>* node, Type val, bool& flag) {
    if (node == nullptr) {
        flag = false;
        return node;
    }

    if (val < node->data) {
        node->left = deleteNode(node->left, val, flag);
    }
    else if (val > node->data) {
        node->right = deleteNode(node->right, val, flag);
    }
    else {
        // Node with only one child or no child
        if (node->left == nullptr) {
            Node<Type>* temp = node->right;
            delete node;
            flag = true;
            return temp;
        }
        else if (node->right == nullptr) {
            Node<Type>* temp = node->left;
            delete node;
            flag = true;
            return temp;
        }

        // Node with two children
        Node<Type>* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data, flag);
    }

    return node;
}
//template<class Type>
//Node<Type>* BinarySearchTree<Type>::Search(Node<Type>* node, Type val, bool& flag)
//{
//    // Base case: if the node is null
//    if (node == nullptr)
//    {
//        flag = false;
//        return nullptr;
//    }
//
//    // If the value is greater, search in the right 
//    if (val > node->data)
//    {
//        return Search(node->right, val, flag);
//    }
//
//    // If the value is smaller, search in the left 
//    if (val < node->data)
//    {
//        return Search(node->left, val, flag);
//    }
//
//    // If the value is found
//    flag = true;
//    return node;
//}

template<class Type>
void BinarySearchTree<Type>::preOrderTraversal(Node<Type>* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

template<class Type>
void BinarySearchTree<Type>::SumOfAllLessThanRoot(Node<Type>* node ,int& Data)
{
   
    if (node != nullptr) {
        Data += node->data;
        SumOfAllLessThanRoot(node->left,Data);
        SumOfAllLessThanRoot(node->right,Data);
    }
  

}

template<class Type>
void BinarySearchTree<Type>::divisibelBy2oR3(Node<Type>* node, int& count)
{

    if (node != nullptr) {


        if (node->data % 3 == 0 || node->data % 2 == 0)
        {
            count++;
        }
        divisibelBy2oR3(node->left, count);
        divisibelBy2oR3(node->right, count);
    }
}

template<class Type>
int BinarySearchTree<Type>::height(Node<Type>* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    return 1 + std::max(height(node->left), height(node->right));
}

template<class Type>
void BinarySearchTree<Type>::RightView(Node<Type>* node)
{
    if (node != nullptr)
    {
        cout << node->data << " ";
        RightView(node->right);
    }

    
}

template<class Type>
void BinarySearchTree<Type>::LeftView(Node<Type>* node)
{
    if (node != nullptr)
    {
        cout << node->data << " ";
        LeftView(node->left);
    }
}


template<class Type>
void BinarySearchTree<Type>::nodeTypecount(Node<Type>* node, int& Onechild, int& Twochild, int& Nochild)
{
    if (node != nullptr) {
        if (node->left == nullptr && node->right == nullptr) {
            Nochild++;
        }
        else if (node->left != nullptr && node->right != nullptr) {
            Twochild++;
        }
        else {
            Onechild++;
        }

        nodeTypecount(node->left, Onechild, Twochild, Nochild);
        nodeTypecount(node->right, Onechild, Twochild, Nochild);
    }
}

template<class Type>
void BinarySearchTree<Type>::MirrorBst(Node<Type>* node)
{
    if (node != nullptr)
    {
        Node<Type>* temp = node->right;
        node->right = node->left;
        node->left = temp;

        MirrorBst(node->left);
        MirrorBst(node->right);
    }

}




template<class Type>
void BinarySearchTree<Type>::inOrderTraversal(Node<Type>* node) {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
}

template<class Type>
void BinarySearchTree<Type>::postOrderTraversal(Node<Type>* node) {
    if (node != nullptr) {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }
}






template<class Type>
void BinarySearchTree<Type>::insertNode(Type val) {
    root = insertNode(root, val);
}

template<class Type>
void BinarySearchTree<Type>::inorderTraversal() {
    inorderTraversal(root);
    cout << endl;
}

//template<class Type>
//bool BinarySearchTree<Type>::Search(Type val)
//{
//    bool flag = false;
//    Search(root, val, flag);
//    return flag;
//
//}

template<class Type>
bool BinarySearchTree<Type>::deleteNode(Type val) {

    bool flag = false;
    root = deleteNode(root, val, flag);
    return flag;

}

template<class Type>
void BinarySearchTree<Type>::preOrderTraversal() {
    preOrderTraversal(root);
    cout << endl;
}

template<class Type>
int BinarySearchTree<Type>::SumOfAllLessThanRoot()
{
    int Data = 0;
    SumOfAllLessThanRoot(root->left, Data);

    return Data;
}

template<class Type>
int BinarySearchTree<Type>::divisibelBy2oR3()
{
    int count = 0;
    divisibelBy2oR3(root, count);

    return count;
}

template<class Type>
int BinarySearchTree<Type>::height()
{
    return height(root);
}

template<class Type>
void BinarySearchTree<Type>::nodeTypecount()
{
    int OneChild = 0;
    int TwoChild = 0;
    int NoChild = 0;

        
        nodeTypecount(root, OneChild, TwoChild, NoChild);

    cout << "\n";
    cout << "No of One Child: " << OneChild << "\n";
    cout << "No of Two Child: " << TwoChild << "\n";
    cout << "No of No Child: " << NoChild << "\n";

}

template<class Type>
void BinarySearchTree<Type>::RightView()
{
    RightView(root);
}

template<class Type>
void BinarySearchTree<Type>::LeftView()
{
    LeftView(root);
}

template<class Type>
void BinarySearchTree<Type>::inOrderTraversal() {
    inOrderTraversal(root);
    cout << endl;
}

template<class Type>
void BinarySearchTree<Type>::postOrderTraversal() {
    postOrderTraversal(root);
    cout << endl;
}