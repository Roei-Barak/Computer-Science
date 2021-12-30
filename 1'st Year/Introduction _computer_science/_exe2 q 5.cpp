/*
* Roei Barak
* ID 318419611
* exe 2 q 5
* */
#include<iostream>
using namespace std;
bool isBig(int x, int y)
{
	if (y > x)
		return true;
	else
		return false;
}

int main()
{
	cout << "enter numbers:" << endl;
	bool flag = false;
	int x, y, z, temp;
	cin >> x >> y;
	while (y <= x || flag == false)
	{
		if (y > x)
		{
			x = y;
			cin >> y;
			if (y > x)
			{
				flag = true;
				return 0;
			}
		}
		x = y;
		cin >> y;
	}
	return 0;
}
/*
enter numbers:
5 10 7 4 18 12 20 20 3 4 34
*/