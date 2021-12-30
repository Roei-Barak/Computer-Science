/*
*Roei Barak - ID 318419611
*Computer science Introduction
*Exe 11 -- Q 4
*/
#include <iostream>
using namespace std;
void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void reverse(int* arr, int size)
{
	swap(arr, 0, size - 1);

	if (size > 2)
	{
		reverse(arr + 1, size - 2);
	}
	else
	{
		return;
	}
}
int main()
{
	int* arr;
	int num;
	cout << "enter a number: ";
	cin >> num;
	arr = new int[num];
	cout << "enter array values: ";
	for (int i = 0; i < num; i++)
		cin >> arr[i];

	cout << "before: \n";
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	reverse(arr, num);
	cout << "after: \n";
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	//delete [] arr;
	return 0;
}

/*
enter a number: 6
enter array values: 1 2 3 4 5 6
before:
1 2 3 4 5 6
after:
6 5 4 3 2 1

*/
