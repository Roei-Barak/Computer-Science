/*
*Roei Barak - ID 318419611
*Computer science Introduction
*Exe 11 -- Q 5
*/
#include <iostream>
using namespace std;
bool check(int vec[8][8], int row,int coulm)
{

	//if there is not queen in this rows
	for (int i = 0; i < 8; i++)
		if (vec[row][i] == 1)
			return false;
	//if there is not queen in left side diagonal
	for (int col = coulm, ro = row; col >= 0 && ro >= 0; ro-- && col--)//go one row up and two left
		if (vec[ro][col] == 1)
			return false;
	//if there is not queen in right side diagonal
	for (int col = coulm, ro = row; col >= 0 && ro >= 0; ro-- && col--)//go one row down and two left
		if (vec[ro][col] == 1)
			return false;

	return true;
}
bool queen(int vec[8][8], int coulm) // recrusive solve from left coulm 
{
	if (coulm == 8)
		return true;
	//try all possion can be in this coulm ( rows ) 
	for (int i = 0; i < 8; i++)
	{
		if (check(vec, i, coulm) == true) // place queen in row i and current coulm
		{
			vec[i][coulm] = 1;
			if (queen(vec, coulm + 1) == true)
				return true;
		}
		if (check(vec, i, coulm) == false) // erase the queen 
			vec[i][coulm] = 0;
	}
	return false;
}
int main()
{
	int vec[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			vec[i][j] = 0;
	}
	queen(vec, 0);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
}
/*
1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0
0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1
0 0 1 0 0 0 0 0
0 0 0 0 1 0 0 0
0 0 0 1 0 0 0 0
*/