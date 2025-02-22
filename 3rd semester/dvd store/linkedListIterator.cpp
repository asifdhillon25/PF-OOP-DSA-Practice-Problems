#include "linkedListIterator.h"


template<class Type>
inline linkedListIterator<Type>::linkedListIterator()
{
	current = nullptr;
}

template<class Type>
inline linkedListIterator<Type>::linkedListIterator(nodeType<Type>* ptr)
{
	current = ptr;
}

template<class Type>
inline Type linkedListIterator<Type>::operator*()
{
	return current->info;
}

template<class Type>
inline linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
	current = current->link;
	return *this;
}

template<class Type>
inline bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
{
	return (current==right.current);
}

template<class Type>
inline bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const
{
	return false;
}
