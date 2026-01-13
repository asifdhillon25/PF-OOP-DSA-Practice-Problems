#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Name {
private:
    char *firstName;
    char *lastName;
public:
//
//    Name()
//    {
//        firstName= nullptr;
//        lastName= nullptr;
//    }

//    setter function for both characters
    void Settter(char f[], char l[]);

//    getter for first char
    void getfirst();

//    getter for last char
    void getlast();

// make first letter capital of both attributes
    void camelCase();

//    function for lower case conversion
    void lowercase();

//    function for uppercase conversion
    void uppercase();

//    function for getting length of both names
    int nameLength(char a[],char b[]);

//    function for swapping names
    void swapNames();

//    funcion for displaying both names
    void display();

//    function for checking if name is valid
        bool isValidName();
//function for full name (catenation)
        char* fullname();




//destructor
        ~Name();


    };

bool Name::isValidName() {

    int x = 0;
    int y = 0;
    for (int i = 0; (firstName[i]) != '\0'; ++i) {

        if ((firstName[i]) < 'A' || (firstName[i]) > 'z') {
            x++;
            break;
        }

    }
    for (int i = 0; (lastName[i]) != '\0'; ++i) {

        if ((lastName[i]) < 'A' || (lastName[i]) > 'z') {
            y++;
            break;
        }

    }
    if (x == 0 && y == 0) {
        cout << "Both names are valid\n";
        return true;
    } else {
        cout << " Warning!: One of the name is not valid\n";
        return false;
    }


}

void Name::display() {

    cout << "Printing Attributes\n";
    getfirst();
    cout << "\t";
    getlast();
    cout << endl << endl;

}

void Name::swapNames() {

    char ftemp[10];
    char ltemp[10];



    for (int i = 0; i<10; ++i) {

        ftemp[i] = firstName[i];
        if(firstName[i]=='\0')
        {
            break;
        }
    }


    for (int i = 0; i<10; ++i) {

        ltemp[i] =lastName[i];
        if(lastName[i]=='\0')
        {
            break;
        }
    }

    for (int i = 0; i<10; ++i) {

        lastName[i]=ftemp[i];
        if(ftemp[i]=='\0')
        {
            break;
        }
    }

    for (int i = 0; i<10; ++i) {

        firstName[i]=ltemp[i];
        if(ltemp[i]=='\0')
        {
            break;
        }
    }

    cout << "Both names have been swapped\n";

}

int Name::nameLength(char *a, char *b) {

    int i=0;
    int flength = 0;
    int llength=0;

    while ((a[i]) != '\0')
    {
        flength++;
        i++;
    }
    i=0;
    while ((b[i]) != '\0')
    {
        llength++;
        i++;
    }


    return flength+llength;

}

void Name::uppercase() {
    cout << "Changing Attributes to Uppercase\n";

    for (int i = 0; firstName[i] != '\0'; i++) {


        if (firstName[i] >= 'a' && firstName[i] <= 'z') {
            firstName[i] -= 32;
        }
    }

    for (int i = 0; lastName[i] != '\0'; i++) {


        if (lastName[i] >= 'a' && lastName[i] <= 'z') {
            lastName[i] -= 32;
        }
    }
}

void Name::lowercase() {

    cout << "Changing Attributes to lowercase\n";
    for (int i = 0; firstName[i] != '\0'; i++) {


        if (firstName[i] >= 'A' && firstName[i] <= 'Z') {
            firstName[i] += 32;
        }
    }

    for (int i = 0; lastName[i] != '\0'; i++) {


        if (lastName[i] >= 'A' && lastName[i] <= 'Z') {
            lastName[i] += 32;
        }
    }

}

void Name::camelCase() {

    cout << "Changing Attributes to Camelcase\n";

    if (firstName[0] >= 'a' && firstName[0] <= 'z') {
        firstName[0] = firstName[0] - 32;
    }
    if (lastName[0] >= 'a' && lastName[0] <= 'z') {
        lastName[0] = lastName[0] - 32;
    }
}

void Name::getlast() {
    for (int i = 0; (lastName[i]) != '\0'; ++i) {

        cout << lastName[i];

    }
}

void Name::getfirst() {
    for (int i = 0; (firstName[i]) != '\0'; ++i) {

        cout << firstName[i];

    }
}

void Name::Settter(char *f, char *l) {


    firstName = new char[9];
    for(int i=0;i<9 ;i++)
    {
        firstName[i]=f[i];
        if (f[i]=='\0')
        {
            break;
        }
    }


    lastName = new char[9];
    for(int i=0;i<9 ;i++)
    {
        lastName[i]=l[i];
        if (l[i]=='\0')
        {
            break;
        }
    }



}

char *Name::fullname() {

    char* fullname = new char[20];
    int i;
    for (i = 0; firstName[i] != '\0'; ++i) {
        fullname[i] = firstName[i];
    }
    fullname[i] = ' ';
    int j;
    for (j = 0; lastName[j] != '\0'; ++j) {
        fullname[i + j + 1] = lastName[j];
    }
    fullname[i + j + 1] = '\0';
    cout<<"Full name function called\n";
    return fullname;
}

Name::~Name() {
    delete[] firstName;
    delete[] lastName;

}





