
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <numeric>
using namespace std;

//class Solution {
//public:
//
//   char s[5] = { 'a','e','i','o','u' };
//
//   vector<string>  stvec;
//   string current;
//
//   
//   int countVowelStrings(int n) {
//
//       int counter = 0;
//       bool flag = true;
//
//       while(flag)
//       {
//          
//          static int k = 0;
//          static int j = 0;
//          string st;
//           char temp = s[k];
//           //cout << "Temp id: " << temp<<"\n";
//          for (int i = 0; i < n; i++)
//          {
//              if (i == 0)
//              {
//                  st += temp;
//                  
//              }
//              else
//              {
//                  //cout << s[j]<<" ";
//                  st += s[j];
//                  j++;
//                 
//              }
//             
//          }
//
//          if (j %5==0)
//          {
//              j = 0;
//          }
//          counter++;
//        cout << st << " ";
//          stvec.push_back(st);
//          
//          
//             
//          
//              if (j >= 5)
//              {
//                  j = 0;
//              }
//
//
//          if (counter%5==0)
//          {
//              k = (k % 4) + 1;
//          }
//          if (!stvec.empty() && stvec.size() >= 2)
//          {
//              if (stvec.back() < stvec[stvec.size() - 1])
//              {
//                  flag = false;
//                  
//              }
//          }
//          
//       }
//
//       return counter;
//
//   }

        
        


    
//};


class Solution {
public:
    int countVowelStrings(int n) {
        if (n == 1) return 5;
        vector<int>v{ 1,2,3,4,5 };
        for (int i = 3; i <= n; i++) {
            vector<int>tmp;
            for (int j = 0; j < 5; j++) {
                int a = 0;
                for (int k = 0; k <= j; k++) {

                    a += v[k];
                }
                tmp.emplace_back(a);
            }
            copy(tmp.begin(), tmp.end(), v.begin());

        }
        int ans = 0;
        for (int i = 0; i < 5; i++) {
            ans += v[i];
        }
        return ans;


    }
};



int main()
{
    Solution a;
    cout << a.countVowelStrings(33);
    

}

