
#include "Matrix.h"

void Matrix::SetMatrix() {

    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Col; ++j) {
            cin>>Matric[i][j];


        }

    }

}

Matrix Matrix::operator*(Matrix &other) {
    Matrix temp;
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Col; ++j)
        {temp.Matric[i][j]=0;
            for (int k = 0; k < Col; ++k) {
                temp.Matric[i][j]+=Matric[i][k]*other.Matric[k][j];
            }

        }
    }

    return temp;
}

void Matrix::ShowMatrix() {
    for (int i = 0; i < Rows; ++i) {
        cout<<endl;
        for (int j = 0; j < Col; ++j) {
            cout<<Matric[i][j]<<" ";


        }

    }

}

Matrix::Matrix() {

    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Col; ++j) {
            Matric[i][j]=0;


        }

    }
}

Matrix Matrix::operator+(Matrix &other) {
    Matrix result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.Matric[i][j] = Matric[i][j] + other.Matric[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator+=(Matrix &other) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Matric[i][j] += other.Matric[i][j];
        }
    }
    return *this;
}

bool Matrix::operator==(Matrix &other) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Matric[i][j] != other.Matric[i][j]) {
                return false;
            }
        }
    }
    return true;
}
