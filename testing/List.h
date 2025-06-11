#pragma once

template<typename Type>
class List
{
		
protected:
    Type* arr;
    int maxSize;
    int currentSize;
    Type* front;
    Type* last;





    Type* regrow() {
        maxSize *= 2;
        Type* newArr = new Type[maxSize];
        for (int i = 0; i < currentSize; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        return arr;
    }

public:
    virtual void addElement(Type element) = 0;
    virtual Type removeElement() = 0;








};

