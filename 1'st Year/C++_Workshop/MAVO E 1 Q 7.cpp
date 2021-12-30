/*
* Roei Barak
* ID 318419611
* exe 1 q 1
*/
#include<iostream>
using namespace std;

bool odd(int a)
{
	if (!(a & 2))
		return true;
	else
		return false;
}
int positive(int a)
{
	if (a >= 0)
	{
		if (odd(a))
		{
			return 3;
		}
		else
		{
			return 2;
		}
	}
	else
		return 1;
}
int main()
{
	cout << " enter a number:" << endl;
	int num, afterNum;
	cin >> num;
	afterNum = positive(num);
	cout << afterNum;
}
/*
 enter a number:
-15
1
*/