/*
*Roei Barak - ID 318419611
*Computer science Introduction
*Q7.3
*/
#include <iostream>
void InsertionSort(int vec[], int size)
{
	int i, j;
	for (i = 1; i < size; i++)
	{
		int tmp = vec[i];
		for (j = i; j > 0 && tmp < vec[j - 1]; j--)
			vec[j] = vec[j - 1];
		vec[j] = tmp;
	}
}

using namespace std;
int main()
{
	int array[10][10]{ 10 ,5,7,2,5,29,20 };
	cout << "enter the values: " << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			cin >> array[i][k] ;
		}
	}
	int left_trig[45]{ 0 };
	int right_trig[45]{ 0 };
	int diagonal[10]{ 0 };
	//diagonal vector
	for (int i = 0; i < 10; i++)
	{
		diagonal[i] = array[i][i];
	}
	//right_trig vector
	int right_trig_index = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int k = i + 1; k < 10 ; k++)
		{
			right_trig[right_trig_index] = array[i][k];
			right_trig_index++;
		}
	}
	//left_trig vector
	int left_trig_index = 0;
	for (int i = 1; i < 10; i++)
	{
		for (int k = 0; k < i; k++)
		{
			left_trig[left_trig_index] = array[i][k];
			left_trig_index++;
		}
	}
	cout << "before sorted: " << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			cout << array[i][k] << " ";
		}
		cout << "\n";
	}
	InsertionSort(right_trig, 45);
	InsertionSort(left_trig, 45);
	//sorted left_trig vector
	left_trig_index = 0;
	for (int i = 1; i < 10; i++)
	{
		for (int k = 0; k < i; k++)
		{
			array[i][k] = left_trig[left_trig_index];
			left_trig_index++;
		}
	}
	//sorted right_trig vector
	right_trig_index = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int k = i + 1; k < 10; k++)
		{
			array[i][k] = right_trig[right_trig_index];
			right_trig_index++;
		}
	}
	//old diagonal vector
	for (int i = 0; i < 10; i++)
	{
		array[i][i] = diagonal[i];
	}
	cout << "sorted matrix: " << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			cout << array[i][k] << " ";
		}
		cout << "\n";
	}

	return 0;
}
/*
enter the values:
1 11 21 31 41 51 61 71 81 91 2 12 22 32 42 52 62 72 82 92 3 13 23 33 43 53 63 73 83 93 4 14 24 34 44 54 64 74 84 94 5 15 25 35 45 55 65 75 85 95 6 16 26 36 46 56 66 76 86 96 7 17 27 37 47 57 67 77 87 97 8 18 28 38 48 58 68 78 88 98 9 19 29 39 49 59 69 79 89 99 10 20 30 40 50 60 70 80 90 100
before sorted:
1 11 21 31 41 51 61 71 81 91
2 12 22 32 42 52 62 72 82 92
3 13 23 33 43 53 63 73 83 93
4 14 24 34 44 54 64 74 84 94
5 15 25 35 45 55 65 75 85 95
6 16 26 36 46 56 66 76 86 96
7 17 27 37 47 57 67 77 87 97
8 18 28 38 48 58 68 78 88 98
9 19 29 39 49 59 69 79 89 99
10 20 30 40 50 60 70 80 90 100
sorted matrix:
1 11 21 22 31 32 33 41 42 43
2 12 44 51 52 53 54 55 61 62
3 4 23 63 64 65 66 71 72 73
5 6 7 34 74 75 76 77 81 82
8 9 10 13 45 83 84 85 86 87
14 15 16 17 18 56 88 91 92 93
19 20 24 25 26 27 67 94 95 96
28 29 30 35 36 37 38 78 97 98
39 40 46 47 48 49 50 57 89 99
58 59 60 68 69 70 79 80 90 100


*/