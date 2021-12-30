/*
* Roei Barak
* ID 318419611
* exe 1 q 5
*/
#include<iostream>
using namespace std;
bool fun(int a, int b, int c)
{
	if (c == (a % b))
		return true;
	else if (c == (b % a))
		return true;
	else
	{
		return false;
	}
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (fun(a, b, c))
	{
		cout << "yes";
		return true;
	}
	else if (fun(c,a,b))
	{
		cout << "yes";
		return true;
	}
	else if (fun(c,b,a))
	{
		cout << "yes";
		return true;
	}
	else
	{

		cout << "no";
		return false;
	}

}
/*
5 7 8
no
*/