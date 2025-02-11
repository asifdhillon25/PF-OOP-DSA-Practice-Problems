#pragma once
#include <iostream>
#include <cstdlib> // For system("pause") and system("cls")
#include <string>  // For using string type
#include <fstream>
using namespace std;

// ANSI escape codes for text color
constexpr auto  RED_TEXT = "\033[31m";
constexpr auto  Black_Text = "\033[30m";
constexpr auto RESET_COLOR = "\033[30m";
constexpr auto WHITE_COLOR = "\033[37m";




//enumeration for assigning color properties to nodes
enum Color { 
    RED, 
    BLACK };




//node class for mangaing node prppopeties
template<class Type>
class Node
{
public:
	Type Data;
    Color colour;
	Node<Type>* left;
	Node<Type>* right;
    Node<Type>* parent;
    unsigned int count;

    //constructor with initializerlist
	Node(Type value) :left(nullptr), right(nullptr), Data(value),colour(RED),parent(nullptr),count(1) {

	}
};


template<class Type>
class RedBlack
{
private:

    //function prototypes
    void inorder1(Node<Type>* node);
    void preorder1(Node<Type>* node);
    void postorder1(Node<Type>* node);
    void inorder2(Node<Type>* node);
    void preorder2(Node<Type>* node);
    void postorder2(Node<Type>* node);
    void DeleteDuplicate(Node<Type>* node);
    Node<Type>* insert(Node<Type>*, Type value);
    Node<Type>* rotateLeft(Node<Type>* node);
    Node<Type>* rotateRight(Node<Type>* node);
    void PrintNode(Node<Type>* node);
    Node<Type>* Search(Node<Type>* node, Type val, bool& flag);
    Node<Type>* DestroyTree(Node<Type>* node);

public:

    RedBlack();
    Node<Type>* root;

    //flag values for handling rotations
    bool LeftLeft; // Left-Left Rotation flag
    bool RightRight; // Right-Right Rotation flag
    bool LeftRight; // Left-Right Rotation flag
    bool RightLeft; // Right-Left Rotation flag


    //functions for public functions
    void MakeTreeFromFile();
    void PrintRoot();
    void insert(Type value);
    void inorder();
    void preorder();
    void postorder();
    void inorder2();
    void preorder2();
    void postorder2();
    bool Search(Type value);
    void DestroyTree();
    void DeleteDuplicate();
};

