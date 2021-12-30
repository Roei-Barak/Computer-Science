#pragma once
class Vector
{
public:
	Vector(int num = 2);
	Vector(const Vector& source);
	~Vector();
	int getCapacity();
	int getSize();
	void print();
	void assign(const Vector& source);
	int& at(int index);
	int strcatcat(const Vector source);
	Vector strnewcat(const Vector source);
	void clear();
	void delLast();
	void insert(int val);
	bool isEqual(const Vector source);


private:
	int* data ;
	int capacity;
	int size;
};
