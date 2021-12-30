/*
*Roei Barak - ID 318419611
*Computer science Introduction
*exe 10 -- Q .1
* crypt a-z b-y
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#pragma warning (disable:4996)
using namespace std;
void crypto(char* list)
{
	int str_size = 0;
	cout << "Enter a string:" << endl;
	cin.getline(list,80);
	str_size = strlen(list);
	for (int i = 0; i < str_size; i++)
	{
		if (list[i] <= 'm' && list[i] >= 'a')
			list[i] = list[i] + 25 - (list[i] - 'a')*2;
		else if(list[i] <= 'z' && list[i] > 'm')
			list[i] = list[i] - 25 + ('z' -list[i]) * 2;
	}
}

int main()
{
	//declare list as char
	char list[80];
	crypto(list);
	cout << "After crypto:"<< endl;
	cout<<(list);

}
/*
Enter a string:
abcdefghijklmnopqrstuvwxyz
After crypto:
zyxwvutsrqponmlkjihgfedcba
*/