/************************
*Roei Barak				*
*318419611				*
*Exe 5 q 3				*
*						*
*						*
*************************/
#include <iostream>
#define SIZE 7
using namespace std;
int max(int a, int b)
{
	int max = 0;
	a > b ? max = a : max = b;
	return max;
}
int chain(int vec[SIZE][SIZE]);
int check(int vec[SIZE][SIZE], int row, int coul);
int main()
{
	int arr[SIZE][SIZE];
	srand((unsigned)time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			arr[i][j] = rand()%2;
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << arr[i][j] << " | ";
		cout << endl;
	}
	cout << endl << "the number withe the larget cahin is : " << chain(arr);
	return 0;
}

int chain(int vec[SIZE][SIZE])
{
	int counter = check(vec,0,0);
	int bin = vec[0][0];
	int temp = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i; j < SIZE; j++)
		{
			temp = check(vec, i, j);
			temp > counter ? bin = vec[i][j] : bin = bin;
			counter = max(temp,counter);
		}
	}
	return bin;
}

int check(int vec[SIZE][SIZE], int row, int coul)
{
	int counterCou = 0;
	int counterRow = 0;
	for (int i = row; i < SIZE - 1; i++) // loop for check coulm chain
	{
		if (vec[i][coul] == vec[i + 1][coul])
			counterCou++;
		else
			break;
	}
	for (int i = coul; i < SIZE - 1; i++) // loop for check row chain
	{
		if (vec[row][i] == vec[row][i + 1])
			counterRow++;
		else
			break;
	}
	
	return max(counterRow,counterCou);
}
/*
0 | 1 | 1 | 0 | 1 | 1 | 1 |
1 | 1 | 1 | 1 | 1 | 0 | 0 |
1 | 1 | 0 | 0 | 1 | 1 | 0 |
0 | 0 | 0 | 0 | 1 | 1 | 0 |
0 | 0 | 0 | 1 | 1 | 0 | 0 |
0 | 0 | 0 | 1 | 1 | 0 | 1 |
1 | 0 | 1 | 0 | 1 | 1 | 1 |

the number withe the larget cahin is : 1
*/