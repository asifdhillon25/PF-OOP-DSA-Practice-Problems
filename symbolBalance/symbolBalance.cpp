
#include <iostream>
#include "Stack.h"
#include <string>
#include "Functions.h"


int main()
{
    Stack <char> MyStack;
    string MyString;
    char SymbolArr[] = { '(',')','{','}','[',']' };
    
    cout << "********Application - Balancing Symbols **********\n\n";
    cout << "Enter eqution to check if its symbols balanced or not\n";
    cin >> MyString;

    if (isSymbolEqual(MyString, MyStack, SymbolArr))
    {
        cout << "\n\n\aEquation Has Balnced No of Symbols\n";
    }
    else
    {
        cout << "No of Symbols Are not Balanced\n";
    }

    system("pause");
}
