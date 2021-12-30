#pragma once
#include<iostream>
#include"Employee.h"
class FullTime : public Employee
{
public:
	FullTime(string name = "", int id = 0, int seniority = 0, float pay = 0, float yea = 0);
	~FullTime();
	void setYealySalary(float y);
	float getYealySalary();
	int salary();
	friend ostream& operator<<(ostream& os, const FullTime& ms);
	friend istream& operator>>(istream& is, FullTime& ms);



private:
	float yearlySalary;
};