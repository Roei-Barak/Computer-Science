#pragma once
#include<iostream>
using namespace std;
class Clock
{
public:
	friend ostream& operator<<(ostream& os, const Clock& c);
	friend istream& operator>>(istream& is, Clock &c);
	//ctr

	Clock(int h = 0, int m = 0, int s = 0);
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
