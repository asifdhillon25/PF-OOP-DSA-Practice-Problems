#pragma once
#include<iostream>
#include "unorderedLinkedList.h"
#include "dvdType.h"

#include "linkedlist.h"
#include <string>
using namespace std;

class dvdListType:public unorderedLinkedList<dvdType>
{
public:
	bool dvdSearch(string title)const;
	bool isDVDAvailable(string title)const;
	void dvdCheckOut(string title);
	void dvdCheckIn(string title);
	bool dvdCheckTitle(string title) const;
	void dvdUpdateInStock(string title, int num);
	void dvdSetCopiesInStock(string title, int num);
	void dvdPrintTitle() const;
private:
	void searchDVDList(string title, bool& found,
		nodeType<dvdType>*& current) const;
	
};


