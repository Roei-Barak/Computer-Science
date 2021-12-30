/*
* Roei Barak
* ID 318419611
* exe 1 q 1
*/
#include<iostream>
using namespace std;
int main()
{
	int countTwenty = 0;
	int countTen = 0;
	int countTwo = 0;
	int countOne = 0;
	int countHalf = 0;
	int countAgora = 0;
	float sumToPay = 0, paySum = 0;
	cin >> sumToPay >> paySum;
	if (sumToPay <= 0 || paySum <= sumToPay )
	{
		cout << "ERROR" << endl;
		cin >> sumToPay >> paySum;
	}
	while (paySum > sumToPay)
	{
		if (paySum - 20 >= sumToPay)
		{
			paySum -= 20;
			countTwenty++;
		}
		else if (paySum - 10 >= sumToPay)
		{
			paySum -= 10;
			countTen++;
		}
		else if (paySum - 2 >= sumToPay)
		{
			paySum -= 2;
			countTwo++;
		}
		else if (paySum - 1 >= sumToPay)
		{
			paySum -= 1;
			countOne++;
		}
		else if (paySum - 0.5 >= sumToPay)
		{
			paySum -= 0.5;
			countHalf++;
		}
		else if (paySum - 0.1 >= sumToPay)
		{
			paySum -= 0.1;
			countAgora++;
		}
	
	}
	cout << countTwenty << " Banknote of 20" << endl;
	cout << countTen << " coin of 10" << endl;
	cout << countTwo << " coin of 2" << endl;
	cout << countOne << " coin of 1" << endl;
	cout << countHalf << " coin of 0.5 " << endl;
	cout << countAgora << " coin of 0.1" << endl;
}
/*
17.4
-2
ERROR
17.4
60
2 Banknote of 20
0 coin of 10
1 coin of 2
0 coin of 1
1 coin of 0.5
1 coin of 0.1
*/