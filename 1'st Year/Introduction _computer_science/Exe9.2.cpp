/****************
*	Roei Barak	*
*	318419611	*
*	Exe 9 Q	2	*
****************/
#include <iostream>
using namespace std;
int recu(int n);
int main()
{
	cout << "enter a number : ";

	int x = 0;
	cin >> x;
	cout << "The number of digit of the number is : " << recu(x);
	return 0;
}

/**************************************************
*		enter a number : 123456789				  *
*		The number of digit of the number is : 9  *
* 						  						  *
**************************************************/

int recu(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return 	(recu(n / 10) + 1);
}
