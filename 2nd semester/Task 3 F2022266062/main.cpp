#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nameheader.h"

using namespace std;

int namecompare(char a[],char b[]);

int main() {

    char first[10];
    char last[10];

    cout<<"Enter first name :";cin>>first;
    cout<<"\nEnter last name :";cin>>last;

    Name object;

    //setting values to object
    object.Settter(first,last);

    //checking if attributes are valid
    if(!object.isValidName())
    {
        cout<<"please go back and check names\n";
        ::getchar();
    }

    //displaying object
    object.display();

    //calling function
    object.camelCase();

    //displaying object
    object.display();

    //calling function
    object.uppercase();

    //displaying object
    object.display();

    //calling function
    object.lowercase();

    //displaying object
    object.display();


    //calling fullname func and storing its value in a pointer
//and displaying value
    char* fullname=object.fullname();
    cout<<"Full name is: "<<fullname<<endl<<endl;
    delete[] fullname;//destructor


    //calling function
    object.swapNames();

    //displaying object
    object.display();

cout<<"Namecompare function called\n";
cout<<"Value returned is: "<<namecompare(first,last)<<endl;

cout<<"namelengh is "<<object.nameLength(first,last);







    return 0;
}

int namecompare(char a[],char b[])
{
	int i;
	
    for( i=0;a[i]!='\0' && b[i]!='\0';i++)
    {
        if(a[i]>b[i]){
            return 1;
            break;
        }
        else if(a[i]<b[i])
        {
            return -1;
            break;
        }
        else{
            return 0;
        }
        
        
    }
    
    
     if (a[i] == '\0' && b[i] == '\0') {
        return 0; 
    } else if (a[i] == '\0') {
        return -1; 
    } else {
        return 1; 
    }
}
