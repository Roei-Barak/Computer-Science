#pragma once
#include<iostream>
using namespace std;
class Employee
{
public:
	//Employee();
	Employee(string name,int id , int seniority , float pay);
	~Employee();
	friend ostream& operator<<(ostream& os, const Employee& ms);
	friend istream& operator>>(istream& is, Employee& ms);
	void setName(string n);
	void setId(int i);
	void setSeniority(int s);
	void setPay(float p);
	string getName();
	int getId();
	int getSeniority();
	float getPay();
	float salaryAfterBonus();
//--------------------------------------------------//
	string name;
	int	id;
	int seniority;
	float pay;

private:

};