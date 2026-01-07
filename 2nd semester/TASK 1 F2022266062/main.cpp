#include <iostream>
#include "numheader.h"
using namespace std;



int main() {
	
	cout<<"Note:Enter only integer values\n";

    
    
    //sample object +constructer called
    MyNum object1;
    int value;
    cout<<"enter the value for single object\n";
    cin>>value;
    object1.setnum(value);
    cout << "\n\n\t\t***Printing data for single object***\n";
    //printing value of single object
    cout << "\n\tValue of first single object is " << object1.getnum() << endl;

	//asking user to enter no of objects he want
    cout << "\n\tenter the num of objects you want\n";
    cout << "\tenter number ";
    int ObjectNumber;
    cin >> ObjectNumber;

	//making a array of objects according to user
    MyNum *nObjects = new MyNum[ObjectNumber];


	//making a loop for intializing objects
    int ObjectValue;
    for (int i = 0; i < ObjectNumber; i++) {

        cout << "\tenter the value for object " << i + 1 <<": ";
        cin >> ObjectValue;
        nObjects[i].setnum(ObjectValue);
    }
	
	system("cls");
	
	//printing data
    cout << " \n\t***printing objects data***\n";
    for (int i = 0; i < ObjectNumber; i++) {

        cout << " \tvalue of object " << i + 1 << " is " << nObjects[i].getnum() << endl;
    }


		//new pointer for storing sorted array
     MyNum *Sortedobject;
	
	//calling sorted array function
    Sortedobject= nObjects->osorting(ObjectNumber, nObjects);

	//printing sorted data
    cout << "\n\t***Printing objects data after sorting***\n";
    for (int i = 0; i < ObjectNumber; i++) {

        cout << " \tvalue of object " << i + 1 << " is " << Sortedobject[i].getnum() << endl;
    }


}
