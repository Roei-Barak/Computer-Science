/*
Roei Barak
318419611
Exe 8 q 2
*/
#include<iostream>
#include<cstring>
#include<string>
#pragma warning (disable:4996)
using namespace std;
//bool isPalindrome(char str[])
//{
//
//	int start = 0;
//	int end = strlen(str) - 1;
//
//
//	while (end > start)
//	{
//		if (str[start++] != str[end--])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//char* recurs(char a[80])
//{
//	int  i;
//	char temp[80];
//	if (strlen(a) == 1)
//	{
//		return nullptr;
//	}
//	if (isPalindrome(a))
//		return a;
//	else
//	{
//		for (i = 0; i < strlen(a) - 1; i++)
//		{
//			temp[i] = a[i];
//		}
//		temp[i] = '\0';
//		return recurs(temp);
//	}
//}
//void fun(char sen[80])
//{
//	/*cout << "enter a sentence :";
//	char sen[80]{};
//	cin >> sen;*/
//	char temp[80]{};
//	char r[80]{};
//	char none[80]{};
//	char** arr = new char* [strlen(sen)];
//	int counter = 0;
//	for (int i = 0; i < strlen(sen); i++)
//	{
//		arr[i] = none;
//	}
//	for (int i = 0; i < strlen(sen); i++)
//	{
//		arr[counter] = new char[80];
//		if (recurs(sen + i) != nullptr)
//		{
//
//			strcpy(arr[counter], recurs(sen + i));
//			i += strlen(arr[counter]) - 1;
//			counter++;
//		}
//	}
//	for (int i = 0; i < counter; i++)
//	{
//		if (arr[i] == nullptr)
//		{
//			break;
//		}
//		cout << arr[i] << endl;
//	}
//}

int main()
{
	//char str[80];
	//cout << "enter a sentence :";
	//cin.getline(str, 80, '\n');
	//fun(str);
	//cout << "enter a charater to change : "; char temp; cin >> temp;
	//cout << "enter a index of charter to change : "; int index; cin >> index;
	//str[index] = temp;
	//fun(str);
	cout << "Hello\nWorld";

}
/*
enter a sentence :Gbtpxzfaeokclzzhfkqxbzbbttbssbtwht
zz
bzb
bttb
ss
************************************************************

enter a sentence : bvbtpxzfaeokclzzhfkqxbzbbttbssbtwht
bvb
zz
bzb
bttb
ss
enter a charater to change : w
enter a index of charter to change : 26
bvb
zz
bzb
wtbssbtw

*/

