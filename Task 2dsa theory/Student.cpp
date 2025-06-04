#include "Student.h"

 void Student::SetRowColoumn()
{
label1:
	cout << "Enter no of Rows for Matrix One: ";
	cin >> Row1;
	cout << "Enter  no of Coloumns for Matrix One: ";
	cin >> Coloumn1;

	cout << "Enter no of Rows for Matrix Two: ";
	cin >> Row2;
	cout << "Enter no of  Coloumns for Matrix Two: ";
	cin >> Coloumn2;

	if (Coloumn1 != Row2)
	{
		cout << " coloumn1 not equal to row 2\n ";
		cout << "Please re enter values\n\n";
		goto label1;
	}
}

 void Student::initializeMatrix1()
{
	Matrix1 = new int* [Row1];

	for (int i = 0; i < Row1; i++)
	{
		Matrix1[i] = new int[Coloumn1];
	}

	// For Matrix 2
	Matrix2 = new int* [Row2];

	for (int i = 0; i < Row2; i++)
	{
		Matrix2[i] = new int[Coloumn2];
	}

}

 int** Student::matProduct()
{
	// Check if the multiplication is possible


	// Allocate memory for the result matrix (AnsMatrix)
	AnsMatrix = new int* [Row1];

	for (int i = 0; i < Row1; i++)
	{
		AnsMatrix[i] = new int[Coloumn2];
	}

	// Perform matrix multiplication
	for (int i = 0; i < Row1; i++)
	{
		for (int j = 0; j < Coloumn2; j++)
		{
			int sum = 0;
			for (int k = 0; k < Coloumn1; k++)
			{
				sum += Matrix1[i][k] * Matrix2[k][j];
			}
			AnsMatrix[i][j] = sum;
		}
	}

	return AnsMatrix;
}

 void Student::ShowMatrix(int** matrix)
{

	 cout << "\nProduct is  " << endl;

	for (int i = 0; i < Row1; i++)
	{
		for (int j = 0; j < Coloumn2; j++)
		{
			cout << matrix[i][j] << "\t"; // Assuming tab separation
		}
		cout << endl; // Move to the next row
	}
}

 void Student::getMatrixValues(int** matrix, int rows, int columns)
{
	cout << "Enter values for the matrix:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "Enter value for row " << (i + 1) << ", column " << (j + 1) << ": ";
			cin >> matrix[i][j];
		}
	}
}

// Function to get values for Matrix1

 void Student::getMatrix1Values()
{
	getMatrixValues(Matrix1, Row1, Coloumn1);
}

// Function to get values for Matrix2

 void Student::getMatrix2Values()
{
	getMatrixValues(Matrix2, Row2, Coloumn2);
}

 Student::~Student()
{
	delete Matrix1;
	delete Matrix2;
	delete AnsMatrix;
}
