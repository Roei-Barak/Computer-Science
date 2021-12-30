#include "Clock.h"
#include<iostream>

Clock::Clock(int h, int m, int s)
{
	/*try
	{*/
		if (h > 23)
		{
			throw "Wrong time format.\nInvalid time - more than 24 hours.";
		}
		else if (h < 0)
		{
			throw "Wrong time format.\nInvalid time - negative number of hours.";
		}

	//}
	//catch (const char* msg)
	//{
	//	hour = 0; minute = 0;  second = 0;
	//	cout << msg;
	//}
	//try
	//{
		if (m > 59)
		{
			throw "Wrong time format.\nInvalid time - more than 60 minutes.";

		}
		else if (m < 0)
		{
			throw "Wrong time format.\nInvalid time - negative number of minutes.";
		}

	//}
	//catch (const char* msg)
	//{
	//	hour = 0; minute = 0;  second = 0;
	//	cout << msg << endl;
	//}
	//try
	//{
		if (s > 59)
		{
			throw "Wrong time format.\nInvalid time - more than 60 seconds.";
		}
		else if (s < 0)
		{
			throw "Wrong time format.\nInvalid time - negative number of seconds.";
		}

	/*}
	catch (const char* msg)
	{
		hour = 0; minute = 0;  second = 0;
		cout << msg << endl;
	}*/
		hour = h; minute = m; second = s;
}

void Clock::setHour(int h)
{
	if (h < 0 || h > 23)
	{
		hour = 0; minute = 0;  second = 0;
		return;
	}
	hour = h;
}

void Clock::setMinute(int m)
{
	if (m < 0 || m  > 59)
	{
		hour = 0; minute = 0;  second = 0;
		return;
	}
	minute = m;
}

void Clock::setSecond(int s)
{
	if (s < 0 || s > 59)
	{
		hour = 0; minute = 0;  second = 0;
		return;
	}
	second = s;
}

int Clock::getHour()
{
	return hour;
}

int Clock::getMinute()
{
	return minute;
}

int Clock::getSecond()
{
	return second;
}

void Clock::operator+=(int sec)
{
	second += sec;
	while (second > 59)
	{
		minute++;
		second -= 60;
	}
	while (minute > 59)
	{
		hour++;
		minute -= 60;
	}
	if (hour > 23)
	{
		hour = hour % 24;
	}
}

ostream& operator<<(ostream& os, const Clock& c)
{
	if (c.hour < 10)
		os << '0' << c.hour;
	else
		os << c.hour;
	os << ':';
	if (c.minute < 10)
		os << '0' << c.minute;
	else
		os << c.minute;
	os << ':';
	if (c.second < 10)
		os << '0' << c.second;
	else
		os << c.second;
	return os;
}

istream& operator>>(istream& is, Clock& c)
{
	//try
	//{
		is >> c.hour;
		if (c.hour > 23)
		{
			throw "Wrong time format.\nInvalid time - more than 24 hours.";
		}
		else if (c.hour < 0)
		{
			throw "Wrong time format.\nInvalid time - negative number of hours.";
		}

	/*}*/
	//catch (const char* msg)
	//{
	//	c.hour = 0; c.minute = 0;  c.second = 0;
	//	cout << msg;
	//}
	/*try
	{*/
		is >> c.minute;
		if (c.minute > 59)
		{
			throw "Wrong time format.\nInvalid time - more than 60 minutes.";
		}
		else if (c.minute < 0)
		{
			throw  "Wrong time format.\nInvalid time - negative number of minutes.";
		}
	/*}
	catch (const char* msg)
	{
		c.hour = 0; c.minute = 0;  c.second = 0;
		cout << msg;
	}*/
	/*try
	{*/
		is >> c.second;
		if (c.second > 59)
		{
			throw "Wrong time format.\nInvalid time - more than 60 seconds.";
		}
		else if (c.second < 0)
		{
			throw "Wrong time format.\nInvalid time - negative number of seconds.";
		}

	/*}
	catch (const char* msg)
	{
		c.hour = 0; c.minute = 0;  c.second = 0;
		cout << msg;
	}*/
	return is;
}
