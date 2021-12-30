#pragma once
#include<iostream>
#include <string>
#include <vector>
using namespace std;
class Volunteer
{

public:
	string 	Name;
	string Address;
	int phoneNumber;
	vector<string> clnt;

	Volunteer(string n = "", string a = "", int p = 0) :Name(n), phoneNumber(p), Address(a) {};
	Volunteer(const Volunteer& v);//copy-ctor
	~Volunteer() {};
	Volunteer& operator=(const Volunteer& v);
	bool operator==(const Volunteer& v)const;
	friend istream& operator>>(istream& is, Volunteer& v);
	friend ostream& operator<<(ostream& os, const Volunteer& v);
};


istream& operator>>(istream& is, Volunteer& v)
{
	cout << "Enter volunteer name phone address\n";
	is >> v.Name;
	is >> v.phoneNumber;
	is >> v.Address;
	return is;
}

ostream& operator<<(ostream& os, const Volunteer& v)
{
	os << v.Name << ":volunteer name=" << v.Name << " pnone=" << v.phoneNumber << " address=" << v.Address << endl;
	return os;
}
inline Volunteer::Volunteer(const Volunteer& v)
{
	Name = v.Name;
	phoneNumber = v.phoneNumber;
	Address = v.Address;
}

inline Volunteer& Volunteer::operator=(const Volunteer& v)
{

	Name = v.Name;
	Address = v.Address;
	phoneNumber = v.phoneNumber;
	return *this;

}

bool Volunteer::operator==(const Volunteer& v)const
{
	return (v.Name == Name);
}
