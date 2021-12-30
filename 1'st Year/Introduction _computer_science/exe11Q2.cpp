/*
*Roei Barak - ID 318419611
*Computer science Introduction
*Exe 11 -- Q 2
*/
#include <iostream>
using namespace std;
int smallest(int* arr, int size )
{
	int temp;
	int index = size-1;
	if (size == 1)
		return 0;
	temp = smallest(arr, size - 1);
	if (arr[size-1] < arr[temp])
	{
		return size - 1;
	}
	else
	{
		return temp;
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
	cout << "the smallest is: " << arr[smallest(arr, num)] << endl;
	//delete[] arr;
	return 0;

}
/*
enter a number:
6
enter array values: 2 4 5 1 5 6
the smallest is: 1

*/
