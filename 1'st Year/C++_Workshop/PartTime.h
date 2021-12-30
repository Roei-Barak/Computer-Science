#pragma once
#include<iostream>
#include"Employee.h"
class PartTime : public Employee
{
public:
	PartTime(string name = "", int id = 0 , int seniority = 0 , float pay= 0 , int h = 0 , float pfh = 0 );
	~PartTime();
	void setPayForHour(float y);
	void setHour(int h);
	float getPayForHour();
	int getHour();
	float salary();
	friend ostream& operator<<(ostream& os, const PartTime& ms);
	friend istream& operator>>(istream& is, PartTime& ms);


private:
	int hour;
	float payForHour;
};
