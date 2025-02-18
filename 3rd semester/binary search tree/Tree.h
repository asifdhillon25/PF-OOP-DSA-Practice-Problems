#pragma once

template <class Type>
class Tree
{

public:
	Tree();
	virtual void insertNode(Type) = 0;
	virtual bool deleteNode(Type) = 0; 
};


