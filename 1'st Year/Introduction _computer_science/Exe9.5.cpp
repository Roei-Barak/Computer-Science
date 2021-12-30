/****************
*	Roei Barak	*
*	318419611	*
*	Exe 9 Q	5	*
****************/
#include <iostream>
using namespace std;
int rec(int num);
int main()
{
    cout << "How many stair ? ";
    int num;
    cin >> num;
    cout << "There is a " << rec(num) << " diffrent options.";
	return 0;
}


int rec(int n)
{
    if (n == 1 || n == 0)
        return 1;
    else if (n == 2)
        return 2;
    else
        return  rec(n - 2) + rec(n - 1);
}

/**************************************************
*	How many stair ? 6                            *
*    There is a 13 diffrent options.			  *
**************************************************/
