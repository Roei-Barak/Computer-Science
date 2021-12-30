#include"Point.h"
#include"Polygon.h"
#include<iostream>
#include<cmath>

using namespace std;
polygon::polygon(int vertex)
{
	Vertices = vertex;
	vecPtr = new Point[vertex];
	cout << "in constructor" << endl;
}
polygon::polygon(const polygon& source)
{
	Vertices = source.Vertices;
	vecPtr = new Point[Vertices];
	for (int i = 0; i < Vertices; i++)
		vecPtr[i] = source.vecPtr[i];
	cout << "in copy-constructor" << endl;
}
polygon::~polygon()
{
	if (Vertices)
	{
		delete[] vecPtr;
		vecPtr = NULL;
		cout << "in destructor" << endl;

	}
}
void polygon::addPoint(int index, int x, int y)
{
	vecPtr[index].setX(x);
	vecPtr[index].setY(y);
}

int polygon::permiter()
{
	double permiter = 0;
	for (int i = 0; i < Vertices - 1; i++)
		permiter += vecPtr[i].distance(vecPtr[i], vecPtr[i + 1]);
	permiter += vecPtr[0].distance(vecPtr[0], vecPtr[Vertices - 1]);
	return round(permiter);
}

bool polygon::equal(polygon a)
{
	bool flag = false;
	if (a.Vertices != Vertices)
		return false;
	for (int i = 0; i < Vertices; i++) // loop for array of the point of the polygon
	{
		a.vecPtr[i];
		for (int j = 0; j < Vertices; j++)// loop to copmare between a point array and the polygon
		{
			if (vecPtr[i].getX() == a.vecPtr[j].getX() && vecPtr[i].getY() == a.vecPtr[j].getY())
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
			return false;
		flag == false;
	}
	return true;
}
