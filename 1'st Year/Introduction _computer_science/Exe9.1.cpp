/****************
*	Roei Barak	*
*	318419611	*
*	Exe 9 Q	1	*
****************/
#include <iostream>
using namespace std;

void recurs(int n);
int main()
{
	int num;
	cout << "enter a positive number : ";
	cin >> num;
	while (num < 1)
	{
		cout << "ERROR !\nEnter a positive number : ";
		cin >> num;

	}
	cout << "reverse number is : ";
	recurs(num);
	return 0;
}

void recurs(int n)
{
	if (n < 1)
	{
		return;
	}
	cout << n % 10;
	recurs(n / 10);
	
}
/**************************************************
*	enter a positive number : 123456			  *
*	reverse number is : 654321					  *
**************************************************/