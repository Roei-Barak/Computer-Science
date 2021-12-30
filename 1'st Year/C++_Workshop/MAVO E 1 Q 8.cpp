/*
* Roei Barak
* ID 318419611
* exe 1 q 8
*/
#include<iostream>`
using namespace std;
bool allNum(int a)
{
	if (a)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool arithmetical(int a, int b,int c, int d,int e)
{
	if ((a - b) == (b - c) == (c - d) == (d - e))
		return true;
	else
		return false;
}
bool geometrical(int a, int b, int c, int d, int e)
{
	if ((a / b) == (b / c) == (c / d) == (d / e))
		return true;
	else
		return false;
}
int main()
{
	cout << "enter 5 values:" << endl;
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	a;
	a + b;
	if (allNum(a) == allNum(b) == allNum(c) == allNum(d) == allNum(e) == true)
	{
		if (arithmetical(a, b, c, d, e))
			cout << "arithmetical sequnce";
		else if (geometrical(a,b,c,d,e))
			cout << "geometrical sequnce";
		else
		{
			cout << "not an arithmetical sequnce and not geometrical sequnce";
		}
	}
	else
	{
		cout << "not an arithmetical sequnce and not geometrical sequnce";
	}
}
/*
enter 5 values:
a 3 d 5 6
not an arithmetical sequnce and not geometrical sequnce
*/