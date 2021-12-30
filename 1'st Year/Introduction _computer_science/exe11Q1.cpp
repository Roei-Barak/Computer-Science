/*
*Roei Barak - ID 318419611
*Computer science Introduction
*Exe 11 -- Q 3
*/
#include <iostream>
using namespace std;
void printABs(int size, char a, char b)
{
	if (!size)
		return;
	else
		cout << a;
	printABs(size - 1, a,b);
	if (!size)
		return;
	else
		cout << 'b';

}
int main()
{
	int num;
	cout << "enter a number:" << endl;
	cin >> num;
	char a = 'a';
	printABs(num,a,'b');
	return 0;
}
/*
enter a number:
10
aaaaaaaaaabbbbbbbbbb
*/