/************************
*	Roei Barak			*
*	318419611			*
*	Exe 8 Q	1			*
*************************/
#include <iostream>
#include<cstring>
#include<string>
#pragma warning (disable:4996)
using namespace std;
char* serche(char sent[], char word[]);
void fun(char sent[], char sour[], char word[]);
int main()
{
	char va[80] = "abcazazyk";
	char b[80] = "azy";
	char* p = strchr(va, b[0]);
	cout << *p;
	//serche(va, b) ? cout << "true" : cout << "false";
	return 0;
}

//char* serche(char sent[], char word[])
//{
//	bool flag = false;
//	char* ptr = strchr(sent, word[0]);
//	char temp[80];
//	if (ptr == NULL)
//	{
//		return false;
//	}
//	for (size_t i = 0; i < strlen(word); i++)
//	{
//		temp[i] = *(ptr + i);
//	}
//	temp[strlen(word)] = '\0';
//	strcmp(ptr, word) == 0 ? flag = true : flag = false;
//	if (flag)
//	{
//		return true;
//	}
//	while (ptr <= sent - strlen(word))
//	{
//		for (size_t i = 0; i < strlen(word); i++)
//		{
//			temp[i] = *(ptr + i);
//		}
//		temp[strlen(word)] = '\0';
//		strcmp(ptr, word) ? flag = true : flag = false;
//		if (flag)
//		{
//			return true;
//		}
//		ptr = strchr(++ptr, word[0]);
//	}
//	return false;
//}

void fun(char sent[], char sour[], char word[])
{
	if (!serche(sent, sour))
	{
		cout << "words was not founded!";
		return;
	}
	char* ptr = strchr(sent, word[0]);


}

/**************************************************
*						  						  *
*						  						  *
*						  						  *
*						  						  *
*						  						  *
* 						  						  *
* 						  						  *
* 						  						  *
* 						  						  *
* 						  						  *
* 						  						  *
* 						  						  *
**************************************************/
