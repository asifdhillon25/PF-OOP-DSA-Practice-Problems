#pragma once



template<typename Type>
class DoublyLinkList
{
	

public:

		virtual void insertAtFront(Type) = 0;
		virtual void insertAtEnd(Type) = 0;
		virtual Type removeFromFront() = 0;
		virtual Type removeFromEnd() = 0;

};

