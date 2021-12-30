#include"Shape.h"
Shape::Shape() {} // defult c-tor
Shape::~Shape() //d-ctor
{
	if (p)
	{
		delete[] p;
	}
}
Shape::Shape(int num) // c-tor
{
	numOfPoints = num;
	p = new Point[num];
	cout << "Enter values of " << num << " points: " << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> p[i];
	}
}

Shape::Shape(const Shape& shp)//copy c-tor
{
	this->numOfPoints = shp.numOfPoints;
	p = new Point[numOfPoints];
	for (int i = 0; i < shp.numOfPoints; i++)
	{
		p[i] = shp.p[i];
	}
}

Shape::Shape(Shape&& shp)
{
	numOfPoints = shp.numOfPoints;
	p = shp.p;
	shp.p = NULL;
}

ostream& operator<<(ostream& os, const Shape& ms)
{
	os << "points: ";
	for (int i = 0; i < ms.numOfPoints; i++)
	{
		cout << ms.p[i] << " ";
	}
	return os;
}
