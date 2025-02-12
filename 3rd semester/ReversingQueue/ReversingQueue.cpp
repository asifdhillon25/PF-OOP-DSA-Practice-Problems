
#include <iostream>
#include "Queue.h"
#include "Functions.h"

int main()
{
    Queue<int> Myqueue;
    initializeQueue(Myqueue);
    cout << "***Printing Queue***\n";
    ShowQueue(Myqueue);


    cout << "Enter number to which extent you want to reverse the Queue\n";
    int num; cin >> num;
    reverseFirstK(num, Myqueue);

    cout << "\nShowing Queue After Reversing Elements\n";
    ShowQueue(Myqueue);


    system("pause");
}
