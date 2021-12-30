///************************
//*	Roei Barak			*
//*	318419611			*
//*	Exe 6 Q	3			*
//*						*
//*						*
//*************************/
//#include <iostream>
//#define SIZE 5
////int vec = *((*(arr+1))+1);
//using namespace std;
////int check(int vec[SIZE][SIZE], int row, int coul);
////int isSort(int* arr, int size,int start);
//void swap(int& a, int& b) { int temp = a; a = b; b = temp; };
//bool isBig(int a, int b) { bool flag;  a >= b ? flag = true : flag = false; return flag; }
//void print(int** arr, int row, int coul);
//int sortArr(int* arr, int coul);
//bool nextRow(int* a, int* b);
//void fun(int arr[3][5], int a, int b);
//int ceil(int** arr, int row, int coul) { return row * coul; }
////int main()
////{
////	enum row
////	{
////		r1, r2, r3, r4, r5, r6, r7, r8, r9, r10
////	};
////	enum coul
////	{
////		c1, c2, c3, c4, c5, c6, c7, c8, c9, c10
////	};
////	int arr[3][5] = {
////		{62,1,2,22,2},
////		{9,3,4,8,32},
////		{64,5,6,7,67}
////	};
////	int* frsPtr;
////	int* lstPtr;
////	int temp = 0;
////	int max = 0;
////	int cntR = 1;
////	max = temp = sortArr(arr[0], c2);
////	while (!isBig(arr[cntR - 1 + 1][c2], arr[cntR - 1][c2 + temp]))
////	{
////		temp--;
////	}
////	cntR++;
////	int total = 0;
////	if (sortArr(arr[cntR - 1], c2) > temp)
////	{
////		total = cntR * temp;
////	}
////	else if (sortArr(arr[cntR - 1], c2) <= temp)
////	{
////		total = cntR * sortArr(arr[cntR - 1], c2);
////	}
////	if (total > max)
////	{
////		swap(total, max);
////	}
////
////
////	for (int i = 0; i < 3; i++)
////	{
////		for (int k = 0; k < 5; k++)
////		{
////
////		}
////	}
////
////	return 0;
////}
//void print(int** arr, int row, int coul)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int k = 0; k < coul; k++)
//			cout << *((*(arr + i)) + k) << ",";
//		cout << endl;
//	}
//}
////int check(int vec[SIZE][SIZE], int row, int coul)
////{
////	int max = isSort(vec[row], SIZE - coul,coul);//first sortted array 
////	for (int i = row; i < SIZE - row; i++)// check if the new array in bigger then max array
////	{
////		int temp = isSort(vec[i], SIZE - coul, coul);
////		//[1][2][3][4]   i = 0
////		//[5][6][7][1]	 i = 1 temp = 3 total array = 1 2 3 4 5 6 == temp*(i+1)
////		if (vec[i])
////		{
////
////		}
////		if ((temp*(i+1))>max)
////			{
////				swap(temp, max);
////			}
////	}
////	return 0;
////}
////int isSort(int* arr, int size,int start)
////{
////	int counter = 0;
////	for (int i = 0; i < size - 1; i++)
////	{
////		if (*(arr + i + 1+ start) >= *(arr + i+ start))
////			counter++;
////		else
////			break;
////	}
////	return counter;
////}
//int sortArr(int* arr, int coul)
//{
//	int counter = 0;
//	for (int i = coul; i < SIZE - 1; i++)
//	{
//		if (*(arr + i) <= *(arr + 1 + i))
//		{
//			counter++;
//		}
//		else
//		{
//			break;
//		}
//
//	}
//	return counter;
//}
//bool nextRow(int* a, int* b)
//{
//	if (*b < *a)
//		return false;
//	return true;
//}
//void fun(int arr[3][5], int a, int b)
//{
//	int cntR = 1;
//	int temp;
//	int max;
//	temp = max = sortArr(arr[0], 1);
//	
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			while (!isBig(arr[i + 1][j], arr[i][j+temp]))
//			{
//				temp--;
//			}
//			i++;
//			int total = 0;
//			if (sortArr(arr[cntR - 1], c2) > temp)
//			{
//				total = cntR * temp;
//			}
//			else if (sortArr(arr[cntR - 1], c2) <= temp)
//			{
//				total = cntR * sortArr(arr[cntR - 1], c2);
//			}
//			if (total > max)
//			{
//				swap(total, max);
//			}
//		}
//	}
//}