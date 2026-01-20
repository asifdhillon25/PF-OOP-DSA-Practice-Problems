
#ifndef TIME_CLASS_TIME_H
#define TIME_CLASS_TIME_H

#include <iostream>
using namespace std;
class Time {
    int Minutes;
    int Hours;
    int Seconds;
public:
    Time();
    Time(int H,int M, int S);
    void ShowTime();
    void GoodTime();
    void SetTime(int H,int M, int S);
    Time operator +(Time & other);
    Time operator ++();
    Time operator --();
    Time operator ++(int);
    Time operator --(int);

};


#endif //TIME_CLASS_TIME_H
