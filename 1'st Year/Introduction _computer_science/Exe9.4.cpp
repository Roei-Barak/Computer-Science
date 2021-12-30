/****************
*	Roei Barak	*
*	318419611	*
*	Exe 9 Q	4	*
****************/
#include <iostream>
using namespace std;
int rec(int i);
int main()
{
	int index;
	cout << "Enter a number : ";
	cin >> index;
	cout << "The value in the index is : " << rec(index);
	return 0;
}

int rec(int i)
{
	if (i == 1)
	{
		return 3;
	}
	return (rec(i - 1) + 2);
}
/**************************************************
*	Enter a number : 5							  *
*	The value in the index is : 11				  *
**************************************************/

