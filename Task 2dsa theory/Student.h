#pragma once

#include <iostream>
using namespace std;


class Student
{
	int Row1;
	int Coloumn1;
	int** Matrix1;

	int Row2;
	int Coloumn2;
	int** Matrix2;
	int** AnsMatrix;

public:

	void SetRowColoumn();

	void initializeMatrix1();

	//function to calculatw mtrix and reto\utn product
	int** matProduct();


	//function to show matrix
	void ShowMatrix(int** matrix);


	void getMatrixValues(int** matrix, int rows, int columns);

	// Function to get values for Matrix1
	void getMatrix1Values();

	// Function to get values for Matrix2
	void getMatrix2Values();


	~Student();
};

