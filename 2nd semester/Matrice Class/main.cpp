

#include "Matrix.h"

#include "Matrix.cpp"
int main() {

    Matrix a,b,result;

    cout<<"Enter Values for Matrix 1\n";
    a.SetMatrix();
    cout<<"Enter Values for Matrix 2\n";
    b.SetMatrix();

    cout<<"\nResult for addition of Matrices\n";
    result=a+b;
    result.ShowMatrix();

    cout<<"\nResult for Multiplication of Matrices\n";
    result=a*b;
    result.ShowMatrix();


}
