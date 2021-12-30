/****************
*	Roei Barak	*
*	318419611	*
*	Exe 9 Q	7	*
****************/
#include <iostream>
using namespace std;
bool rec(int* arr, int size);
int main()
{
	int size = 0;
	cout << "Enter the size of thw array : ";
	cin >> size;
	int* arr = new int[size];
	cout << "Enter " << size << " numbers: ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	rec(arr, size) ? cout << "all the hundred digit is the same" : cout << "not all the hundred digit is the same";
	cout << endl;
	system("pause");
}



bool rec(int* arr, int size)
{
	if (size == 1)
	{
		return true;
	}
	if (((*arr / 100) % 10) != (*(arr + 1) / 100) % 10)
	{
		return false;
	}
	return rec(arr + 1, size - 1);
}
/************************************************************************
*	Enter the size of thw array : 5										*
*	Enter 5 numbers: 12345 9354 387 300 3301							*
*	all the hundred digit is the same									*
*************************************************************************/