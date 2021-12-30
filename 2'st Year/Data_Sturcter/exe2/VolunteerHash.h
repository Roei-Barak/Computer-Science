#pragma once
#include "HashTable.h"
#include "Volunteer.h"
#include <iostream>
#include <cmath>
using namespace std;

class VolunteerHash : public HashTable<Volunteer, string>
{
	
	public:
		VolunteerHash(int size) : HashTable(size) {};
		int h1(string key);
		int h2(string key);

};


inline int VolunteerHash::h1(string key)
{
	/*
	 int sum = 0;
	 int* arr = new int[size];
	 for (int i = 0; i < key.size(); i++)
	 {
		 arr[i] = (int)key[i];
	 }
	 for (int i = key.size(); i > 0; i--)
	 {
		 int power = pow(128, (i - 1));
		 sum += arr[key.size() - i] * power;
	 }
	 */
	int sum = 0;
	for (size_t i = 0; i < key.size(); i++)
	{
		sum += (int)key[i];
	}
	return sum % size;
}

inline int VolunteerHash::h2(string key)
{
	return (h1(key) + 1);
}

