/*
* Roei Barak
* ID 318419611
* exe 2 q 5
* */
#include<iostream>
using namespace std;
bool check(int num, int num2)
{
	int count = 0, temp;
	temp = num2;
	while (temp > 10)
	{
		temp /= 10;
		count++;
	}
	(temp == 10) ? count += 2 : count++;
	for (int i = 0; i < count; i++)
	{
		if ((num2 % 10) == num)
			return true;
		else
			num2 /= 10;
	}
	return false;
}
int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	int count = 0, temp;
	temp = num1;
	while (temp > 10)
	{
		temp /= 10;
		count++;
	}
	(temp == 10) ? count += 2 : count++;
	for (int i = 0; i < count; i++)
	{
		if (check(num1 % 10, num2) == false)
		{
			cout << "no";
			return 0;
		}
		num1 /= 10;
	}
	cout << "yes";
	return 0;
}
/*
558
538
yes
*/