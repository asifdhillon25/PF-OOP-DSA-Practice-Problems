
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//You are given an integer array prices representing the prices of various 
//chocolates in a store.You are also given a single integer money, which 
//represents your initial amount of money.
//
//You must buy exactly two chocolates in such a way that you still 
//have some non - negative leftover money.You would like to minimize the sum of the prices of the two chocolates you buy.
//
//Return the amount of money you will have leftover after buying the
//two chocolates.If there is no way for you to buy two chocolates without ending up in debt, return money.Note that the leftover must be non - negative.

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {

      auto min=  std::min_element(prices.begin(), prices.end());
      int minimum= *min;
      prices.erase(min);

      auto min2 = std::min_element(prices.begin(), prices.end());

      int secondminimum;
      secondminimum = *min2;
      if (minimum + secondminimum <= money)
      {
          cout << "first min : " << minimum << "  secind min:  " << secondminimum << "\n";
           money -= minimum + secondminimum;
           return money;
      }
        return money;
    }
};
int main()
{
    vector <int> Myvec;
    Myvec.push_back(1);
    Myvec.push_back(2);
    Myvec.push_back(2);

    


    Solution a;
    cout << a.buyChoco(Myvec, 3);
   
    
}

