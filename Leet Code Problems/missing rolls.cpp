
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <numeric>
using namespace std;

//Fortunately, you have also calculated the average value of the n + m rolls.
//n of the observations went missing, and you only have the observations of m rolls.
//Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.
//numbers divided by k.
//Return an array of length n containing the missing observations
//such that the average value of the n + m rolls is exactly mean.If there are multiple valid answers, return any of them.If no such array exists, return an empty array.
//The average value of a set of k numbers is the sum of the 
//value of the ith observation.You are also given the two integers mean and n.
//You are given an integer array rolls of length m where rolls[i] is the
//You have observations of n + m 6 - sided dice rolls with each face numbered from 1 to 6. 



class Solution {
public:

    Solution() {
        srand(time(0));
    }
    

    int generateRandomNumber( int upperLimit=6) {
        int i = 1;
        // Seed the random number generator with the current time
        

        // Generate a random number between i and upperLimit
        return std::rand() % (upperLimit - i + 1) + i;
    }

    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        
        if (mean >= 6)//if mean>=6
        {
            vector<int > empty;
            return empty;//returning empty array
        }

        int totalobservations = mean + n;
        
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
    label1:
        vector<int > remaining;
        for (int i = 0; i < n; i++)
        {
            remaining.push_back(generateRandomNumber());
        }

        int remain= accumulate(remaining.begin(), remaining.end(), 0);

        if ((sum + remain) / totalobservations == mean)
        {
            /*for (int i = 0; i < remaining.size(); i++)
            {
                rolls.push_back(remaining[i]);
            }*/

            return remaining;
        }
        goto label1;
    }
};
int main()
{
    vector <int> Myvec = {3,2,4,3 };
   
    int mean = 4, n = 2;

    Solution a;

    vector <int> vec;
    vec = a.missingRolls(Myvec, mean, n);


    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    
}

