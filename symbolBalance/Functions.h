#pragma once


bool checkSymbol(char tocheck, char symbolarr[], int arrsize = 6)
{
    for (int i = 0; i < arrsize; i++)
    {
        if (tocheck == symbolarr[i])

        {
            return true;
        }
    }

    return false;
}

bool isSymbolEqual(string Mystring, Stack <char>& Mystack, char symbolarr[])
{
    for (int i = 0; i < Mystring.size(); i++)
    {
        if (checkSymbol(Mystring[i], symbolarr))
        {
            Mystack.push(Mystring[i]);
        }
    }

    if (Mystack.size() % 2 == 0)
    {
        return true;
    }
    else
        return false;

}