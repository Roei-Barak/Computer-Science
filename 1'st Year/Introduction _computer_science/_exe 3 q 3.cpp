/*
* Roei Barak
* ID 318419611
* exe 3 q 3
* */
#include<iostream>
using namespace std;
void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
int lenth(int num)
{
	int temp = num, counter = 0;
	while (temp)
	{
		counter++;
		temp /= 10;
	}
	return counter;
}
int exitNum(int num, int numToExclude)
{
	int newNum = 0, counter = 0;
	while (num)
	{
		if (num % 10 == numToExclude)
		{
			num /= 10;
			continue;
		}
		(!counter) ? newNum += (num % 10) : newNum += (num % 10) * pow(10,counter);
		counter++;
		num /= 10;
	}
	return newNum;
}
int sortted(int num)
{
	int temp = num, min, max, newNum = 0, counter = 0;
	while (temp)
	{
		max = temp % 10;
		while (temp)
		{
			temp /= 10;
			min = temp % 10;
			if (min > max)
			{
				swap(min, max);
			}
		}
		temp = num = exitNum(num, max);
		(!counter)? newNum += max : newNum += pow(10, counter)* max;
		counter++;
	}
	return newNum;
}
int main()
{
	cout << "Enter a number: " << endl;
	int num;
	cin >> num;
	cout << sortted(num);
	return 0;
}
/*
Enter a number:
804621
12468
*/