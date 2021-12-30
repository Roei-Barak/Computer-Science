#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
public:
	Rectangle() :Shape(4) {};
	~Rectangle();
	float area() const;
	bool isSpecial() const;
	void printSpecial() const;

private:

};