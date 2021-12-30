#pragma once
#include<iostream>
using namespace std;
class Clock
{
public:
	friend ostream& operator<<(ostream& os, const Clock& c);
	friend istream& operator>>(istream& is, Clock &c);
	//ctr

	Clock(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) 
	{
		char ch;
		try
		{
			if (h > 23)
			{
				char h = 'h';
				throw h;
			}
			else if (h < 0)
			{
				int tmp = 1;
				throw tmp;
			}

		}
		catch (char h)
		{
			hour = 0; minute = 0;  second = 0;
			cout << "Wrong time format.\nInvalid time - more than 24 hours.";
		}
		catch (int tmp)
		{
			hour = 0; minute = 0;  second = 0;
			cout << "Wrong time format.\nInvalid time - negative number of hours.";
		}
		try
		{
			if (m > 59)
			{
				char m = 'm';
				throw m;
			}
			else if (m < 0)
			{
				int tmp = 1;
				throw tmp;
			}

		}
		catch (char m)
		{
			hour = 0; minute = 0;  second = 0;
			cout << "Wrong time format.\nInvalid time - more than 60 minutes.";
		}
		catch (int tmp)
		{
			hour = 0; minute = 0;  second = 0;
			cout << "Wrong time format.\nInvalid time - negative number of minutes.";
		}
		try
		{
			if (s > 59)
			{
				char s = 's';
				throw s;
			}
			else if (s < 0)
			{
				int tmp = 1;
				throw tmp;
			}

		}
		catch (char h)
		{
			hour = 0; minute = 0;  second = 0;
			cout << "Wrong time format.\nInvalid time - more than 60 seconds.";
		}
		catch (int tmp)
		{
			hour = 0; minute = 0;  second = 0;
			cout << "Wrong time format.\nInvalid time - negative number of seconds.";
		}
	}
	//copy-ctr
	Clock(const Clock& c) : hour(c.hour), minute(c.minute), second(c.second) {};

	//dstrc
	~Clock() {}; 
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);
	int getHour();
	int getMinute();
	int getSecond();
	void operator+=(int min);




private:
	int hour;
	int minute;
	int second;
};
