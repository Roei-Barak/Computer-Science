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
int file(char* first,char* sec)
{
	ifstream first_file;
	first_file.open(first);
	if (!first_file)
	{
		cout << "File could not be opened.\n";
		return -1;
	}
	float aver = 0; int tmp = 0; int count = 0;
	while (!first_file.eof())
	{
		first_file >> tmp;
		aver += tmp;
		count++;
	}
	first_file.close();
	aver = aver / count;
	ifstream sec_file;
	sec_file.open(sec);
	if (!sec_file)
	{
		cout << "File could not be opened.\n";
		return -1;
	}
	float sec_aver = 0; tmp = 0; count = 0;
	while (!sec_file.eof())
	{
		sec_file >> tmp;
		sec_aver += tmp;
		count++;
	}
	sec_file.close();
	sec_aver = sec_aver / count;
	if (aver > sec_aver)
		return 1;
	else
		return 2;
}
int main()
{
	char tmp[80] = { "grade1.txt" };
	char tmp2[80] = { "grade2.txt" };
	cout << "highest average found in file "<< file(tmp,tmp2);
}
//highest average found in file 2