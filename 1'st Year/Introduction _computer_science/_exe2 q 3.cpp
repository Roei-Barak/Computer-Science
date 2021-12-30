/*
* Roei Barak
* ID 318419611
* exe 2 q 3
* */
#include<iostream>
using namespace std;
int main()
{
	cout << "enter a number : " << endl;
	int num, count = 0, temp;
	bool flag = false;
	cin >> num;
	temp = num;
	while (temp > 10)
	{
		temp /= 10;
		count++;
	}
	if (temp == 10)
		count += 2;
	else if (temp > 0)
	{
		count++;
	}
	temp = num;
	while (temp > 10)
	{
		if ((temp % 10) == count)
		{
			flag = true;
			break;
		}
		temp /= 10;
	}
	if (temp > 0)
	{
		if ((temp % 10) == count)
		{
			flag = true;
		}
	}
	(flag == true) ? cout << "Yes" : cout << "No";
	return 0;
}
/*
enter a number :
12345
Yes
*/