

#ifndef TEMPLATE_TEMPLATE_H
#define TEMPLATE_TEMPLATE_H

#include <iostream>
using namespace std;

template <class T> class Template {
private:
    T num1;
    T num2;

public:
    Template(T n1, T n2);

    T add();

    T subtract();

    T multiply();

    T divide();
};

#endif //TEMPLATE_TEMPLATE_H
