#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector(int num)
{
	capacity = num;
	data = new int[num];
	size = 0;
}

Vector::Vector(const Vector& source)
{
	capacity = source.capacity;
	size = source.size;
	data = new int[capacity];
	for (int i = 0; i < size; i++)
		data[i] = source.data[i];
}

Vector::~Vector()
{
	if (data)
		delete[] data;
	data = NULL;
}

int Vector::getCapacity()
{
	return capacity;
}

int Vector::getSize()
{
	return size;
}

void Vector::print()
{
	cout << "capacity: " << capacity << " size: " << size << " values: ";
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}

void Vector::assign(const Vector& source)
{
	capacity = source.capacity;
	size = source.size;
	data = new int[capacity];
	for (int i = 0; i < capacity; i++)
		data[i] = source.data[i];
}

int& Vector::at(int index)
{
	if (index >= size || index < 0)
	{
		cout << "ERROR" << endl;
		return data[0];
	}
	return data[index];
}

int Vector::strcatcat(const Vector source)
{
	if (source.size != size)
	{
		cout << "ERROR" << endl;
		return -1;
	}
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += (source.data[i] * data[i]);
	return sum;
}

Vector Vector::strnewcat(const Vector source)
{
	int i = 0;
	Vector temp; // put the current vector first
	temp.capacity = capacity + source.capacity;
	temp.size = size + source.size;
	temp.data = new int[capacity];
	for (i = 0; i < size; i++)
		temp.data[i] = data[i];
	for (i; i < source.size + size; i++)// put the source vector second
		temp.data[i] = source.data[i - size];
	return temp;
}

void Vector::clear()
{
	size = NULL;
	delete[] data;
	data = NULL;
}

void Vector::delLast()
{
	if (size == 0)
	{
		cout << "ERROR" << endl;
		return;
	}
	size--;
	data[size] = NULL;
}

void Vector::insert(int val)
{
	if (size == capacity)
	{
		capacity *= 2;
		int* temp = new int[capacity];
		for (int i = 0; i < size; i++)
			temp[i] = data[i];
		temp[size] = val;
		delete[] data;
		size++;
		Vector::data = new int[capacity];
		for (int i = 0; i < size + 1; i++)
			Vector::data[i] = temp[i];
	
		return;
	}
	Vector::data[size] = val;
	size++;
}

bool Vector::isEqual(const Vector source)
{
	if (size != source.size)
		return false;
	for (int i = 0; i < size; i++)
		if (data[i] != source.data[i])
			return false;
	return true;
}
