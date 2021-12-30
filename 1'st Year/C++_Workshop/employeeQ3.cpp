#include<iostream>
#include"employee.h"
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)
using namespace std;

void employee::setEmployeeID(int setID)
{
	employee::ID = setID;
}
void employee::setEmployeeName(char setName[21])
{
#pragma warning(suppress : 4996) 
strcpy(employee::name ,setName);
}
void employee::setEmployeeHourlyWage(float setHourLyWage)
{
	employee::hourlyWage = setHourLyWage;
}
void employee::setEmployeeIncome(float setIncome)
{
	employee::income = setIncome;
}
void employee::setEmployeeWorkHours(int setWorkHours)
{
	employee::workHours = setWorkHours;
}
int employee::getEmployeeID()
{
	return employee::ID;
}
char* employee::getEmployeeName()
{
	return employee::name;
}
float employee::getEmployeeHourlyWage()
{
	return employee::hourlyWage;
}
int employee::getEmployeeWorkHours()
{
	return employee::workHours;
}
float employee::getEmployeeIncome()
{
	return employee::income;
}

int employee::salary()
{
	double temp = employee::income;
	double present = 0, sum = 0,totalSalary = 0,emplSalary = 0;
	int kilo = 1000;
	switch (0)
	{
	case 0://income between 0 to 1000
		if (temp > kilo) 
		{
			present = 0.1;
			sum += kilo * present;
			temp -= kilo;
		}
		else if (temp > 0)
		{
			present = 0.1;
			sum += temp * present;
			temp = 0;
			break;
		}
		else
			break;
	case 1://income between 1000 to 2000
		if (temp > kilo)
		{
			present = 0.15;
			sum += kilo * present;
			temp -= kilo;
		}
		else if (temp > 0)
		{
			present = 0.15;
			sum += temp * present;
			temp = 0;
			break;
		}
		else
			break;
	case 2://income between 2000 to 4000
	
		if (temp > 2*kilo)
		{
			present = 0.2;
			sum += 2.0*kilo * present;
			temp -= 2.0*kilo;
		}
		else if (temp > 0)
		{
			present = 0.2;
			sum += temp * present;
			temp = 0;
			break;
		}
		else
			break;
	case 3://income between 4000 to 5000
		
		if (temp > 1000)
		{
			present = 0.3;
			sum +=  kilo * present;
			temp -= kilo;
		}
		else if (temp > 0)
		{
			present = 0.3;
			sum += temp * present;
			temp = 0;
			break;
		}
		else
			break;
	case 4://income over 5000
		if (temp > 0)
		{
			present = 0.4;
			sum += temp * present;
			temp = 0;
			break;
		}
		else
			break;
	default:
		break;
	}
	emplSalary = employee::workHours * employee::hourlyWage;
	totalSalary = sum + emplSalary;
	return totalSalary;
}