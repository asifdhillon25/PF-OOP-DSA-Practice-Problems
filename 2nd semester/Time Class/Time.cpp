//
// Created by PC on 6/20/2023.
//

#include "Time.h"

Time::Time(int H, int M, int S) {
    M<=60?Minutes=M:Minutes=0;
    H<=12?Hours=H:Hours=0;
    S<=60?Seconds=S:Seconds=0;
}

Time::Time() {
    Minutes=0;
    Hours=0;
    Seconds=0;
}



void Time::ShowTime() {
    cout<<"\t"<<Hours<<':'<<Minutes<<':'<<Seconds<<endl;
}

void Time::GoodTime() {

    while(Seconds>=60||Minutes>=60||Hours>=12)
    {
        if(Seconds>=60)
        {
            Seconds-=60;
            Minutes++;
        }
        if (Minutes>=60)
        {
            Minutes-=60;
            Hours++;
        }
        if (Hours>12)
        {
            int temp=Hours-12;
            Hours=temp;

        }
    }


}

void Time::SetTime(int H,int M, int S) {
    Minutes=M;
    Hours=H;
    Seconds=S;
}

Time Time::operator+(Time &other ) {

    Time temp;
    temp.Hours=other.Hours+Hours;
   temp.Minutes= other.Minutes+Minutes;
   temp.Seconds= other.Seconds+Seconds;
   temp.GoodTime();
    return temp;
}

Time Time::operator++() {

    Seconds++;
    GoodTime();
    return *this;
}

Time Time::operator--() {
    Seconds--;
    GoodTime();
    return *this;}

Time Time::operator--(int) {
    Seconds--;
    GoodTime();
    return *this;
}

Time Time::operator++(int) {
    Seconds++;
    GoodTime();
    return *this;
}
