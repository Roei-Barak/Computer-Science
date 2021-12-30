#include "Account.h"

int Account::sumWithdraw = 0;
int Account::sumDeposit = 0;

istream& operator>>(istream& is, Account& a)
{
	//try
	//{
		is >> a.accountNumber;
		is >> a.code;
		is >> a.mail;
		if (a.code < 1000 || a.code >9999)
		{
			throw "ERROR: code must be of 4 digits!";
		}
		size_t found = (a.mail).find("@");
		if (found == -1)
		{
			throw "ERROR: email must contain @!";

		}
		//if ((a.mail).find('@') != (a.mail).rfind('@') || (a.mail).find('@') <= 0) // one @ only after charther
		//{
		//	throw "ERROR: email must contain @!";
		//}
		found = (a.mail).find(".com");
		if (found == -1)
		{
			found = (a.mail).find(".co.il");
			if (found == -1)
			{
				throw "ERROR: email must end at .com or .co.il!";
			}
		}
		//if (((a.mail).find(".com") < 3) && ((a.mail).find(".co.il") < 3)) // a@a .com/.co.il
		//{
		//	throw "ERROR: email must end at .com or .co.il!";
		//}
		//if ((a.mail).find(" ")) // space not allow
		//{
		//	throw "ERROR: wrong email!";
		//}
			return is;
	//}
	//catch (const char* msg)
	//{
	//	cout << msg << endl;
	//}
}

Account::Account(int acoNum, int cod, int balan, string mai)
{
	if (acoNum == 0 && cod == 0 && balan == 0 && mai == "")
	{
		accountNumber = 0; code = 0; balance = 0; mail = "";
	}
	else
	{
		if (code < 1000 || code > 9999)
		{
			accountNumber = 0; code = 0; balance = 0; mail = "";
			throw "ERROR: code must be of 4 digits!";
		}
		if (!(mai.find('@') == mai.rfind('@') && mai.find('@') > 0)) // one @ only after charther
		{
			accountNumber = 0; code = 0; balance = 0; mail = "";
			throw "ERROR: email must contain @!";
		}
		if (mai.find(' ')) // space not allow
		{
			accountNumber = 0; code = 0; balance = 0; mail = "";
			throw "ERROR: wrong email!";
		}
		if ((mai.find(".com") < 3) && (mai.find(".co.il") < 3)) // a@a .com/.co.il
		{
			accountNumber = 0; code = 0; balance = 0; mail = "";
			throw "ERROR: email must end at .com or .co.il!";
		}

	}
}

void Account::setBalance(int num)
{
	balance = num;
}

void Account::setMail(string newMail)
{

	if (!(newMail.find('@') == newMail.rfind('@') && newMail.find('@') > 0)) // one @ only after charther
	{
		accountNumber = 0; code = 0; balance = 0; mail = "";
		throw "ERROR: wrong email!";
	}
	if (newMail.find(' ')) // space not allow
	{
		accountNumber = 0; code = 0; balance = 0; mail = "";
		throw "ERROR: wrong email!";
	}
	if ((newMail.find(".com") < 3) && (newMail.find(".co.il") < 3)) // a@a .com/.co.il
	{
		accountNumber = 0; code = 0; balance = 0; mail = "";
		throw "ERROR: wrong email!";
	}
	else
	{
		mail = newMail;
	}
}
int Account::getAccountNumber()
{
	return accountNumber;
}

int Account::getCode()
{
	return code;
}

int Account::getBalance()
{

	return balance;
}

string Account::getMail()
{
	return mail;
}

void Account::withdraw(int nis)
{
	
	if ((balance - nis) <= -6000)
	{
		throw "ERROR: cannot have less than - 6000 NIS!";
	}
	if (nis > 2500)
	{
		throw "ERROR: cannot withdraw more than 2500 NIS!";
	}
		balance -= nis;
		sumWithdraw += nis;
}

void Account::deposit(int sum)
{
	if (sum > 10000)
	{
		throw  "ERROR: cannot deposit more than 10000 NIS!";
	}
	else
	{
		balance += sum;
		sumDeposit += sum;
	}
}

int Account::getSumWithdraw()
{
	return sumWithdraw;
}

int Account::getSumDeposit()
{
	return sumDeposit;
}
