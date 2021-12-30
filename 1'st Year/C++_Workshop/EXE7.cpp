/************************
*	Roei Barak			*
*	318419611			*
*	Exe 7 Q	1			*
*						*
*						*
*************************/
#include <iostream>
#include"Shape.h"
#include"Circle.h"
#include"Triangle.h"
#include"Rectangle.h"
using namespace std;

int main()
{
	cout << "How many shapes you would like to define?" << endl;
	int num,size; 
	cin >> size;
	Shape** arr = new Shape*[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
		{
			cout << "Enter radius:" <<endl;
			cin >> num;
			arr[i] = new Circle (num);
			break;
		}
		case 3:
		{
			arr[i] = new Triangle();
			break;
		}
		case 4:
		{
			arr[i] = new Rectangle();
			break;
		}
		default:
			cout << "invalid input" << endl;
			i--;
			break;
		}
	}
	for (int i = 0; i < size ; i++)
	{
		cout << *arr[i];
		cout <<"area is: " << arr[i]->area() << endl;
		if (arr[i]->isSpecial())
		{
			arr[i]->printSpecial();
		}
	}
	return 0;
}
/*
How many shapes you would like to define?
 5
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4
4
Enter values of 4 points:
(0,0) (0,1) (1,1) (1,0)
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4
3
Enter values of 3 points:
(1,1) (2,3) (3,1)
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4
2
invalid input
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4
1
Enter radius:
3
Enter values of 1 points:
(2,5)
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4
1
Enter radius:
7
Enter values of 1 points:
(0,0)
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4
4
Enter values of 4 points:
(1,2) (1,5) (5,5) (5,2)
points: (0,0) (0,1) (1,1) (1,0) area is: 1
Square with side length 1
*/

