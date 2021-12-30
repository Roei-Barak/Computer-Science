#pragma once
#include "Shape.h"
#include<cmath>
class Triangle : public Shape
{
public:
	Triangle (): Shape(3) {};
	~Triangle ();
	float area() const;
	bool isSpecial() const;
	void printSpecial() const;

private:

};
