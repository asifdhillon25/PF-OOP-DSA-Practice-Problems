// vectortest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool g6(int element)
{
    return element < 5;
}
int main()
{
    std::cout << "Hello World!\n";

    vector <int> myvect;


    for (int i=0;i<10;i++)
    {
        myvect.push_back(i);
    }


    for (auto& i : myvect)
    {
        cout << i<<" ";
    }

    auto g5 = [](int element) {return element > 5; };
   

    myvect.erase(std::remove_if(myvect.begin(), myvect.end(), g6), myvect.end());
    //myvect.erase(std::remove_if(myvect.begin(), myvect.end(), isGreaterThan5), myvect.end());
    cout << "after lambda\n\n";
    for (auto& i : myvect)
    {
        cout << i << " ";
    }

    // std::string message = "Hello, C++!";

    //// Using auto in a range-based for loop to iterate over characters in a string
    //for (const auto& c : message) {
    //    std::cout << c << " ";
    //}

   
}
