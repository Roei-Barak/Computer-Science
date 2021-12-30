#include"Rectangle.h"
#include<cmath>
Rectangle::~Rectangle()
{
	if (Shape::p)
	{
		delete[]p;
	}
}

float Rectangle::area() const
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
	return ab * bc;
}

bool Rectangle::isSpecial() const
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
	if (ab == bc)
	{
		return true;
	}
	return false;
}

void Rectangle::printSpecial() const
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
		cout << "Square with side length " << dist << endl;
	}
}
