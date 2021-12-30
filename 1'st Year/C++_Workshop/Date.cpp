#include "Date.h"

Date::Date(int x, int y, int z)
{
	if (x < 1 || x > 30)
	{
		cout << "Error day" << endl;
		x = 1;
	}
	if (y < 1 || y > 12)
	{
		cout << "Error month" << endl;
		y = 1;
	}
	if (z < 1920 || z > 2099)
	{
		cout << "Error year" << endl;
		z = 1920;
	}
	day = x;
	month = y;
	year = z;
}

Date::Date(const Date& source)
{
	day = source.day;
	month = source.month;
	year = source.year;
}

Date::Date(Date&& source)
{
	day = source.day;
	month = source.month;
	year = source.year;
}

Date::~Date() {}
void Date::setDate(int x, int y, int z)
{
	if (x < 1 || x > 30)
		return;
	if (y < 1 || y > 12)
		return;
	if (z < 1920 || z > 2099)
		return;
	day = x;
	month = y;
	year = z;
}
//prefix ++
Date& Date::operator++()
{
	if (day < 30)
	{
		day++;
		return *this;//next day
	}
	else if (day == 30)
	{
		day = 1;
		if (month < 12)
		{
			month++;
			return *this; // if day is 30 and month is under 12 return day = 1 ,  month + 1
		}
		else if (month == 12)
		{
			month = 1;
			if (year < 2099)
			{
				year++;
				return *this;// if day is 30 and month is 12 return day = 1 ,  month = 1 , month + 1
			}
			else if (year == 2099)
			{
				day = 1;
				month = 1;
				year = 1920;
				return *this;// if day is 30 and month is 12  and month is 2099 , return defualt 1/1/1920
			}
		}
	}
}
//postprix++
Date Date::operator++(int none)
{
	Date result = *this;
	if (day < 30)
	{
		day++;
		return result;//next day
	}
	else if (day == 30)
	{
		day = 1;
		if (month < 12)
		{
			month++;
			return result; // if day is 30 and month is under 12 return day = 1 ,  month + 1
		}
		else if (month == 12)
		{
			month = 1;
			if (year < 2099)
			{
				year++;
				return result;// if day is 30 and month is 12 return day = 1 ,  month = 1 , month + 1
			}
			else if (year == 2099)
			{
				day = 1;
				month = 1;
				year = 1920;
				return result;// if day is 30 and month is 12  and month is 2099 , return defualt 1/1/1920
			}
		}
	}
}

Date& Date::operator+=(int days)
{
	int dayToAdd = days % 30;
	int monthToAdd = days / 30;
	int yearToAdd = monthToAdd / 12;
	monthToAdd %= 12;
	if (this->day + dayToAdd < 30)
	{
		this->day += dayToAdd;
	}
	else
	{
		this->day = (this->day + dayToAdd) - 30;
		monthToAdd++;
	}
	if (this->month + monthToAdd < 12)
	{
		this->month += monthToAdd;
	}
	else
	{
		this->month = (this->month + monthToAdd) - 12;
		yearToAdd++;
	}
	if (this->year + yearToAdd < 2099)
	{
		this->year += yearToAdd;
	}
	else
	{//defualt values 1/1/1920
		day = 1; month = 1; year = 1920;
	}
	return *this;
}

bool Date::operator>(const Date& rhs) const
{
	if (this->year > rhs.year) // this year is bigger and the date is later
		return true;
	else if (this->year < rhs.year)// this year is smaller and the date is earlyer
		return false;
	// the year is the same year , we compare between month

	if (this->month > rhs.month) // this month is bigger and the date is later
		return true;
	else if (this->month < rhs.month)// this month is smaller and the date is earlyer
		return false;
	// the month is the same month , we compare between days

	if (this->day > rhs.day) // this day is bigger and the date is later
		return true;
	else if (this->day <= rhs.day)// this day is smaller and the date is earlyer
		return false;


}

bool Date::operator<(const Date& rhs) const
{
	if (this->year < rhs.year) // this year is earlyer and the date is earlyer
		return true;
	else if (this->year > rhs.year)// this year is later and the date is later
		return false;
	// the year is the same year , we compare between month

	if (this->month < rhs.month)// this month is smaller and the date is earlyer
		return true;
	else if (this->month > rhs.month) // this month is bigger and the date is later
		return false;
	// the month is the same month , we compare between days

	if (this->day < rhs.day) // this day is smaller and the date is earlyer
		return true;
	else if (this->day >= rhs.day)// this day is bigger and the date is later
		return false;
}

bool Date::operator==(const Date& rhs) const
{
	if (this->day == rhs.day && this->month == rhs.month && this->year == rhs.year)
		return true;
	return false;
}

void Date::print()
{
	cout << day << "/" << month << "/" << year << endl;
	//bool dayFlag = false, monthFlag = false;
	//if (this->day < 10)
	//	dayFlag = true;
	//if (this->month < 10)
	//	monthFlag = true;
	//if (dayFlag == false && monthFlag == false) // no need 0 dd/mm/yyyy
	//	cout << day << "/" << month << "/" << year << endl;
	//else if (dayFlag == false && monthFlag == true)// need 0 in month  dd/0m/yyyy
	//{
	//	cout << day << "/0" << month << "/" << year << endl;
	//}
	//else if (dayFlag == true && monthFlag == false) // need 0 in day 0d/mm/yyyy
	//{
	//	cout << "0" << day << "/" << month << "/" << year << endl;
	//}
	//else if (dayFlag == true && monthFlag == true)// need 0 in day and month 0d/0m/yyyy
	//{
	//	cout << "0" << day << "/0" << month << "/" << year << endl;
	//}
}
