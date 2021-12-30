/*
* Roei Barak
* ID 318419611
* exe 4 q 3
* */
#define SIZE 10
#include<iostream>
using namespace std;
int index(int* arr, int size)
{
	int ind = 0, sumBeg = arr[0];
	int sumEnd = 0;
	for (int i = size - 1; i > 0 ; i--)
	{
		sumEnd += arr[i];
	}
	for (int i = 1; i < size; i++)
	{
		sumBeg += arr[i];
		sumEnd -= arr[i];
		if (sumBeg == sumEnd)
		{
			return i;
		}
	}
	return-1;
}
int main()
{
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		cin >> arr[i];
	}
	cout << index(arr, SIZE);


	return 0;
}
/*
8 2 9 8 7 8 5 0 1 6
3
*/