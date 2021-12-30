#pragma once
#include "Shape.h"
class Circle : public Shape 
{
public:
	Circle(int r) : Shape(1), radius(r) {};
	~Circle() {};
	float area() const;
	bool isSpecial() const ;
	void printSpecial() const ;

private:
	float radius;
};
