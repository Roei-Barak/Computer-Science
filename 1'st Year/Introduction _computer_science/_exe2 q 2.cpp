/*
* Roei Barak
* ID 318419611
* exe 2 q 2
* */
#include<iostream>
using namespace std;
int main()
{
	cout << "enter a number:" << endl;
	int num,i = 1 ;
	cin >> num;
	int higer = 1;
	while (i < num)
	{
		if (num % i == 0)
			higer = i;
		i++;
	}
	cout << "the biggest divetion num is : " << higer;
	return 0;
}
/*
enter a number:
16
the biggest divetion num is : 8
*/