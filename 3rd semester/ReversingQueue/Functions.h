#pragma once
#include <iostream>
#include "Queue.h"

void reverseFirstK(int k, Queue<int>& Myqueue)
{
    Queue<int> temp;
    if (!(k > Myqueue.size()))
    {
        for (int i = 0; i < k; i++)
        {
            temp.enqueue(Myqueue.dequeue());
            Myqueue.enqueue(temp.dequeue());
        }
    }
    else
    {
        cout << "your Number is Greater than Queue Size\n";
    }


}

void ShowQueue(Queue<int> myqueue)
{
    while (!myqueue.empty())
    {
        cout << myqueue.dequeue() << " ";
    }
    cout << endl;
}

void initializeQueue(Queue<int>& Myqueue)
{
    for (int i = 1; i <= 10; i++)
    {
        Myqueue.enqueue(i);
    }
}