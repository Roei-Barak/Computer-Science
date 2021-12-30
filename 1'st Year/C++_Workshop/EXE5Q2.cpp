/*
* Roei Barak
* 318419611
* C++ Workshop
* EXE 5.2
*/

#include <iostream>
#include "List.h"
using namespace std;
List merge(List a,List b)
{
	List newMer (a);
	while (!b.isEmpty())
	{
		newMer.insert(b.firstElement());
		b.removeFirst();
	}
	return newMer;
}
void makeSet(List& a)
{
	int value = 0;
	List tmp,r;
	while (!a.isEmpty())
	{
		value = a.firstElement();
		a.removeFirst();
		if (a.search(value)) // the value is doble show
			continue;
		tmp.insert(value);
	}
	a = tmp;
}
void reverse(List& a)
{
	int value = 0;
	List tmp;
	while (!a.isEmpty())
	{
		value = a.firstElement();
		a.removeFirst();
		tmp.add(value);
	}
	a = tmp;
}
int main()
{
	List lst1, lst2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;
	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	reverse(mergedList);
	cout << "the new merged reverse: " << mergedList << endl;


	return 0;
}
/*
enter sorted values for the first list:
6 5 4 3 2 1 9
enter sorted values for the second list:
7 5 4 3 9
the new merged list: 7 6 5 5 4 4 3 3 2 1
the new merged set: 7 6 5 4 3 2 1
the new merged reverse: 1 2 3 4 5 6 7

*/