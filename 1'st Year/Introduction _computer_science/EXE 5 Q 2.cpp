/************************
*Roei Barak				*
*318419611				*
*exe 5 q 2				*
*						*
*						*
*************************/
#include <iostream>
#define SIZE 10
using namespace std;
void mat(char arr[SIZE][SIZE], int row, int cul);
int main()
{
	cout << "enter row and coulm :" << endl;
	int row, coul;
	cin >> row >> coul;
	char arr[SIZE][SIZE];
	mat(arr, row, coul);
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << arr[i][j] << " , ";
		cout << endl;
	}
	return 0;
}

void mat(char arr[SIZE][SIZE], int row, int cul)
{
	arr[row][cul] = '+';
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i][cul] == '+')
			continue;
		arr[i][cul] = '-';
	}
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[row][i] == '+')
			continue;
		arr[row][i] = '*';
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cul; j++)
			arr[i][j] = 'U';
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = cul + 1; j < SIZE; j++)
			arr[i][j] = 'u';
	}
	for (int i = row + 1; i < SIZE; i++)
	{
		for (int j = 0; j < cul; j++)
			arr[i][j] = 'D';
	}
	for (int i = row + 1; i < SIZE; i++)
	{
		for (int j = cul + 1; j < SIZE; j++)
			arr[i][j] = 'd';
	}
}
/*
enter row and coulm :
4 8
U , U , U , U , U , U , U , U , - , u ,
U , U , U , U , U , U , U , U , - , u ,
U , U , U , U , U , U , U , U , - , u ,
U , U , U , U , U , U , U , U , - , u ,
* , * , * , * , * , * , * , * , + , * ,
D , D , D , D , D , D , D , D , - , d ,
D , D , D , D , D , D , D , D , - , d ,
D , D , D , D , D , D , D , D , - , d ,
D , D , D , D , D , D , D , D , - , d ,
D , D , D , D , D , D , D , D , - , d ,
*/