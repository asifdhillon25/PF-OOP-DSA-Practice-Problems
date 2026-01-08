
#include <iostream>
using namespace std;

class MyChar{
	
	char ch;

public:

	//constructers
    MyChar(){}
    MyChar(char a): ch(a){}

	//getter and setter functions
    void setchar(char a){ ch=a;}
    char getchar()const{ return ch;}


    void lowercase(string str)
    {
        for(int i=0;str[i]!='\0';i++){


            if(str[i]>='A' && str[i]<='Z')
            {
                str[i]=str[i]+32;
            }
        }

        cout<<"The string in lower case is "<<str;
    }



    void uppercase(string str)
    {
        for(int i=0;str[i]!='\0';i++){


            if(str[i]>='a' && str[i]<='z')
            {
                str[i]=str[i]-32;
            }
        }

        cout<<"The string in upper case is "<<str;
    }

char cha='\0';

    MyChar* sorting(int lengthofarray, MyChar object[]) {

        for (int i = 0; i < lengthofarray; ++i) {

            for (int j = 0; j < lengthofarray; ++j) {

                if (object[i].ch<object[j].ch){

                    cha=object[i].ch;
                    object[i].ch=object[j].ch;
                    object[j].ch=cha;
                }
            }
        }
        return object;
    }


};

