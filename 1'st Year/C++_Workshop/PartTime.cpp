#include "PartTime.h"

PartTime::PartTime(string name, int id, int seniority, float pay, int h, float pfh) : Employee(name, id, seniority, pay), hour(h), payForHour(pfh) {}

PartTime::~PartTime() {}

void PartTime::setPayForHour(float pfh)
{
	payForHour = pfh;
}

void PartTime::setHour(int h)
{
	hour = h;
}

float PartTime::getPayForHour()
{
	return payForHour;
}

int PartTime::getHour()
{
	return hour;
}

float PartTime::salary()
{
	Employee::setPay(payForHour * hour);
	return payForHour * hour;
}

ostream& operator<<(ostream& os, const PartTime& ms)
{
	cout << "Employee: " << ms.name << "\nEmployee ID : " << ms.id << "\nYears Seniority : " << ms.seniority << "\nHours: "<< ms.hour<<"\nSalary per Month: " << ms.hour * ms.payForHour << endl;
	return os;
}

istream& operator>>(istream& is, PartTime& ms)
{
	is >> (Employee&)ms;
	is >> ms.hour;
	is >> ms.payForHour;
	ms.salary();
	if (ms.id <= 0 || ms.name == "" || ms.seniority < 0 || ms.hour <= 0 || ms.payForHour <= 0)
		throw "ERROR";

	return is;
}
