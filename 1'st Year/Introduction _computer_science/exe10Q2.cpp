/*
*Roei Barak - ID 318419611
*Computer science Introduction
*exe 10 -- Q .2
*
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#pragma warning (disable:4996)
using namespace std;
void reverse(char sentence[])
{
	int letters_counter = 0;
	for (int i = 0; i < 80; i++)
	{
		if (sentence[i] == -52 ) //end of the string
			return ;
		if (sentence[i] != 32 && sentence[i] != '\0' && sentence[i] != '\n')
			letters_counter++;
		else
		{
			//swap beteewn the letters
			for (int j = 1; j <= letters_counter; j++)
			{
				char tmp;
				tmp = sentence[i - letters_counter];
				sentence[i - letters_counter] = sentence[i - j];
				sentence[i - j] = tmp;
				letters_counter--;
				sentence[i];
			}
			letters_counter = 0;
		}
	}
}

int main()
{
	char sentence[81];
	cout << "Enter a string: " << endl;
	cin.getline(sentence, 80);
	cout << "After reverse: ";
	reverse(sentence);
	/*int letters_counter = 0;
	for (int i = 0; i < 80; i++)
	{
		if (sentence[i] == -52)
		{
			return 0;
		}
		if (sentence[i] != 32 && sentence[i] != '\0' && sentence[i] != '\n')
			letters_counter++;
		else
		{
			for (int j = 1; j <= letters_counter; j++)
			{
				char tmp;
				tmp = sentence[i - letters_counter];
				sentence[i - letters_counter] = sentence[i-j];
				sentence[i-j] = tmp;
				letters_counter--;
				sentence[i];
			}
			letters_counter = 0;
		}
	}*/
	cout << (sentence);

}
/*
Enter a string:
This is a silly88 sentence
After reverse: sihT si a 88yllis ecnetnes
*/