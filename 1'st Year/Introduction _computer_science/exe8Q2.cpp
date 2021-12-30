/*
*Roei Barak - ID 318419611
*Computer science Introduction
*Q8.2
*/
#include<iostream>
using namespace std;
int arraySize(int *array, int size = 50)
{
	if (*array <= 0)
		return 0;
	for (int i = 1; i < size-1; i++)
	{
		if (*(array+i) <= 0)
			return (i);
	}
	return 50;
}
void bubbleSort(int *array, int size)
{
	int last;
	bool IsChange = true;
	for (last = size - 1; last > 0 && IsChange; last--)
	{
		// put in array[last] the largest element of array[0..last]
		IsChange = false;
		for (int i = 0; i < last; i++)
		{
			if (*(array+i) <=0)
			{
				IsChange = true;
				int temp = *(array + size-1);
				*(array + size - 1) = *(array+i);
				*(array + i) = temp;
			}
			if (*(array + i) > *(array + i + 1) && *(array + i + 1) > 0)
			{
				IsChange = true;
				int temp = *(array + i + 1);
				*(array + i + 1) = *(array + i);
				*(array + i) = temp;
			}
		}
	}
}
void printAll(int *array, int size)
{
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			cout << *(array + i) << "\n";
		}
	}
}
void InsertElement(int *array, int  size, int to_add)
{
	if (size != 0)
	{
		*(array + size) = to_add;
		bubbleSort(array, size + 1);
	}
	else
		*array = to_add;
}
void newClass(int *array, int size, int addClass)
{//add new class to database
	bool flag = true;
	for (int i = 0; i <= size ; i++)
	{
		if (*(array+i) == addClass)
		{
			flag = true;
			break;
		}
		else
			flag = false;
	}
	if (size < 50 && flag == false)
	{
		InsertElement(array, size, addClass);
	}
}
void delClass(int *array, int size, int delClass)
{
	
	//delete  class from database
	bool flag = true;
	for (int i = 0; i < size; i++)
	{
		if (*(array+i)!= delClass)
			flag = true;
		else
		{
			flag = false;
			*(array + i) = 0;
			bubbleSort(array, 50);
			break;
		}
	}
	for (int j = 0; j < size; j++)
	{
		if (*(array + j) == 0 || *(array + j) == *(array + j - 1))
			*(array + j) = *(array + j+1);
	}
}
int searchClass(int *array,int size,int searchClass)
{
	for (int i = 0; i < size; i++)
		if (*(array + i) == searchClass)
			return (++i);
	return NULL;
}
void printCode(int *array, int size, int code)
{int k=0;
	while ((*(array+k) /1000) <= code && *(array + k) >0 )
	{
		if ((*(array + k) / 1000) == code)
			cout << *(array + k) << " ";
		k++;
	}
}
int main()
{enum command {add , del , search , code , print , exit };
	int database[50]{ 0 };
	int size = arraySize(database, 50);
	cout << "Enter 0 to add a new classroom." << endl;
	cout << "Enter 1 to delete a hybrid classroom." << endl;
	cout << "Enter 2 to search for a specific classroom." << endl;
	cout << "Enter 3 to print all the classsrooms for a specific Machon." << endl;
	cout << "Enter 4 to print all the hybrid classrooms." << endl;
	cout << "Enter 5 to exit." << endl;
	cout << "Enter your choice:" << endl;
	int choise = 0;
	cin >> choise;
	while (choise != exit)
	{
		switch (choise)
		{
		case add:
			int addClass;
			cout << "Enter the code of the classroom to add:" << endl;
			cin >> addClass;
			newClass(database,size,addClass);
			size = arraySize(database, 50);
			printAll(database, size);
			break;
		case del:
			int deletClass;
			cout << "Enter the code of the classroom to delete:" << endl;
			cin >> deletClass;
			delClass(database,size,deletClass);
			size = arraySize(database, 50);
			printAll(database, size);
			break;
		case search:
			int serClass;
			cout << "Enter the code of the classroom to search for:"<< endl;
			cin >> serClass;
			if (searchClass(database,size,serClass) !=NULL)
				cout << "Found" << endl;
			else
				cout << "Not found" << endl;
			break;
		case code:
			int machon;
			cout << "Enter the code of the Machon:" << endl;
			cin >> machon;
			while (machon>99||machon<10)
			{
				cout << " ERROR " << endl;
				cin >> machon;
			}
			printCode(database, size,machon);
			break;
		case print:
			printAll(database, size);
			break;
		case exit:
			return 0;
		default:
			cout << "ERROR" << endl;
			break;
		}
		cout << "Enter your next choice:" << endl;
		cin >> choise;
	}
	return 0;

}
/*
Enter 0 to add a new classroom.
Enter 1 to delete a hybrid classroom.
Enter 2 to search for a specific classroom.
Enter 3 to print all the classsrooms for a specific Machon.
Enter 4 to print all the hybrid classrooms.
Enter 5 to exit.
Enter your choice:
0
Enter the code of the classroom to add:
11111
11111
Enter your next choice:
0
Enter the code of the classroom to add:
44444
11111
44444
Enter your next choice:
0
Enter the code of the classroom to add:
22222
11111
22222
44444
Enter your next choice:
1
Enter the code of the classroom to delete:
22222
11111
44444
Enter your next choice:
3
Enter the code of the Machon:
11
11111 Enter your next choice:
4
11111
44444
Enter your next choice:
5
*/