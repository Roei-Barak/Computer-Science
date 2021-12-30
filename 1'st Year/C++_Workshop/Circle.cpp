#include<cmath>
#include"Circle.h"
#define PI 3.14
float Circle::area() const
{
	 return	(pow(this->radius, 2) * PI);
	 
}

bool Circle::isSpecial() const
{
	if (Shape::p->getX() ==0 && Shape::p->getY() == 0)
	{
		return true; 
	}
	return false;
}

void Circle::printSpecial() const
{
	if (isSpecial())
	{
		cout << "A canonical circle with a radius " << radius << endl;
	}
	else
	{
		return;
	}
}
