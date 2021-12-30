/****************
*	Roei Barak	*
*	318419611	*
*	Exe 9 Q	6	*
****************/
#include <iostream>
using namespace std;
bool rec(int* arr , int size);
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
rec(arr, size) ? cout << "there isn't a two counsecutive number with the same dozens digit" : cout << "there is two counsecutive number with the same dozens digit";
}



bool rec(int* arr ,int size	)
{
	if (((*arr/10)%10) == (*(arr+1 )/ 10) % 10)
	{
		return false;
	}
	if (size == 1)
	{
		return true;
	}
	return rec(arr + 1,size-1);
}
/************************************************************************
*	Enter the size of thw array : 4										*
*	Enter 4 numbers: 12 144 45 23									    *
*	there is two counsecutive number with the same dozens digit		    *
* 						  						  				  	    *
************************************************************************/