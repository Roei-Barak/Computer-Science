/*
Roei Barak 318419611
C++ סדנא
E - 2 --- Q - 1
*/

#include"Point.h"
#include"Polygon.h"
#include<iostream>
#include<cmath>

using namespace std;
int main()
{
	int vertices = 0, x, y;
	char symbol = ' ';
	Point* vecPtr = NULL;
	cout << "enter number of sides:" << endl;
	cin >> vertices;
	polygon a(vertices);
	cout << "enter the point values:" << endl;
	for (int i = 0; i < vertices; i++)
	{
		cin >> symbol >> x >> symbol >> y >> symbol;
		a.addPoint(i, x, y);
	}
	cout << "enter number of sides:"<< endl;
	cin >> vertices;
	polygon b(vertices);
	cout << "enter the point values:" << endl;
	for (int i = 0; i < vertices; i++)
	{
		cin >> symbol >> x >> symbol >> y >> symbol;
		b.addPoint(i, x, y);
	}
	if (a.equal(b) == true)
		cout << "equal. perimeter: " << a.permiter() << endl;
	else
	{
		cout << "perimeter: " << a.permiter() << endl;
		cout << "perimeter: " << b.permiter() << endl;
	}
	return 0;
}
/*
enter number of sides:
3
in constructor
enter the point values:
(13,10) (10,10) (10,14)
enter number of sides:
3
in constructor
enter the point values:
(10,10) (10,14) (13,10)
in copy-constructor
in destructor
equal. perimeter: 12
in destructor
in destructor

*/