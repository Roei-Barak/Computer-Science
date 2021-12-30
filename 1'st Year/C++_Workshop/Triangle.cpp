#include<cmath>
#include"Triangle.h"
Triangle::~Triangle()
{
	if (Shape::p)
		delete[]p;
}
float Triangle::area() const
{
	Point a, b, c;
	a = Shape::p[0];
	b = Shape::p[1];
	c = Shape::p[2];
	float ab, bc, ca;
	float deltaY, deltaX;
	deltaY = b.getY() - a.getY();
	deltaX = b.getX() - a.getX();
	ab = sqrt(pow(deltaY, 2) + pow(deltaX, 2));
	deltaY = c.getY() - b.getY();
	deltaX = c.getX() - b.getX();
	bc = sqrt(pow(deltaY, 2) + pow(deltaX, 2));
	deltaY = a.getY() - c.getY();
	deltaX = a.getX() - c.getX();
	ca = sqrt(pow(deltaY, 2) + pow(deltaX, 2));
	double angle = (pow(ab, 2) + pow(bc, 2) - pow(ca, 2)) / (2 * ab * bc);
	//find angle with cos
	angle = acos(angle);
	return ((ab * bc * sin(angle)) / 2);
}

bool Triangle::isSpecial() const
{
	Point a, b, c;
	a = Shape::p[0];
	b = Shape::p[1];
	c = Shape::p[2];
	float ab, bc, ca;
	float deltaY, deltaX, dist;
	deltaY = b.getY() - a.getY();
	deltaX = b.getX() - a.getX();
	dist = sqrt(pow(deltaY, 2) + pow(deltaX, 2));
	ab = dist;
	deltaY = c.getY() - b.getY();
	deltaX = c.getX() - b.getX();
	bc = sqrt(pow(deltaY, 2) + pow(deltaX, 2));
	deltaY = a.getY() - c.getY();
	deltaX = a.getX() - c.getX();
	ca = sqrt(pow(deltaY, 2) + pow(deltaX, 2));
	if (ab == bc && bc == ca)
	{
		return true;
	}
	return false;
}

void Triangle::printSpecial() const
{
	Point a, b;
	a = Shape::p[0];
	b = Shape::p[1];
	float ab;
	float deltaY, deltaX, dist;
	deltaY = b.getY() - a.getY();
	deltaX = b.getX() - a.getX();
	dist = sqrt(pow(deltaY, 2) + pow(deltaX, 2));
	if (this->isSpecial())
	{
		cout << "An isosceles triangle with a side length " << dist << endl;
	}
}
