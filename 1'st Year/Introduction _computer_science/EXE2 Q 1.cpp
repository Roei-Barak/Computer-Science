/*
* Roei Barak
* ID 318419611
* exe 1 q 2
* */
#include<iostream>
using namespace std;
int main()
{
	cout << "how many money do you have ?" << endl;
	int num;
	cin >> num;
	if (num > 2600)
	{
		cout << "you can bay graphical board printer speaker and computer";
	}
	else if (num > 2300)
	{
		cout << "you can bay printer speaker and computer";
	}
	else if (num > 2100)
	{
		cout << "you can bay speaker and computer";
	}
	else if (num > 2000)
	{
		cout << "you can bay a computer";
	}
	else
	{
		cout << "you can't bay nothing ";
	}
	return 0;
}
/*
how many money do you have ?
2230
you can bay speaker and computer
*/