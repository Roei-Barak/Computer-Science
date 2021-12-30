/*
* Roei Barak
* ID 318419611
* exe 3 q 1
* */
#include<iostream>
#include<cmath>
using namespace std;
double dist(int x1, int y1, int x2, int y2)
{
	int deltaX = x1 - x2;
	int deltaY = y1 - y2;
	double distance = sqrt(pow(deltaX,2) + pow(deltaY,2));
	return distance;
}
bool circle(int x1, int y1, int r, int x2, int y2)
{
	if (dist(x1,y1,x2,y2) > r)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main()
{
	cout << "enter the circle center (x y) and the radius:" << endl;
	int x, y, r;
	cin >> x >> y >> r;
	int x2, y2;
	cout << "enter point cordinates:" << endl;
	cin >> x2 >> y2;
	circle(x, y, r, x2, y2) ? cout << "in the circle" : cout << "not in the circle";
	return 0;
}
/*
enter the circle center (x y) and the radius:
3 4
7
enter point cordinates:
9 8
not in the circle
*/