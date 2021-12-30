/*
* Roei Barak
* ID 318419611
* exe 1 q 3
*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int x = 0, y = 0, z = 0;
	int res = 0;
	char left, right;
	cin >> x >> left >> y >> right >> z;
	char p = '^', m = '*', d = '/', plus = '+', sub = '-';
	if (left != p && left != m && left != d)
	{
		switch (right)
		{
		case '^':
			res = pow(y, z);
			break;
		case '*':
			res = y * z;
			break;
		case'/':
			res = y / z;
			break;
		default:
			break;
		}
		switch (left)
		{
		case '+':
			res += x;
			break;
		case '-':
			res = x - res ;
			break;
		}

	}
	else
	{
		switch (left)
		{
		case '^':
			res = pow(x, y);
			break;
		case'/':
			res = x / y;
			break;
		case '+':
			res = x + y;
			break;
		case '-':
			res = x - y;
			break;
		case '*':
			res = x * y;
			break;
		}
		switch (right)
		{
		case'/':
			res /= z;
			break;
		case '+':
			res += z;
			break;
		case '-':
			res -= z;
			break;
		case '*':
			res *= z;
			break;
		case '^':
			res = pow(res, z);
			break;
		}
	}
	cout << res;
	return 0;
}
/*
5+8*4
37
*/