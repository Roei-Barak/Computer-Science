/*
Roei Barak 318419611
C++ סדנא
E - 1 --- Q - 3
*/
#include"circle.h"
#include"Point.h"
#include<iostream>
#include<cmath>
using namespace std;
#define PI 3.14
int main()
{
	Circle A;
	Circle B;
	Circle C;
	int  radius,x,y,aCount=0,bCount=0,cCount=0;
	char tav = ' ';
	cout << "enter the center point and radius of 3 circles:" << endl;
	cin >> tav >> x >> tav >> y >> tav >> radius;
	A.setCenter(x, y); A.setRadius(radius);
	cin >> tav >> x >> tav >> y >> tav >> radius;
	B.setCenter(x, y);B.setRadius(radius);
	cin >> tav >> x >> tav >> y >> tav >> radius;
	C.setCenter(x, y);C.setRadius(radius);
	cout << "perimeter:\tA: " << A.perimeter() << "\tB: " << B.perimeter() << "\tC: " << C.perimeter()<<endl;
	cout << "area:\tA: " << A.area() << "\tB: " << B.area() << "\tC: " << C.area()<<endl;
	cout << "enter points until (0,0):" << endl;
	Point temp;
	while (true)
	{
		cin >> tav >> x >> tav >> y >> tav;
		if (x == 0 && y == 0)
			break;
		temp.setX(x);temp.setY(y);
		if (A.onInOut(temp) != 1)
			aCount++;
		if (B.onInOut(temp) != 1)
			bCount++;
		if (C.onInOut(temp) != 1)
					cCount++;
	}
	cout << "num of points in circle:\tA:" << aCount << "\tB:" << bCount << "\tC:" << cCount;

}
/*
enter the center point and radius of 3 circles:
(0,0) 3
(1,1) 2
(5,5) 2
perimeter:      A: 18.84        B: 12.56        C: 12.56
area:   A: 28.26        B: 12.56        C: 12.56
enter points until (0,0):
(0,1)
(1,0)
(0,4)
(0,0)
num of points in circle:        A:2     B:2     C:0
*/