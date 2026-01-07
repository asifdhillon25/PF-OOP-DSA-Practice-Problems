
#include <iostream>
using namespace std;

class MyNum{
	
	//private member
    int num;

public:

	//constructers
    MyNum(){}
    MyNum(int a):num(a){}

	//getter and setter functions
    void setnum(int a){num=a;}
    int getnum()const{ return num;}
	
	//positive convert function
    int PositiveConvert(){

        if (num<0){
            num=num*-1;
        }
        return 0;
    }

	//Negative convert function
    int NegativeConvert(){

        if (num>0){
            num=num*-1;
        }
        return 0;
    }
    
    
    int a=0;
    
    //loop for sorting and returnng a pointer
    MyNum* osorting(int LengthOfArray,MyNum* array) {

        for (int i = 0; i < LengthOfArray; i++) {

            for (int j = 0; j < LengthOfArray; j++) {

                if (array[i].num < array[j].num) {
                    a = array[i].num;
                    array[i].num = array[j].num;
                    array[j].num= a;


                }
            }
        }
        return array;
    }

};

