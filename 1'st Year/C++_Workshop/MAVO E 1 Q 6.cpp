/*
* Roei Barak
* ID 318419611
* exe 1 q 6
*/
#include<iostream>
using namespace std;
int main() 
{
	cout << "enter 3 number between 100 - 999" << endl;
	int a, b, c, res;
	int meot, asarot, achadot;
	cin >> a >> b >> c;
	meot = a / 100;
	asarot =( b / 10) % 10;
	achadot = c % 10;
	res = meot * 100 + asarot * 10 + achadot;
	cout << res;
}
/*enter 3 number between 100 - 999
111 222 333
123*/