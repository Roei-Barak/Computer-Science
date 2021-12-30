/************************
*	Roei Barak			*
*	318419611			*
*	Exe 7 Q	1			*
*						*
*						*
*************************/
#include <iostream>
using namespace std;
int* pilandrom(int num, int size) {
	int* arr = new int[size];
	if (size == 0)
	{
		arr[0] = num;
		return arr;
	}
	if (size == 1)
	{
		arr[0] = arr[1] = num;
		return arr;
	}
	int temp = 0;
	if (size % 2 != 0)
	{
		for (int i = 0; i < (size+1) / 2; i++)
		{
			arr[i] = num + i;
			temp = num + i;
		}
		for (int i = (size + 1) / 2; i < size + 1; i++)
		{
			arr[i] = temp--;
		}
	}
	if (size % 2 == 0)
	{
		for (int i = 0; i < (size + 1) / 2 + 1; i++)
		{
			arr[i] = num + i;
			temp = num + i;
		}
		for (int i = (size + 1) / 2 + 1; i < size+1; i++)
		{
			arr[i] = --temp;
		}
	}
	return arr;
}
int main()
{
	srand((unsigned)time(NULL));
	int n = 0;
	int temp = 0;
	cout << "enter a number : " ;
	cin >> n;
	int** arr = new int* [n * 2 - 1];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[i];
	}
	for (int i = n; i < 2 * n; i++)
	{
		arr[n] = new int[i];
	}
	for (int i = 0; i < n; i++)
	{
		/* for i is odd number->the first elemnt is max : 10 - i / 2
		for i is even number -> the dirst elemnt is max : 10 - i/2 + 1*/
		if (i % 2 == 0)
		{
			temp = rand() % (10 - i / 2 + 1) + 1;
			
			arr[i] = pilandrom(temp, i);
		}
		else if (i % 2 != 0)
		{
			temp = rand() % (10 - i / 2) + 1;
			arr[i] = pilandrom(temp, i);
		}
	}
	int k = n-1;
	for (int i = n; i < 2*n; i++)
	{
	
		if (i % 2 == 0)
		{
			temp = rand() % (10 - i / 2 + 1) + 1;
			arr[i] = pilandrom(temp,k);
		}
		else if (i % 2 != 0)
		{
			temp = rand() % (10 - i / 2) + 1;
			arr[i] = pilandrom(temp, k);
		}
		k--;
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < i + 1; k++)
		{
			cout << arr[i][k] << " ";
		}
		cout << endl;
	}
	for (int i = n; i < 2*n; i++)
	{
		for (int k = 0; k <2*n - i ; k++)
		{
			cout << arr[i][k] << " ";
		}
		cout << endl;
	}

	return 0;
}

/*
enter a number : 6
1
4 4
1 2 1
7 8 8 7
8 9 10 9 8
4 5 6 6 5 4
6 7 8 8 7 6
4 5 6 5 4
5 6 6 5
2 3 2
2 2
3

*/