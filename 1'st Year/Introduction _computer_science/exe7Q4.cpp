/*
*Roei Barak - ID 318419611
*Computer science Introduction
*Q7.4
*/
#include <iostream>
using namespace std;
void bubbleSort(char array[][5], int size)
{
	int last;
	for (last = 10 - 1; last > 0; last--)
	{

		for (int i = 0; i < last; i++)
		{
			int k = 0;
			while (array[i][k] == array[i + 1][k])
			{
				k++;
			}
			if (array[i][k] > array[i + 1][k])
			{
				for (int k = 0; k < 5; k++)
				{
					char temp = array[i + 1][k];
					array[i + 1][k] = array[i][k];
					array[i][k] = temp;
				}
			}
		}
	}
}


int main()
{
	char array[10][5];
	cout << "enter 10 words:" << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			cin >> array[i][k];
		}
	}
	cout << "after sorting:" << endl;
	bubbleSort(array, 10);
	/*int last;
	for (last = 10 - 1; last > 0 ; last--)
	{

		for (int i = 0; i < last ; i++)
		{
			int k = 0;
			while (array[i][k] == array[i + 1][k])
			{
				k++;
			}
			if (array[i][k] > array[i + 1][k])
			{
				for (int k = 0; k < 5; k++)
				{
					char temp = array[i + 1][k];
					array[i + 1][k] = array[i][k];
					array[i][k] = temp;
				}
			}
		}
	}*/
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			cout << array[i][k];
		}
		cout << " ";
	}


return 0;
}
/*
enter 10 words:
house apple teach array teach books point float apply begin
after sorting:
apple apply array begin books float house point teach teach
*/