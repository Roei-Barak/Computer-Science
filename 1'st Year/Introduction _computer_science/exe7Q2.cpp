/*
*Roei Barak - ID 318419611
*Computer science Introduction
*Q7.2
*/
#include <iostream>
using namespace std;
bool sorted(int arry[10])
{
	bool flag = true;
		for (int i = 0; i < 9; i++)
		{
			if (arry[i] == 0)
				return flag;
			//check if it sorted or not
			if (arry[i] <= arry[i+1])
			{
				flag = false;
				return flag;
			}
		}
	return flag;
}
void array_fun( int * array) 
{
	bool flag = true;
	for (int i = 0; i < 10; i++)
	{
		cin >> *(array + i);
		if (array[i] == 0)
			break;
	}
	if (sorted(array) == 0)
		flag = false;
	while (flag == false)
	{
		for (int i = 0; i < 10; i++)
		{
			array[i] = 0;
		}
		cout << "ERROR" << endl;
		for (int i = 0; i < 10; i++)
		{
			cin >> array[i];
			if (array[i] == 0)
				break;
		}
		if (sorted(array) == 1)
			flag = true;
	}

}
void Merge(int a[], int b[],int c[], int target[], int size_a, int size_b ,int size_c)
{
	int index_a = 0, index_b = 0,index_c = 0, index_target = 0;

	while (index_a < size_a && index_b < size_b && index_c < size_c)
	{
		if (a[index_a] <= b[index_b])
		{
			if (c[index_c] >= b[index_b])
				target[index_target++] = c[index_c++];
			else
				target[index_target++] = b[index_b++];
		}
		else
		{
			if (a[index_a] <= c[index_c])
				target[index_target++] = c[index_c++];
			else
				target[index_target++] = a[index_a++];
		}
	}


	if (index_a == size_a) //elements left in b or c
	{
		while (index_b < size_b && index_c < size_c)
		{
			if (c[index_c] >= b[index_b])
				target[index_target++] = c[index_c++];
			else
				target[index_target++] = b[index_b++];
		}
		if (index_b == size_b)//elements left in c
			while (index_c < size_c)
				target[index_target++] = c[index_c++];
		else// elements left in b
			while (index_b < size_b)
				target[index_target++] = b[index_b++];
	}
	else if (index_b == size_b)//elements left in c or a
	{
		while (index_b< size_b && index_c < size_c)
		{
			if (c[index_c] >= a[index_a])
				target[index_target++] = c[index_c++];
			else
				target[index_target++] = a[index_a++];
		}
		if (index_a == size_a)//elements left in c
			while (index_c < size_c)
				target[index_target++] = c[index_c++];
		else// elements left in a
			while (index_a < size_a)
				target[index_target++] = a[index_a++];
	}
	else if (index_c == size_c)	//elements left in b or a
	{
		while (index_b < size_b && index_a < size_a)
		{
			if (a[index_a] >= a[index_a])
				target[index_target++] = a[index_a++];
			else
				target[index_target++] = a[index_a++];
		}
		if (index_a == size_a)	//elements left in b
			while (index_a < size_a)
				target[index_target++] = a[index_a++];
		else					// elements left in a
			while (index_a < size_a)
				target[index_target++] = a[index_a++];
	}
}

/*void test(int array[])
{
	int test = 0;
	int* temp = array + 1 ;
	cin >> array[3];
	cin >> test;
	*temp = test;
}
*/
int main()

{
	int first[10]{ 0 };
		int first_arr[10]{ 0 }, sec_arr[10]{ 0 }, thr_arr[10]{ 0 }, mergedarr[30];
		bool flag = true;
		//first arry number
		cout << "enter values for the first vector: " << endl;
		array_fun(first_arr);
		//second arry number
		cout << "enter values for the second vector: " << endl;
		array_fun(sec_arr);
		//third arry number
		cout << "enter values for the third vector: " << endl;
		array_fun(thr_arr);
		
		Merge(first_arr, sec_arr, thr_arr, mergedarr, 10, 10, 10);
		cout << "merged vector is: " << endl;
		int merged_index = 0;
		for (int i = 0; i < 30; i++)
		{
			if (mergedarr[i] <= 0)
				break;
			cout << mergedarr[i] << " ";
		}
}
/*
enter values for the first vector:
6 4 2 0
enter values for the second vector:
-1 0
ERROR
 5 4 3 3 0
ERROR
5 4 3 0
enter values for the third vector:
7  6 5 4 3 2 1 0
merged vector is:
7 6 6 5 5 4 4 4 3 3 2 2 1
*/