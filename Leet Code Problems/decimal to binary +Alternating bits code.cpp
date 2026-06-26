
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n) {

       string num= Binary(n);


       for (int i = 0; i < num.size()-1; i++)
       {
           char next = num[i];
           char prev = num[i + 1];
           if (next == prev)
           {
               return false;
           }


       }

       return true;
    }

    string Binary(int n)
    {
        string binary;
       
        while (n > 0)
        {
            int temp = n % 2;
            //cout << "temp: " << temp;
            binary.push_back('0'+temp);
            n /= 2;
        }
        std::reverse(binary.begin(), binary.end());
        return binary;
    }

   
};
int main()
{
    Solution a;
   // cout <<"binary of"<<2122<< "is " <<   a.Binary(2122)<<endl;
    for (int i = 0; i <= 18; i++)
    {
        cout <<"binary of"<<i<< "is " <<   a.Binary(i)<<endl;
    }
   

    if (a.hasAlternatingBits(10))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    
}

