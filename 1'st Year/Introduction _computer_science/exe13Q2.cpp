/*
*Roei Barak - ID 318419611
*Computer science Introduction
*Exe 13  -- Q 1
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include <fstream>
#pragma warning (disable:4996)
using namespace std;
int f()
{
	char fileName[80];
	cin >> fileName;
	ifstream first_file;
	first_file.open(fileName);
	if (!first_file)
	{
		cout << "File could not be opened.\n";
		return -1;
	}
	int arr[10]; char tmp; int  count = 0;
	for (int i = 0; i < 10; i++)
	{
		while (!first_file.eof())
		{
			tmp = first_file.get();
			if (tmp == i + 48)
				count++;
		}
		arr[i] = count;
		count = 0;
		first_file.close();
		first_file.open(fileName);
	}
	ofstream freqFile("frequencyDigits.txt");
	if (!freqFile)
	{
		cout << "File could not be opened.\n";
		return -1;
	}
	freqFile << "digit\tfrequency\n";
	for (int i = 0; i < 10; i++)
		freqFile << i << '\t' << arr[i] << endl;
	cout << "digit\tfrequency\n";
	for (int i = 0; i < 10; i++)
		cout << i << '\t' << arr[i] << endl;
	first_file.close();
}
int main()
{
	f();
	/*char fileName[80];
	cin >> fileName;
	ifstream first_file;
	first_file.open(fileName);
	if (!first_file)
	{
		cout << "File could not be opened.\n";
		return -1;
	}
	int arr[10]; char tmp;int  count = 0;
	for (int i = 0; i < 10; i++)
	{
		while (!first_file.eof())
		{
			tmp = first_file.get();
			if (tmp == i+48 )
				count++;
		}
		arr[i] = count;
		count = 0;
		first_file.close();
		first_file.open(fileName);
	}
	ofstream freqFile("frequencyDigits.txt");
	if (!freqFile)
	{
		cout << "File could not be opened.\n";
		return -1;
	}
	freqFile << "digit\tfrequency\n";
	for (int i = 0; i < 10; i++)
		freqFile << i << '\t' << arr[i] << endl;
	cout << "digit\tfrequency\n";
	for (int i = 0; i < 10; i++)
		cout << i << '\t' << arr[i] << endl;
	first_file.close();*/
	return 0;
}
/*
information.txt
digit   frequency
0       2
1       2
2       0
3       0
4       0
5       0
6       0
7       0
8       0
9       0
*/