#include<iostream>
using namespace std;
class Matrix
{
	int rows;
	int cols;
	int **m = new int *[rows];
	
public:
	Matrix()
	{
		rows = 0;
		cols = 0;
	}
	Matrix(int r, int c)
	{
		rows = r;
		cols = c;
		
		for (int i = 0; i < rows; i++)
		{
			m[i] = new int[cols];
		}
		
	}
	void getMatrix()
	{
		cout << "Enter the matrix ";
		
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cin >> m[i][j];
			}
		}
	}
	void display();
	friend Matrix Mat_Mul(Matrix A, Matrix B);
};
void Matrix::display()
{
	cout << "The matrix is :" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}
Matrix Mat_Mul(Matrix A, Matrix B)
{
	Matrix T(A.rows, B.cols);
	for (int i = 0; i < T.rows; i++)
	{
		for (int j = 0; j < T.cols; j++)
		{
			T.m[i][j] = 0;
			for (int k = 0; k < A.cols; k++)
			{
				T.m[i][j] += A.m[i][k] * B.m[k][j];
			}
		}
	}
	return T;
}
int main()
{
	int r1, r2, c1, c2;
	cout << "Enter the rows and cols of matrix A";
	cin >> r1 >> c1;
	cout << "\nEnter the rows and cols of matrix B";
	cin >> r2 >> c2;
	Matrix A(r1, c1);
	Matrix B(r2, c2);
	Matrix C;
	A.getMatrix();
	B.getMatrix();
	if (c1 == r2)
	{
		
		C = Mat_Mul(A, B);
		C.display();
	}
	else
	{
		cout << "Matrix multiplication is not possible "<<endl;
	}
	system("pause");
	return 0;

}

