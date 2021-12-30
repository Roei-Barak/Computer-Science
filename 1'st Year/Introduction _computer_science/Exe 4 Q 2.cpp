/*
* Roei Barak
* ID 318419611
* exe 4 q 2
* */
#include<iostream>
using namespace std;
int main()
{
	int temp = 0;
	char l;
	char row[14];
	for (int i = 0; i < 14; i++)
	{
		row[i] = 'A' + i;
	}	
	int sit[14] = { 0 };
	while (temp < 30)
	{
		cin >> l;
		while (l >'N' || l< 'A')
		{
			cout << " ERROR" << endl;
			cin >> l;
		} 
		for (int  i = 0; i < 14; i++)
		{
			if (l == row[i])
			{
				temp = ++sit[i];
				break;
			}
		}
	}
	for (int i = 0; i < 14; i++)
	{
		cout << row[i] << " ";
		for (int k = 0; k < sit[i]; k++)
		{
			cout << '*';
		}
		cout << endl;
	}


	return 0;
}
/*
ABBBBBBBBAAABBBABBBACCABBABEBAAEBEEEBBBB
BBBBBBB
A **********
B ******************************
C **
D
E *****
F
G
H
I
J
K
L
M
N
*/