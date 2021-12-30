#pragma once
#include"Point.h"
class Shape
{
protected:
	int numOfPoints;
	Point* p;

public:
	Shape();
	virtual ~Shape();
	Shape(int num);
	Shape(const Shape& shp);
	Shape(Shape&& shp);
	virtual float area() const = 0;
	virtual bool isSpecial() const = 0;
	virtual void printSpecial() const= 0;
	friend ostream& operator<<(ostream& os, const Shape& ms);



private:

};
