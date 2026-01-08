#include <iostream>
#include <string>
#include "charheader.h"
using namespace std;



int main() {


cout<<"Note: Enter only single character values\n\n";
    cout << "\n\n\t\t***Printing data for single character***\n";

    //sample object +constructer called
    MyChar object1;
    char getdata;
    cout << "enter data for single character\n";
    cin >> getdata;
    object1.setchar(getdata);

    //printing value of single object
    cout << "\n\tValue of first single character is " << object1.getchar() << endl;

    //asking user to enter no of objects he want
    cout << "\n\tenter the num of objects you want\n";
    cout << "\tenter number ";
    int ObjectNumber;
    cin >> ObjectNumber;

    //making a array of objects according to user
    MyChar *nObjects = new MyChar[ObjectNumber];


    //making a loop for intializing objects
    char ObjectValue;
    for (int i = 0; i < ObjectNumber; i++) {

        cout << "\tenter the value for character " << i + 1 << ": ";
        cin >> ObjectValue;
        nObjects[i].setchar(ObjectValue);
    }

    system("cls");

    //printing data
    cout << " \n\t***printing objects data***\n";
    for (int i = 0; i < ObjectNumber; i++) {

        cout << " \tvalue of character " << i + 1 << " is " << nObjects[i].getchar() << endl;
    }


    nObjects=nObjects->sorting(ObjectNumber,nObjects);



    //printing data
    cout << " \n\t***printing objects data after sorting***\n";
    for (int i = 0; i < ObjectNumber; i++) {

        cout << " \tvalue of character " << i + 1 << " is " << nObjects[i].getchar() << endl;
    }
    
    
    

}

