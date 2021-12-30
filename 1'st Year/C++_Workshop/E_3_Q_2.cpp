/*
Roei Barak 318419611
C++ סדנא
E - 3 --- Q - 2
*/
#include"Date.h"
#include<iostream>
using namespace std;
int main()
{
	char a;
	//Date chosenDate;
	int dozens, unity,day,month,year,chose,tmp; Date temp;
	cout << "Enter a date" << endl;
	cin >> day >> a >> /*get day*/ month >> a /* get month*/ >> year; // get year
	Date chosenDate(day, month, year);
	chosenDate.print();
	cout << "Enter an action code : " << endl;
	cin >> chose;
	while (chose != -1)
	{
		switch (chose)
		{
		case 1:
		{
			cout << "Enter a date" << endl;
			cin >> day >> a >> /*get day*/ month >> a /* get month*/ >> year; // get year
			chosenDate.setDate(day, month, year);
			chosenDate.print();
			break;
		}
		case 2:
		{
			(++chosenDate).print();
			break;
		}
		case 3:
		{
			(chosenDate++).print();
			break;
		}
		case 4:
		{
			cout << "Enter # days" << endl;
			cin >> tmp;
			chosenDate += tmp;
			chosenDate.print();
			break;
		}
		case 5:
		{
			cout << "Enter a date" << endl;
			cin >> day >> a >> /*get day*/ month >> a /* get month*/ >> year; // get year
			temp.setDate(day,month,year);
			cout << ">:" << ((chosenDate > temp) ? "true" : "false")<< endl;
			break;
		}
		case 6:
		{
			cout << "Enter a date" << endl;
			cin >> day >> a >> /*get day*/ month >> a /* get month*/ >> year; // get year
			temp.setDate(day, month, year);
			if (chosenDate < temp)
				cout << "<:true" << endl;
			else
				cout << "<:false" << endl;
			break;
		}
		case 7:
		{
			cout << "Enter a date" << endl;
			cin >> day >> a >> /*get day*/ month >> a /* get month*/ >> year; // get year
			temp.setDate(day, month, year);
			cout << "==:" << ((chosenDate == temp) ? "true" : "false") <<endl;
			break;
		}
		default:
			break;
		}
		cout << "Enter an action code :" << endl;
		cin >> chose;
	}
}
/*
Enter a date
-5/1/2012
Error day
01/01/2012
What do you want to do
1
Enter a date
5/7/2010
05/07/2010
What do you want to do
2
06/07/2010
What do you want to do
3
06/07/2010
What do you want to do
4
Enter # days
7
14/07/2010
What do you want to do
5
Enter a date
14/7/2010
>:false
What do you want to do
7
Enter a date
10/7/2010
==:false
What do you want to do
7
Enter a date
14/7/2010
==:true
What do you want to do
-1

*/