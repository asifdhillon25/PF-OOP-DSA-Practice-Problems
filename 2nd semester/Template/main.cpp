#include <iostream>
using namespace std;
#include "template.h"
#include "template.cpp"


int main() {


    int intNum1, intNum2;
    cout << "Enter two integers: ";
    cin >> intNum1 >> intNum2;
    Template<int> intCalc(intNum1, intNum2);

    float floatNum1, floatNum2;
    cout << "Enter two floating-point numbers: ";
    cin >> floatNum1 >> floatNum2;
    Template<float> floatCalc(floatNum1, floatNum2);

    cout << "Integer Calculation:" << endl;
    cout << "Addition: " << intCalc.add() << endl;
    cout << "Subtraction: " << intCalc.subtract() << endl;
    cout << "Multiplication: " << intCalc.multiply() << endl;
    cout << "Division: " << intCalc.divide() << endl;

    cout << "Floating-Point Calculation:" << endl;
    cout << "Addition: " << floatCalc.add() << endl;
    cout << "Subtraction: " << floatCalc.subtract() << endl;
    cout << "Multiplication: " << floatCalc.multiply() << endl;
    cout << "Division: " << floatCalc.divide() << endl;


}
