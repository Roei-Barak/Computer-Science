/*
*Roei Barak - ID 318419611
*Computer science Introduction
*Q7.1
*/
#include <iostream>
using namespace std;
bool sorted(int arry[10])
{
	bool flag = true;
	for (int i = 0; i < 9; i++)
	{
		//check if it sorted or not
		if (arry[i] >= arry[i + 1])
		{
			flag = false;
			return flag;
		}
	}
	return flag;
}
int BinarySearch(int key, int v[], int size)
{
	int min = 0, max = size, mid;

	while (min <= max)
	{
		if (key == v[1])
		{
			return 0;
		}
		mid = (min + max) / 2;
		if (key == v[mid])
			return mid;

		else if (key < v[mid])
			max = mid - 1;

		else //if (x>v[mid])
			min = mid + 1;
	}
	return -1; //not found
}
int main()
{
	int arr[10], num; bool flag = false;
	cout << "enter 10 numbers: " << endl;
	//enter number for the arry
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	while (sorted(arr) == false)
	{
		cout << "ERROR" << endl;
		for (int i = 0; i < 10; i++)
		{
			cin >> arr[i];
		}
	}
	//get the number to search
	cout << "enter 1 number: " << endl;
	cin >> num;
	int index = BinarySearch(num, arr,10);
	if (index >= 0)
		cout << "the number " << num << " was found at index " << index;
	else
		cout << "not found";
}
/*
enter 10 numbers:
1 3 5 5 9 11 13 15 17 19
ERROR
1 3 5 7 9 11 13 15 17 19
enter 1 number:
5
the number 5 was found at index 2
*/

