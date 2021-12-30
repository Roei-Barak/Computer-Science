#include "Point.h"
#include<cmath>

void Point::setX(int myX)
{
	Point::x = myX;
}

void Point::setY(int myY)
{
	Point::y = myY;
}

int Point::getX()
{
	return Point::x;
}

int Point::getY()
{
	return Point::y;
}
double Point::distance(Point firstpoint , Point seconpoint)
{
	int deltaY = seconpoint.y - firstpoint.y;
	int deltaX = seconpoint.x - firstpoint.x;
	double distance = sqrt(pow(deltaY, 2) + pow(deltaX, 2));
	return distance;
}

ostream& operator<<(ostream& os, const Point& ms)
{
	os << "(" << ms.x << "," << ms.y << ")";
	return os;
}

istream& operator>>(istream& is, Point& ms)
{
	char tav;
	is >> tav >> ms.x >> tav >> ms.y >> tav;// (x,y)
	return is;
}
