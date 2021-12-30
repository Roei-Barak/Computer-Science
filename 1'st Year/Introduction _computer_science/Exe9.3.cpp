/****************
*	Roei Barak	*
*	318419611	*
*	Exe 9 Q	3	*
****************/
#include <iostream>
using namespace std;
float rec(int x, int y , int i);
int main()
{
	cout << "Enter two number : ";
	int x, y;
	cin >> x >> y;
	cout <<"The rest of divaing the number is : "<< rec(x, y, 0);
	return 0;
}

/**************************************************
*		Enter two number : 1234 89				  *
*		The rest of divaing the number is : 77	  *
**************************************************/

float rec(int x, int y, int i = 0  )
{
	if (y*i > x)
	{
		return x-(y*--i);
	}
	if (y * i > x)
	{
		return 0;
	}
	return rec(x, y, i + 1);
}
