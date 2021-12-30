/*
*Roei Barak - ID 318419611
*Computer science Introduction
*Q8.1
*/
#include <iostream>
using namespace std;
int fun_jump(int* big, int* small, int big_size, int small_size)
{
	if (small_size ==1)
	{
		for (int r =0; r < big_size; r++)
		{
			if (*(small) == *(big+r))
			{
				return 0;
			}
		}
	}
	bool flag = true;
	int jump = 0, k = 0;
	int* ptr_first_value = &jump;
	int* ptr_second_value = &jump;
	while (*big > -1 && big < (big + big_size)&&small_size> 1)
	{
		// check if the first number in small array are in the big array
		for (int i = k; i < big_size; i++)
		{
			if (*small == *(big + i))
			{
				flag = true;
				ptr_first_value = big + i;
				break;
			}
			else
				flag = false;
		}
		//if flag false the small array isn`t in big array
		if (flag == false)
			return -1;
		//check the jump
		// check if the second number in small array are in the big array
		for (int j = 1; j < big_size; j++)
		{
			if (*(small + 1) == *(ptr_first_value + j))
			{
				flag = true;
				jump = j;
				break;
			}
			else
			{
				flag = false;
			}
		}
		//if flag false the small array isn`t in big array
		if (flag == false)
			return -1;

		//check if the numbers in small array are in the big array
		//and return the jump between them
		for (int i = 0; i < small_size; i++)
		{
			if (*(small + i) != *(ptr_first_value + (i * jump)))
			{
				flag = false;
				break;
			}
			else
				flag = true;
		}
		if (flag == true)
			return jump;
		big++;
		k++;
	}
	return -1;
}
int main()
{
	int bigarray[80]; int smallarray[80]; int big_size, small_size;
	cout << "Enter the size of big:" << endl;
	cin >> big_size;
	cout << "Enter " << big_size << " numbers:" << endl;
	for (int i = 0; i < big_size; i++)
	{
		cin >> bigarray[i];
	}
	cout << "Enter the size of small:" << endl;
	cin >> small_size;
	cout << "Enter " << small_size << " numbers:" << endl;
	for (int i = 0; i < small_size; i++)
	{
		cin >> smallarray[i];
	}
	int jump = fun_jump(bigarray, smallarray, big_size, small_size);
	if (jump > 0)
		jump--;
	cout << "Size of jump: " << "\n" << jump;
	return 0;
}
/*Enter the size of big:
17
Enter 17 numbers:
1 2 2 1 5 8 2 5 4 3 5 8 3 5 1 2 7
Enter the size of small:
3
Enter 3 numbers:
1 2 3
Size of jump:
2
*/