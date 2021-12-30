#pragma once
#define PI 3.14
#include<iostream>
using namespace std;
class Point
{
private:
	int x;
	int y;
public:
	void setX(int myX);
	void setY(int myY);
	int getX();
	int getY();
	double distance(Point firstpoint, Point seconpoint);
	friend ostream& operator<<(ostream& os, const Point& ms);
	friend istream& operator>>(istream& is, Point& ms);


};
