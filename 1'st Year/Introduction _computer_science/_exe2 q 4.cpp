/*
* Roei Barak
* ID 318419611
* exe 2 q 2
* */
#include<iostream>
using namespace std;
int factorial(int num)
{
	if (!num)
		return 1;
	int fact = 1;
	for (int i = 1; i <= num; i++)
	{
		fact *= i;
	}
	return fact;
}
double pow(double x, int y)
{
	double temp = 1;
	for (int i = 1; i <= y; i++)
	{
		temp *= x;
	}
	return temp;
}
int main()
{
	cout << "enter two numbers:" << endl;
	double p, cort, sum = 1;
	cin >> p >> cort;
	for (int i = 1; i < cort; i++)
	{
		sum += pow(p, i) / factorial(i);
	}
	cout << "e^" << p << " = " << sum;
	return 0;
}
/*
enter two numbers:
2 10
e^2 = 7.38871
*/
