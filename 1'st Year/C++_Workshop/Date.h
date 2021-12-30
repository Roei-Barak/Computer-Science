#pragma once
#include<iostream>;
using namespace std;
class Date
{
public:
	//x = day , y = month , z= year (ctor)
	Date(int x = 1, int y = 1, int z = 1920);//ctor
	Date(const Date& source);// copy ctor
	Date(Date&& source); // move cotr 
	~Date(); // d-ctor
	void setDate(int x, int y, int z); // set new date if the value are corrcet
	Date& operator++ (); //++ prefix next day 
	Date operator++ (int none); //++ postfrix  next day 
	Date& operator+=(int days); 
	bool operator>(const Date& rhs)const;
	bool operator<(const Date& rhs)const;
	bool operator==(const Date& rhs)const;
	void print();
private:
	int day; // 1 - 30
	int month; // 1- 12
	int year; // 1920 - 2099
};
