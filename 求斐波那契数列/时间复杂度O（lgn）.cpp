#include <iostream>
using namespace std;

void MatrixN(long long matrix[2][2], const unsigned& n);
long long Fibonacci(const unsigned& n)
{
	/*
	*	f(n)		f(n-1)	=		1	1		的（n-1）方
	*	f(n-1)	f(n-1)			1	0
	*/

	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	long long fib[2][2] = {
										{1,1},
										{1,0}
									};

	MatrixN(fib, n - 1);

	return fib[0][0];
}

//求矩阵的n次方
void MatrixN(long long matrix[2][2], const unsigned& n)
{		
	if (n <= 1)
		return;
	if ( n == 2 )
	{
		long long matrixTemp[2][2];

		matrixTemp[0][0] = matrix[0][0];
		matrixTemp[0][1] = matrix[0][1];
		matrixTemp[1][0] = matrix[1][0];
		matrixTemp[1][1] = matrix[1][1];

		for (int i = 0;i < 2; i++)
			for (int j = 0;j < 2;j++)				
			{
				matrix[i][j] = matrixTemp[i][0] * matrixTemp[0][j] + matrixTemp[i][1] * matrixTemp[1][j];
			}
		return;
	}
	if (n % 2 == 0)
	{
		MatrixN(matrix, n / 2);
		MatrixN(matrix, 2);
		return;
	}
	if (n % 2 == 1)
	{
		MatrixN(matrix, (n - 1) / 2);
		MatrixN(matrix, 2);

		long long matrixTemp1[2][2];

		matrixTemp1[0][0] = matrix[0][0];
		matrixTemp1[0][1] = matrix[0][1];
		matrixTemp1[1][0] = matrix[1][0];
		matrixTemp1[1][1] = matrix[1][1];

		long long matrixTemp2[2][2];
		matrixTemp2[0][0] = 1;
		matrixTemp2[0][1] = 1;
		matrixTemp2[1][0] = 1;
		matrixTemp2[1][1] = 0;

		for (int i = 0;i < 2; i++)
			for (int j = 0;j < 2;j++)
			{
				matrix[i][j] = matrixTemp1[i][0] * matrixTemp2[0][j] + matrixTemp1[i][1] * matrixTemp2[1][j];
			}

		return;
	}
}


int main()
{
	for (unsigned int i = 0;i <= 50;i++)
		cout << Fibonacci(i) << "\t";

	system("pause");
}