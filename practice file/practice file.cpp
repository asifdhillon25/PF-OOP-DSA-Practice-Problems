// practice file.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:

    bool minusfLAG=false;
    bool positiveflag=false;
    bool firstwordflag=false;
    int output = 0;
    int i = 0;


    int myAtoi(string s) {

        while (i < s.length() && s[i] == ' ')
            i++;

        if (s[i] == '-') {
            minusfLAG = true;
            i++;
        }
        if (s[i] == '+') {
            positiveflag = true;
            i++;
        }
        
        if (minusfLAG && positiveflag)
        {
            return 0;
        }

        if (!isdigit(s[i]))
            return 0;

        while(i < s.length() && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            // Check for overflow
            if (!minusfLAG && (output > INT_MAX / 10 || (output == INT_MAX / 10 && digit > INT_MAX % 10))) {
                return INT_MAX;
            }
            if (minusfLAG && (-output < INT_MIN / 10 || (-output == INT_MIN / 10 && digit > -(INT_MIN % 10)))) {
                return INT_MIN;
            }

            output = output * 10 + digit;
            i++;
        }

        if (minusfLAG)
        {
            output *= -1;
        }

        return output;
    }
}; 



 
    int main()
    {

        
        Solution S;

        cout << S.myAtoi("2147483646");

        return 0;
    }

 
    int myAtoi(string s) {
        int i = 0;
        bool minusFlag = false;
        int output = 0;

        // Skip whitespace characters
        while (i < s.length() && s[i] == ' ')
            i++;

        // Check for optional sign character
        if (s[i] == '-') {
            minusFlag = true;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }

        // Process numeric characters
        while (i < s.length() && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow
            if (output > INT_MAX / 10 || (output == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return minusFlag ? INT_MIN : INT_MAX;
            }

            output = output * 10 + digit;
            i++;
        }

        // Apply sign
        if (minusFlag) {
            output *= -1;
        }

        return output;
    }
