/*
Roei Barak 318419611
C++
E - 3 --- Q - 3
*/
#include"MyString.h"
#include<iostream>
using namespace std;
int main()
{
	char tav;
	char aChar[80] = {};
	char bChar[80] = {};
	int index;
	cin >> aChar;
	cin >> bChar;
	cin >> index;
	MyString a(aChar);
	MyString b(bChar);
	if (a < b)
		cout << "a<b" << endl;
	else if (a > b)
		cout << "a>b" << endl;
	else
		cout << "a=b" << endl;
	MyString c = a.insert(index, b.getString());
	if (index > a.length())
	{
		cout << "ERROR" << endl;
		cin >> tav;
		cin >> index;
		cout << "ERROR" << endl;
		return 0;
	}
	else
	{
		cout << c.getString() << endl;
	}
	cin >> tav;
	cin >> index;
	if (index >= c.length())
	{
		cout << "ERROR";
	}
	else
	{
		c[index] = tav;
		c.print();
	}
	
}
/*
Hello
World
2
a<b
WoHellorld
?
2
Wo?ellorld
*/