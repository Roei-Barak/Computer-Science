#include "FullTime.h"
FullTime::FullTime(string name, int id, int seniority, float pay, float yea) : Employee(name, id, seniority, pay), yearlySalary(yea) {}
FullTime::~FullTime(){}
void FullTime::setYealySalary(float y)
{
	yearlySalary = y;
}

float FullTime::getYealySalary()
{
	return yearlySalary;
}

int FullTime::salary()
{
	int temp = yearlySalary / 12;
	Employee::setPay(temp);
	return temp;
}
ostream& operator<<(ostream& os, const FullTime& ms)
{
	cout << "Employee: " << ms.name << "\nEmployee ID : " << ms.id << "\nYears Seniority : " << ms.seniority << "\nSalary per Month: " << ms.pay << endl;
	return os;
}

istream& operator>>(istream& is, FullTime& ms)
{
	is >> (Employee&)ms;
	is >> ms.yearlySalary;
	ms.salary();
	if (ms.id <= 0 || ms.name == "" ||ms.seniority < 0 || ms.yearlySalary < 0 )
		throw "ERROR";
	return is;
}
