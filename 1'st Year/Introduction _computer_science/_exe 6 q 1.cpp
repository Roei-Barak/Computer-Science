/************************
*	Roei Barak			*
*	318419611			*
*	Exe 6 Q	1			*
*						*
*						*
*************************/
#include <iostream>
using namespace std;
bool fun(int arr[], int size, int target);
int main()
{
	int size;
	int target;
	cout << "enter size of the array and enter value to him : " << endl;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> *(arr + i);
	}
	cout << "enter the target number :" << endl;
	cin >> target;
	fun(arr, size, target) ? cout << "true"<< endl :cout<<"false";
	return 0;
}

bool fun(int arr[], int size, int target)
{
	int temp = 0;
	int* ptr = arr;
	for (int i = 0; i < size; i++)
	{
		while (temp < target)
		{
			temp += *(arr++);
			if (temp == target)
				return true;
		}
	}
	return false;
}
/*
enter size of the array and enter value to him :
10
6 3 2 5 24 2 11 1 2 9
enter the target number :
43
false
*/
