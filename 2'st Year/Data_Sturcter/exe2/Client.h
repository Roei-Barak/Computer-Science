#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Client
{

public:
	string Name;
	string Address;
	int phone;
	vector<string> vltr;
	
	Client(string n = "", string a = "", int p = 0);
	~Client() {};
	Client& operator=(const Client& clnt);
	bool operator==(const Client& clnt)const;
	friend istream& operator>>(istream& is, Client& c);
	friend ostream& operator<<(ostream& os, const Client& c);
	int GetPhone() { return phone; }

};

Client::Client(string n, string a, int p) : Name(n), Address(a), phone(p)
{

}

Client& Client::operator=(const Client& clnt)
{
	Name = clnt.Name;
	phone = clnt.phone;
	Address = clnt.Address;

	return *this;
	// TODO: insert return statement here
}

bool Client::operator==(const Client& clnt) const
{
	if (phone == clnt.phone)
		return true;
	return false;
}

istream& operator>>(istream& is, Client& c)
{
	cout << "please enter name and phone and address of client\n";
	is >> c.Name;
	is >> c.phone;
	is >> c.Address;
	return is;
}

ostream& operator<<(ostream& os, const Client& c)
{
	os << c.phone << ":client name= " << c.Name << " pnone= " << c.phone << " address= " << c.Address << endl;
	return os;
}
