
/*
Roei Barak 318419611
C++ סדנא
E - 1 --- Q - 2
*/
#include<iostream>
#include"employee.h"
#include <string.h>
#define CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)
using namespace std;
int main()
{
	employee minimumSum;
	employee highestSalary;
	employee firstEmployee;
	employee secondEmployee;
	employee temp;
	int ID=1;
	char name[21];
	float hourlyWage;
	int workHours;
	float income;

	int stop;
	cout << "enter details, to end enter 0:" << endl;
	cin >> ID;
	if (ID == 0)
		return 0;
	cin >> name;
	cin >> hourlyWage >> workHours >> income;
	while (ID < 0 || hourlyWage < 0 || workHours < 0 || income < 0) // check if the number are positive for the second employee
	{
		cout << "ERROR" << endl;
		cin >> ID;
		cin >> name;
		cin >> hourlyWage >> workHours >> income;
	}
	firstEmployee.setEmployeeName(name);
	firstEmployee.setEmployeeIncome(income);
	firstEmployee.setEmployeeID(ID);
	firstEmployee.setEmployeeWorkHours(workHours);
	firstEmployee.setEmployeeHourlyWage(hourlyWage);
	highestSalary = firstEmployee;
	minimumSum = firstEmployee;
	while (ID !=0 )
	{
		cin >> ID;
		if (ID == 0)
		{
			cout << "minimum sum:" << minimumSum.getEmployeeIncome() << " " << minimumSum.getEmployeeName() << " " << minimumSum.getEmployeeID() << endl;
			cout << "highest  salary :" << highestSalary.salary() << " " << highestSalary.getEmployeeName() << " " << highestSalary.getEmployeeID();
			return 0;
		}
		cin >> name;
		cin >> hourlyWage >> workHours >> income;
		while (ID < 0 || hourlyWage < 0 || workHours < 0 || income < 0) // check if the number are positive for the second employee
		{
			cout << "ERROR" << endl;
			cin >> ID;
			if (ID == 0)
				break;
			cin >> name;
			cin >> hourlyWage >> workHours >> income;
		}
		firstEmployee.setEmployeeName(name);
		firstEmployee.setEmployeeIncome(income);
		firstEmployee.setEmployeeID(ID);
		firstEmployee.setEmployeeWorkHours(workHours);
		firstEmployee.setEmployeeHourlyWage(hourlyWage);
		if (firstEmployee.getEmployeeIncome() < minimumSum.getEmployeeIncome()) // keep the loast details
		{
			temp = firstEmployee;
			if (firstEmployee.salary() > highestSalary.salary())
			{
				firstEmployee = highestSalary;
				highestSalary = temp;
			}
			firstEmployee = minimumSum;
			minimumSum = temp;
		}
		else if (firstEmployee.salary() > highestSalary.salary())
		{
			temp = firstEmployee;
			firstEmployee = highestSalary;
			highestSalary = temp;
		}
		cin >> ID;
		if (ID == 0)
		{
			cout << "minimum sum:" << minimumSum.getEmployeeIncome() << " " << minimumSum.getEmployeeName() << " " << minimumSum.getEmployeeID() << endl;
			cout << "highest  salary :" << highestSalary.salary() << " " << highestSalary.getEmployeeName() << " " << highestSalary.getEmployeeID();
			return 0;
		}
		cin >>name;
		cin >> hourlyWage >> workHours >> income;
		while (ID < 0 || hourlyWage < 0 || workHours < 0 || income < 0) // check if the number are positive for the first employee
		{
			cout << "ERROR" << endl;
			cin >> ID;
			if (ID == 0)
			{
				cout << "minimum sum:" << minimumSum.getEmployeeIncome() << " " << minimumSum.getEmployeeName() << " " << minimumSum.getEmployeeID() << endl;
				cout << "highest  salary :" << highestSalary.salary() << " " << highestSalary.getEmployeeName() << " " << highestSalary.getEmployeeID();
				return 0;
			}
			cin >>name;
			cin >> hourlyWage >> workHours >> income;
		}
		secondEmployee.setEmployeeName(name);
		secondEmployee.setEmployeeIncome(income);
		secondEmployee.setEmployeeID(ID);
		secondEmployee.setEmployeeWorkHours(workHours);
		secondEmployee.setEmployeeHourlyWage(hourlyWage);
		if (secondEmployee.getEmployeeIncome() < minimumSum.getEmployeeIncome()) // keep the loast details
		{
			temp = secondEmployee;
			if (secondEmployee.salary() > highestSalary.salary())
			{
				secondEmployee = highestSalary;
				highestSalary = temp;
			}
			secondEmployee = minimumSum;
			minimumSum = temp;
		}
		else if (secondEmployee.salary() > highestSalary.salary())
		{
			temp = secondEmployee;
			secondEmployee = highestSalary;
			highestSalary = temp;
		}
		
	}
	cout << "minimum sum:" << minimumSum.getEmployeeIncome() << " " << minimumSum.getEmployeeName() << " " << minimumSum.getEmployeeID() << endl;
	cout << "highest  salary :" << highestSalary.salary() << " " << highestSalary.getEmployeeName() << " " << highestSalary.getEmployeeID();

	return 0;
}
/*
enter details, to end enter 0:
 1 aaa 50 -20 1300 1 aaa 50 20 200
ERROR
2 bbb 40 40 6555
3 ccc -40 30 0
ERROR
0
minimum sum:200 aaa 1
highest  salary :1020 aaa 1
*/