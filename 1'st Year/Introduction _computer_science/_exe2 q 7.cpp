/*
* Roei Barak
* ID 318419611
* exe 2 q 7
* */
#include<iostream>
using namespace std;
int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - i; j++)
		{
			cout << "*\t";
		}
		for (int k = 0; k < i; k++)
		{
			cout << "\t";
		}
		for (int k = 0; k < i; k++)
		{
			cout << "\t";
		}
		for (int j = 0; j < num - i; j++)
		{
			cout << "*\t";
		}
		cout << endl;
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = num - i ; j <= num; j++)
		{
			cout << "*\t";
		}
		for (int k = 1; k < (num - i); k++)
		{
			cout << "\t";
		}
		for (int k = 1; k < num -i; k++)
		{
			cout << "\t";
		}
		for (int j = num - i; j <= num; j++)
		{
			cout << "*\t";
		}
		cout << endl;
	}
	return 0;
}
/*
4
*       *       *       *       *       *       *       *
*       *       *                       *       *       *
*       *                                       *       *
*                                                       *
*                                                       *
*       *                                       *       *
*       *       *                       *       *       *
*       *       *       *       *       *       *       *
*/