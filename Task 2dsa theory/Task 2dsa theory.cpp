#include <iostream>
using namespace std;
#include "Student.h"



int main()
{
    Student Myobj;

    Myobj.SetRowColoumn();
    Myobj.initializeMatrix1();
    Myobj.getMatrix1Values();
    Myobj.getMatrix2Values();
    Myobj.ShowMatrix(Myobj.matProduct());


}

