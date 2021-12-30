/*
* Roei Barak
* ID 318419611
* exe 1 q 4
*/
#include<iostream>
using namespace std;
int main()
{
	char tmp;
	int counter = 0;
	int sec, min, hour, day, month, year;
	cout << "enter a date of fly:(d/m/y)" << endl;
	cin >> day >> tmp >> month >> tmp >> year;
	cout << "enter a fly time :(h/m/s)" << endl;
	cin >> hour >> tmp >> min>> tmp >> sec;
	int secFly, minFly, hourFly;
	cout << "enter a fly during :(h/m/s)" << endl;
	cin >> hourFly >> minFly >> secFly;
	int secConc, minConc, hourConc,dayConc, monthConc, yearConc;
	cout << "enter a date of conection fly:(d/m/y)" << endl;
	cin >> dayConc >> tmp >> monthConc >> tmp >> yearConc;
	cout << "enter a conection fly time :(h/m/s)" << endl;
	cin >> hourConc >> tmp >> minConc >> tmp >> secConc;
	int secTotal, minTotal, hourTotal, dayTotal,monthTotal, yearTotal;
	cin >> sec>> tmp>> min>> tmp >> hour>> tmp >> month>> tmp >> year;
	secTotal = sec + secFly;
	while (secTotal > 59)
	{
		secTotal -= 59;
		counter++;
	}
	minTotal = min + minFly + counter;
	counter = 0;
	while (minTotal > 59)
	{
		minTotal -= 59;
		counter++;
	}
	hourTotal = hour + hourFly + counter;
	counter = 0;
	while (hourTotal > 23)
	{
		hourTotal -= 23;
		counter++;
	}
	dayTotal = day + counter;
	counter = 0;
	while (dayTotal > 29)
	{
		dayTotal -= 29;
		counter++;
	}
	monthTotal = month + counter;
	counter = 0;
	while (monthTotal > 11)
	{
		monthTotal -= 11;
		counter++;
	}
	yearTotal = year + monthTotal + counter;
	counter = 0;
	if (((yearTotal <= yearConc ) || (yearTotal == yearConc && monthTotal<= monthConc ) || (yearTotal == yearConc && monthTotal == monthConc && hourTotal <= hourConc) || (yearTotal == yearConc && monthTotal == monthConc && hourTotal == hourConc && minTotal <= minConc) || (yearTotal == yearConc && monthTotal == monthConc && hourTotal == hourConc && minTotal == minConc && secTotal <= secConc)) == true)
	{
		cout << "can rich the fly";
		return true;
	}
	else
	{
		cout << "can't rich the fly";
		return false;
	}
}
