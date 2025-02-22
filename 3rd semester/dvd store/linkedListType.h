#pragma once
#include "linkedListIterator.h"
template <class Type>
class linkedListType
{

public:
	int count;
	nodeType<Type>* first;
	nodeType<Type>* last;
	nodeType<Type>* current;

	const linkedListType<Type>& operator=
		(const linkedListType<Type>&);
	void initializeList();
	bool isEmptyList() const;
	void print() const;
	int length() const;
	void destroyList();
	Type front() const;
	Type back() const;
	virtual bool search( Type& searchItem)  = 0;
	virtual void insertFirst(const Type& newItem) = 0;
	virtual void insertLast(const Type& newItem) = 0;
	virtual void deleteNode(const Type& deleteItem) = 0;
	linkedListIterator<Type> begin();
	linkedListIterator<Type> end();
	linkedListType();
	~linkedListType();
	linkedListType(linkedListType<Type>& otherList);

linkedListType(const linkedListType<Type>& otherList);

	
private:
	void copyList(const linkedListType<Type>& otherList);
};

