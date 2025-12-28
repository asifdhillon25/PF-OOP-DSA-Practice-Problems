
#ifndef MATRICE_CLASS_MATRIX_H
#define MATRICE_CLASS_MATRIX_H
#include <iostream>
using namespace std;
#define Rows 3
#define Col 3

class Matrix {

    int Matric[Rows][Col];
public:
    Matrix();
    void SetMatrix();
    void ShowMatrix();
    Matrix operator*(Matrix &other);
    Matrix operator+(Matrix &other);
    Matrix operator+=(Matrix &other);
    bool operator==(Matrix &other);

};


#endif //MATRICE_CLASS_MATRIX_H
