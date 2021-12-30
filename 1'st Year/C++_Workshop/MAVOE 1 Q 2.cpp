/*
* Roei Barak
* ID 318419611
* exe 1 q 2
*/
#include<iostream>
using namespace std;
int main()
{
	cout << "enter a number between 1 to 9999" << endl;
	int num = 0;
	cin >> num;
	while (num > 9999)
	{
		cout << "ERROR" << endl;
		cin >> num;
	}
	int sumDig = 0, count = 0;
	while (num > 0)
	{
		sumDig += num % 10;
		num /= 10;
		count++;
	}
	int averg = sumDig / count;
	cout << "averga num is : " << averg;

	return 0;

}
/*enter a number between 1 to 9999
9999
averga num is : 9
*/