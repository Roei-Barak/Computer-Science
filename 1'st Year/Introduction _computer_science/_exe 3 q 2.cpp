/*
* Roei Barak
* ID 318419611
* exe 3 q 2
* */
#include<iostream>
#include<cmath>
using namespace std;
int addOne(int num)
{
	int temp = num, newNum = 0, counter = 1;
	while (temp > 0)
	{
		if (((temp % 10) + 1) == 10)
		{
			counter *= 10;
			temp /= 10;
			continue;
		}
		newNum += ((temp % 10) + 1) * counter;
		counter *= 10;
		temp /= 10;
	}
	return newNum;
}
int main()
{
	int num;
	cout << "enter a num :" << endl;
	cin >> num;
	cout << addOne(num);

	return 0;
}
/*
enter a num :
309
410
*/
