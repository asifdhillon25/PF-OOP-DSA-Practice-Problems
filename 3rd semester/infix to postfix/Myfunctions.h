#pragma once
#include <iostream>
#include "Stack.h"
#include "string"



bool operatorsCheck(char arr[], char tocheck, int arrsize = 4)
{
    for (int i = 0; i < arrsize; i++)
    {
        if (tocheck == arr[i])
        {
            return true;
        }

    }

    return false;
}

bool StackCheck(char ch, Stack<char> stc, char arr[], int arrsize = 4)
{
    int temp, stTemp;

    for (int i = 0; i < arrsize; i++)
    {
        if (ch == arr[i])
        {
            temp = i;
        }
        if (stc.peek() == arr[i])
        {
            stTemp = i;
        }
    }
    
    if (temp <= stTemp)
    {
        return true;
    }
    else
    {
        return false;
    }


}


string CalculatePostfix(string exp, Stack<char> StackAprnd, char operators[], int arrsize = 4)
{
    string output;

    for (int i = 0; i < exp.size(); i++)//
    {


        if (exp[i] == ')') 
        {

            if (StackAprnd.empty())
            {
                cout << "stack is empty\n";
            }
            else
            {
                output += StackAprnd.pop();
                StackAprnd.pop();
            }

        }
        else if (exp[i] == '(')
        {
            StackAprnd.push(exp[i]);
        }
        else
        {
            if (!operatorsCheck(operators, exp[i]))
            {
                output.push_back(exp[i]);

            }
            else
            {
                if (!StackAprnd.empty() && StackAprnd.peek()!='(' && StackAprnd.peek() != ')')
                {
                    if (StackCheck(exp[i], StackAprnd, operators))
                    {

                        output += StackAprnd.pop();
                        StackAprnd.push(exp[i]);

                    }
                    else
                    {
                        StackAprnd.push(exp[i]);
                    }
                }
                else
                {
                    StackAprnd.push(exp[i]);
                }


            }
        }
      


    }



    if (!StackAprnd.empty())
    {
        for (int i = 0; i < StackAprnd.size() + 1; i++)
        {
            output += StackAprnd.pop();

        }
    }
    

    return output;


}