#pragma once
#include"Point.h"
class polygon
{
public:
	
	polygon(int vertex = 0 );//constructor
	polygon(const polygon& source);//copy-constructor
	~polygon();//destructor
	void addPoint(int  index, int x, int y);
	int permiter();
	bool equal(polygon a);

private:
	Point* vecPtr;
	int Vertices;
};



