/************************
*	Roei Barak			*
*	318419611			*
*	Exe 7 Q	2			*
*						*
*						*
*************************/
#include <iostream>
using namespace std;
int size(int* arr)
{
	int i = 0;
	while (arr[i] != -1)
	{
		i++;
	}

	return i;
}
bool serche(int* arr, int num)
{
	int i = 0;
	while (arr[i] != -1)
	{
		if (arr[i] == num)
			return true;
		i++;
	}
	return false;
}
int * deleteNum(int* arr, int size, int num)
{
	int* newArr = new int[size - 1];
	int i = 0;
	while (arr[i] != -1)
	{
		if (arr[i] == num)
		{
			i++;
		}
		else
		{
			newArr[i] = arr[i];
			i++;
		}
	}
	return newArr;
}
int * newArr(int* arr, int size, int num)
{
	int* newArr = new int[size + 1];
	int i = 0;
	while (arr[i] != -1)
	{
		newArr[i] = arr[i];
		i++;
	}
	newArr[size] = num;
	newArr[size + 1] = -1;
	return newArr;
}
bool sixDig(int num);
int main()
{
	int** arr = new int* [4];
	for (int i = 0; i < 4; i++)
	{
		arr[i] = new int[0];
		arr[i][0] = -1;
	}
	char ch;
	bool flag = false;
	int id = 0;
	int temp = 0;
	int temp2 = 0;
	int* t;
	cout << "enter your choice (N/O/E) :";
	cin >> ch;
	while (ch != 'E')
	{
		flag = false;
		switch (ch)
		{
		case 'N':
			cout << "enter an client number: ";
			cin >> id;
			while (!sixDig(id))
			{
				cout << "Wrong client number !\nenter number between 0 - 999999:";
				cin >> id;
			}
			for (int i = 0; i < 4; i++)
			{
				if (serche(arr[i], id))
				{
					cout << "already in the queue number " << i << endl;
					flag = true;
					break;
				}
			}
			if (flag)
				break;
			arr[0] = newArr(arr[0], size(arr[0]), id);
			break;
		case 'O':
			cout << "enter the queue number 1/2/3/4:";
			cin >> temp;
			while (temp > 4 || temp < 1)
			{
				cout << "Wrong queue number !\nenter number between 1 - 4:";
				cin >> temp;
			}
			cout << "enter the client number :";
			cin >> id;
			while (!sixDig(id))
			{
				cout << "Wrong client number !\nenter number between 0 - 999999:";
				cin >> id;
			}
			if (!serche(arr[temp - 1], id))
				cout << "ERROR !\nnot founded" << endl;
			else
			{
				arr[temp - 1] = deleteNum(arr[temp - 1], size(arr[temp - 1]), id);
				cout << "etner to a new queue (y/n) ?";
				cin >> ch;
				if (ch == 'y')
				{
					cout << "etner the new queue : ";
					cin >> temp2;
					while (temp2 > 4 || temp2 < 1)
					{
						cout << "Wrong queue number !\nenter number between 1 - 4:";
						cin >> temp2;
					}
					while (temp == temp2)
					{
						cout << "ERROR! \nthe current queue! \nEnter a new queue number between 1-4 not include " << temp <<" :" ;
						cin >> temp2;
					}
						arr[temp2 - 1] = newArr(arr[temp2 - 1], size(arr[temp2 - 1]), id);
				}
			}
			break;
		default:
			cout << "ERROR" << endl;
		}
		cout << "enter your choice (N/O/E) :";
		cin >> ch;
	}
	return 0;
}
/*

enter your choice (N/O/E) :n
ERROR
enter your choice (N/O/E) :N
enter an client number: -1
Wrong client number !
enter number between 0 - 999999:19999999
Wrong client number !
enter number between 0 - 999999:13
enter your choice (N/O/E) :N
enter an client number: 12
enter your choice (N/O/E) :O
enter the queue number 1/2/3/4:5
Wrong queue number !
enter number between 1 - 4:0
Wrong queue number !
enter number between 1 - 4:1
enter the client number :13
etner to a new queue (y/n) ?y
etner the new queue : 1
ERROR!
the current queue!
Enter a new queue number between 1-4 not include 1 : 2
enter your choice (N/O/E) :O
enter the queue number 1/2/3/4:2
enter the client number :13
etner to a new queue (y/n) ?n
enter your choice (N/O/E) :O
enter the queue number 1/2/3/4:2
enter the client number :13
ERROR !
not founded

*/

bool sixDig(int num)
{
	if (num >999999 || num <=  0 )
	{
		return false;
	}
	return true;
}
