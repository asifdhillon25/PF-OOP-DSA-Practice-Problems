//
// Created by PC on 6/20/2023.
//

#include "template.h"
template<class T>
Template<T>::Template(T n1, T n2) {
    num1 = n1;
    num2 = n2;
}

template<class T>
T Template<T>::add() {
    return num1 + num2;
}

template<class T>
T Template<T>::subtract() {
    return num1 - num2;
}

template<class T>
T Template<T>::multiply() {
    return num1 * num2;
}

template<class T>
T Template<T>::divide() {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        cout << "Error: Division by zero!" << std::endl;
        return 0;
    }
}


