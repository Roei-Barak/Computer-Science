#include"Rational.h"
#include <iostream>
using namespace std;

//bool Rational::equal(Rational num)
//{
//	double firstNum = (double)numerator / denominator;
//	double secNum = (double)num.numerator / num.denominator;
//	if (firstNum == secNum)
//		return true;
//	else
//		return false;
//}
Rational Rational::reduction(Rational num)
{
	Rational temp = num;
	if (temp.numerator == temp.denominator)
	{
		temp.numerator = 1;
		temp.denominator = 1;
		return temp;
	}
	else
	{
		for (int i = 10; i > 1; i--)
		{
			if (temp.denominator % i == 0 && temp.numerator % i == 0)
			{
				temp.denominator /= i;
				temp.numerator /= i;
				i = 10; // keep the loop
			}
		}
	}
	return temp;
}
void Rational::print()
{
	if (this->numerator == this->denominator)
	{
		numerator = 1;
		denominator = 1;
	}
	else
	{
		for (int i = 10; i > 1; i--)
		{
			if (denominator % i == 0 && numerator % i == 0)
			{
				denominator /= i;
				numerator /= i;
				i = 10; // keep the loop for more reduce
			}
		}
	}
	if (denominator == 1 || numerator == 0 )
	{
		cout << numerator; // print only numerator
	}
	else
	{
		cout << numerator << "/" << denominator;
	}
	
}

Rational::Rational(int myMone, int myMechane)
{
	if (!myMechane) // not dividing in zero
	{
		cout << "ERROR" << endl;
		numerator = myMone;
		denominator = 1;

	}
	else
	{
		numerator = myMone;
		denominator = myMechane;
	}
}

// a/b + c/d = (a*d + c*b)/(b*d)
Rational Rational::operator +(const Rational& rhs) const
{
	Rational resualt(this->numerator * rhs.denominator + rhs.numerator * this->denominator, this->denominator * rhs.denominator);
	return resualt;
}
// a/b - c/d = (a*d - c*b)/(b*d)

Rational Rational::operator-(const Rational& rhs) const
{
	Rational resualt(this->numerator * rhs.denominator - rhs.numerator * this->denominator, this->denominator * rhs.denominator);
	return resualt;
}
// a/b + n = (a + n*b) / (b)
Rational Rational::operator+(const int& rhs) const
{
	Rational resualt(this->numerator  + rhs * this->denominator, this->denominator);
	return resualt;
}
// a/b + c/d = (a*c) / (b*d)
Rational Rational::operator*(const Rational& rhs) const
{
	Rational resualt(this->numerator * rhs.numerator, this->denominator * rhs.denominator);
	return resualt;
}
// a/b + c/d = (a*d) / (b*c)
Rational Rational::operator/(const Rational& rhs) const
{
	Rational resualt(this->numerator * rhs.denominator, this->denominator * rhs.numerator);
	return resualt;
}
// ++a/b = a/b +1 = (a+b)/b
Rational& Rational::operator++()
{ 
	this->numerator += this->denominator;
	return *this;
}
// a/b++ = a/b +1 = (a+b)/b
Rational Rational::operator++(int)
{
	Rational result = *this;
	this->numerator += this->denominator;
	return result;
}
// --a/b = a/b - 1 = (a-b)/b
Rational& Rational::operator--()
{
	this->numerator -= this->denominator;
	return *this;
}
// a/b-- = a/b - 1 = (a-b)/b
Rational Rational::operator--(int)
{
	Rational result = *this;
	this->numerator -= this->denominator;
	return result;
}
// a/b == c/d (a/b = x && c/d = x )
bool Rational::operator==(const Rational& rhs) const
{
	double firstNum = (double)numerator / denominator;//reduced
	double secNum = (double)rhs.numerator / rhs.denominator;//reduced
	if (firstNum == secNum) // check the reduced frachion are the same
		return true;
	else
		return false;
}
bool Rational::operator!=(const Rational& rhs) const
{
	double firstNum = (double)numerator / denominator;//reduced
	double secNum = (double)rhs.numerator / rhs.denominator;//reduced
	if (firstNum != secNum) // check the reduced frachion are the same
		return true;
	else
		return false;
}
// a/b >= c/d (a/b = x , c/d = y -> x >= y )

bool Rational::operator>=(const Rational& rhs) const
{
	double firstNum = (double)numerator / denominator; // reduced
	double secNum = (double)rhs.numerator / rhs.denominator; // reduced
	if (firstNum >= secNum) // check the reduced frachion of the object are equal or bigger
		return true;
	else
		return false;
}

bool Rational::operator>(const Rational& rhs) const
{
	double firstNum = (double)numerator / denominator; // reduced
	double secNum = (double)rhs.numerator / rhs.denominator; // reduced
	if (firstNum > secNum) // check the reduced frachion of the object are equal or bigger
		return true;
	else
		return false;
}

bool Rational::operator<=(const Rational& rhs) const
{
	double firstNum = (double)numerator / denominator; // reduced
	double secNum = (double)rhs.numerator / rhs.denominator; // reduced
	if (firstNum <= secNum) // check the reduced frachion of the object are equal or lower
		return true;
	else
		return false;
}

bool Rational::operator<(const Rational& rhs) const
{
	double firstNum = (double)numerator / denominator; // reduced
	double secNum = (double)rhs.numerator / rhs.denominator; // reduced
	if (firstNum < secNum) // check the reduced frachion of the object are equal or lower
		return true;
	else
		return false;
}
