#include <iostream>
#include <iomanip>
using namespace std;



class Matrix {
private:
    int rows, cols;
    int data[100][100];

public:
    Matrix(int r, int c) : rows(r), cols(c) {}

    void readMatrix() {
        cout << "Enter the elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    void displayMatrix() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout <<left<<setw(4)<< data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            cerr << "Error: Matrices must have the same dimensions for addition." << endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }
};

int main() {
    int rows, cols;

    cout << "Enter the number of rows for the matrices: ";
    cin >> rows;

    cout << "Enter the number of columns for the matrices: ";
    cin >> cols;

    Matrix object1(rows, cols), object2(rows, cols), sum(rows, cols);

    cout << "Enter elements for matrix 1:" << endl;
    object1.readMatrix();

    cout << "Enter elements for matrix 2:" << endl;
    object2.readMatrix();

    sum = object1 + object2;

    cout << "Matrix 1:" << endl;
    object1.displayMatrix();

    cout << "Matrix 2:" << endl;
    object2.displayMatrix();

    cout << "Sum of matrices:" << endl;
    sum.displayMatrix();

    
}

