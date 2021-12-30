#include"Employee.h"

Employee::Employee(string name, int id, int seniority, float pay) :name(name), id(id), seniority(seniority), pay(0) {};

Employee::~Employee()
{
}

void Employee::setName(string n)
{
	name = n;
}

void Employee::setId(int i)
{
	id = i;
}

void Employee::setSeniority(int s)
{
	seniority = s;
}

void Employee::setPay(float p)
{
	pay = p;
}

string Employee::getName()
{
	return name;
}

int Employee::getId()
{
	return id;
}

int Employee::getSeniority()
{
	return seniority;
}

float Employee::getPay()
{
	return pay;
}

float Employee::salaryAfterBonus()
{
	float bonus;
	if (seniority <= 5)
	{
		bonus = 500;
	}
	else
	{
		bonus = pay / 4;
	}
	return (getPay() + bonus);
}

ostream& operator<<(ostream& os, const Employee& ms)
{
	cout << "Employee: " << ms.name << "\nEmployee ID : " << ms.id << "\nYears Seniority : " << ms.seniority << endl;
	return os;
}

istream& operator>>(istream& is, Employee& ms)
{
	cout << "Enter employee details:";
	is >> ms.name;
	is >> ms.id;
	is >> ms.seniority;
	//is >> ms.pay;
	return is;
}
