#include <iostream>
using namespace std;

 long long Fibonacci(const unsigned int& n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	 long long fibN1 = 0;
	 long long fibN2 = 1;
	long long fibN;
	for (unsigned int i = 2; i <= n; i++ )
	{
		fibN = fibN1 + fibN2;
		fibN1 = fibN2;
		fibN2 = fibN;
	}
	return fibN;
}

int main()
{
	for (unsigned int i = 0; i <= 50; i++)
		cout << Fibonacci(i) << "\t";

	system("pause");

	return 0;
}