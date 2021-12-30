/************************
*Roei Barak				*
*318419611				*
*EXE 5 Q 4				*
*						*
*						*
*************************/
#include <iostream>
#define SIZE 8 
using namespace std;
void bubbleSort(int vec[], int size)
{
	int last, i;
	for (last = size - 1; last > 0; last--)
		for (int i = 0; i < last; i++)
			if (vec[i + 1] < vec[i]) {
				int temp = vec[i + 1];
				vec[i + 1] = vec[i];
				vec[i] = temp;
			}
}
void print(int* v, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << v[i];
		if (i < n - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;
}
int binarySearch(int* vec, int size, int num)
{
	int left = 0, right = size - 1, mid =0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (vec[mid] < num)
			left = mid + 1;
		else if (vec[mid] > num)
			right = mid - 1;
		else left = right + 1;
	}
	if (vec[mid] == num)
	{
		return mid;
	}
	else
		return-1;
}
int addOne(int num)
{
	int counter = 1;
	int val = 0;
	while (num > 0)
	{
		int digit = (num + 1) % 10;
		val = val + digit * counter;
		counter *= 10;
		num /= 10;
	}
	return val;
}
void fun(int* vec, int size, int val)
{
	int index = binarySearch(vec, size, val);
	if (index == -1)
		return;
	vec[index] = addOne(vec[index]);
	bubbleSort(vec, size);
}
int main()
{
	int arr[SIZE];
	cout << "enter " << SIZE << " sortted numbers :" << endl;
	for (int i = 0; i < SIZE; i++)
		cin >> arr[i];
	cout << "enter a num"<< endl ;
	int num;
	cin >> num;
	fun(arr, (sizeof arr) / sizeof arr[0], num);
	print(arr, (sizeof arr) / sizeof arr[0]);

	return 0;
}
/*
enter 8 sortted numbers :
504 9081 10385 29758 30015 41828 44098 59967
enter a num
29758
504, 9081, 10385, 30015, 30869, 41828, 44098, 59967
*/