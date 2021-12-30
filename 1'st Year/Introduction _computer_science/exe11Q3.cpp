/*
*Roei Barak - ID 318419611
*Computer science Introduction
*Exe 11 -- Q 3
*/	
#include <iostream>
using namespace std;
int smallest(int* arr, int size)
{
	int temp;
	int index = size - 1;
	if (size == 1)
		return 0;
	temp = smallest(arr, size - 1);
	if (arr[size - 1] < arr[temp])
	{
		return size - 1;
	}
	else
	{
		return temp;
	}
}

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void sort(int* arr, int size	)
{
	int small = smallest(arr, size);
	swap(arr, small, 0);
	if (size > 1 )
	{
		sort(arr + 1, size - 1);
	}

}
int main()
{
	int* arr;
	int num;
	do {
		cout << "enter a number:" << endl;
		cin >> num;
		if (num <= 0)
			cout << "ERROR" << endl;
	} while (num <= 0);
	arr = new int[num];
	cout << "enter array values: ";
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	cout << "before: \n";
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	sort(arr, num);
	cout << "after: \n";
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	//delete [] arr;
	return 0;
}
/*
6
enter array values: 2 5 7 5 3 1
before:
2 5 7 5 3 1
after:
1 2 3 5 5 7

*/