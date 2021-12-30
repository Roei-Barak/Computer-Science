#pragma once
#include<string>
#include<iostream>
using namespace std;
class Account
{
public:
	Account(int acoNum = 0, int cod = 0, int balan = 0, string mai = "");
	~Account() {};
	void setBalance(int num);
	void setMail(string newMail);
	int getAccountNumber();
	int getCode();
	int getBalance();
	string getMail();
	friend istream& operator>>(istream& is, Account& a);
	void withdraw(int nis);
	void deposit(int sum);
	static int sumWithdraw;
	static int sumDeposit;
	static int getSumWithdraw();
	static int getSumDeposit();


private:
	int accountNumber;
	int code;
	int balance;
	string mail;
};

