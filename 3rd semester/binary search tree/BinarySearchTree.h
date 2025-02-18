#pragma once
#include<iostream>
#include "Tree.h"
#include <algorithm> 
using namespace std;

template <class Type>
class Node
{
public:
    Type data;
    Node<Type>* left;
    Node<Type>* right;

    Node(Type value) : data(value), left(nullptr), right(nullptr) {}
};

template <class Type>
class BinarySearchTree : public Tree<Type>
{

private:

    Node<Type>* insertNode(Node<Type>* node, Type val);
    void inorderTraversal(Node<Type>* node);
    Node<Type>* findMin(Node<Type>* node);
    Node<Type>* deleteNode(Node<Type>* node, Type val, bool& flag);
   // Node<Type>* Search(Node<Type>* node, Type val, bool& flag);
    void inOrderTraversal(Node<Type>* node);
    void postOrderTraversal(Node<Type>* node);
    void preOrderTraversal(Node<Type>* node);
    void SumOfAllLessThanRoot(Node<Type>* node,  int& Data);
    void  divisibelBy2oR3(Node<Type>* node, int& count);
    int height(Node<Type>* node);
    void RightView(Node<Type>* node);
    void LeftView(Node<Type>* node);
    void nodeTypecount(Node<Type>* node, int& Onechild, int& Twochild, int& Nochild);
    void MirrorBst(Node<Type>* node);
   

public:


    Node<Type>* root;
    BinarySearchTree();
    void MirrorBst();

    void insertNode(Type val);
    void inorderTraversal();
  //  bool Search(Type val);
    bool deleteNode(Type val);
    void inOrderTraversal();
    void postOrderTraversal();
    void preOrderTraversal();
    int SumOfAllLessThanRoot();
    int divisibelBy2oR3();
    int height();
    void nodeTypecount();
    void RightView();
    void LeftView();
};

