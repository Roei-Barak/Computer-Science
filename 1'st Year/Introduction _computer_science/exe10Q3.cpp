/*
*Roei Barak - ID 318419611
*Computer science Introduction
*Exe 10 -- Q 3
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#pragma warning (disable:4996);
using namespace std;
void bubbleSort(char**& array, int size)
{
	int last;
	bool IsChange = true;
	for (last = size - 1; last > 0 && IsChange; last--)
	{
		IsChange = false;
		for (int i = 0; i < last; i++)
			if (strncmp(array[i], array[i + 1], 80) > 0)
			{
				IsChange = true; int max_size = 0; int min_size = 0;
				int size1 = strlen(array[i]);
				int size2 = strlen(array[i + 1]);
				if (size1 > size2)
				{
					max_size = size1;
					min_size = size2;
				}
				else
				{
					max_size = size2;
					min_size = size1;
				}
				if (strncmp(array[i], array[i + 1], max_size) > 0)
				{
					for (int k = 0; k < max_size + 1; k++)
					{
						char temp = array[i + 1][k];
						array[i + 1][k] = array[i][k];
						array[i][k] = temp;
					}
				}
				else if (strncmp(array[i], array[i + 1], min_size) == 0 && size1 > size2)
				{
					for (int k = 0; k < max_size + 1; k++)
					{
						char temp = array[i + 1][k];
						array[i + 1][k] = array[i][k];
						array[i][k] = temp;
					}
				}
			}

	}
}
void printAll(char**& array, int size)
{
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < strlen(array[i]); j++)
			{
				cout << array[i][j];
			}
			cout << ' ';
		}
		cout << endl;
	}
	else
		return;
}
bool searchStr(char** array, int size, char* searchClass)
{
	bool flag = false;
	int i;
	for (i = 0; i < size; i++)
	{
		if (strlen(array[i]) != strlen(searchClass))
		{
			flag = false;
			continue;
		}
		for (int j = 0; j < strlen(array[i]); j++)
		{


			if (array[i][j] == searchClass[j])
				flag = true;
			else
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
			return true;
	}
	if (flag == true)
		return true;
	else
		return false;
}
void printChar(char** array, int size, char code)
{
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i][0] == code) // check if the first letter fit the letter was chosen and print the full string
		{
			for (int k = 0; k < strlen(array[i]); k++)
			{
				cout << array[i][k];
			}
			cout << '\n';
		}
	}
}
void delStr(char**& array, int& size, char* delClass)
{
	//delete  words from lexcion
	if (size < 1)
	{
		char** ptr = new  char* [0];
		delete[] array;
		array = ptr;
		return ;
	}

	bool flag = true;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (strlen(delClass) == strlen(array[i]))
		{
			for (int k = 0; k < strlen(delClass); k++)
			{
				if (array[i][k] == delClass[k])
					flag = true;
				else
				{
					flag = false;
					break;
				}
			}
		}
		else
			flag = false;
		if (flag == true)
			break;
	}
		if (flag == true)
		{
			for (int k = 0; k < strlen(delClass); k++)
				array[i][k] = array[size - 1][k];
		}
		else
			return;
	
	char** ptr = new char* [size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		ptr[i] = new char[80];
		for (int k = 0; k < strlen (array[i]) + 1; k++)
			ptr[i][k] = array[i][k];
	}
	delete[]array;
	array = ptr;
	size--;
	return ;
}
void newStr(char**& array, int& size, char* addClass)
{
	bool flag = true;
	if (size == 0)
	{
		char** ptr = new char* [1];
		delete[]array;
		array = ptr;
		for (int i = 0; i < 1; i++)
		{
			ptr[i] = new char[80];
			for (int j = 0; j < strlen(addClass) + 1; j++)
			{
				ptr[0][j] = addClass[j];
			}
		}
		size++;
		return;
	}
	char** ptr = new char* [size + 1];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = new char[80];
		for (int j = 0; j < strlen(array[i]) + 1; j++)
		{
			ptr[i][j] = array[i][j];
		}
	}
	for (int i = 0; i < 1; i++)
	{
		ptr[size] = new char[80];
		for (int j = 0; j < strlen(addClass) + 1; j++)
		{
			ptr[size][j] = addClass[j];
		}
	}
	delete[] array;
	array = ptr;
	++size;
}
int main()
{
	enum command { add, del, search, letter, print, exit };
	char** lexicon = NULL;
	int size = 0;
	cout << "Enter 0-5:" << endl;
	int choise = 0;
	cin >> choise;
	while (choise != exit)
	{
		switch (choise)
		{
		case add:
		{
			char  addStr[80];
			cout << "Enter the word:" << endl;
			cin >> addStr;
			newStr(lexicon, size, addStr);
			bubbleSort(lexicon, size);
			printAll(lexicon, size);
			break;
		}
		case del:
		{
			char deletStr[80];
			cout << "Enter the word to delete:" << endl;
			cin >> deletStr;
			delStr(lexicon, size, deletStr);
			bubbleSort(lexicon, size);
			printAll(lexicon, size);
			break;
		}
		case search:
		{
			char  Str[80];
			cout << "Enter the word to search for:" << endl;
			cin >> Str;
			if (searchStr(lexicon, size, Str) != 0)
				cout << "Found" << endl;
			else
				cout << "Not found" << endl;
			break;
		}
		case letter:
		{
			char letter;
			cout << "Enter the char:" << endl;
			cin >> letter;
			printChar(lexicon, size, letter);
			break;
		}
		case print:
		{
			printAll(lexicon, size);
			break;
		}
		case exit:
			return 0;
		default:
			cout << "ERROR" << endl;
			break;
		}
		cout << "Enter 0-5:" << endl;
		cin >> choise;
	}
	return 0;

}
/*
Enter 0-5:
0
Enter the word:
abc
abc
Enter 0-5:
0
Enter the word:
bcd
abc
bcd
Enter 0-5:
3
Enter the char:
a
abc
Enter 0-5:
4
abc
bcd
Enter 0-5:
2
Enter the word to search for:
abc
Found
Enter 0-5:
5
*/