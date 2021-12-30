#include"Private.h"

bool Private::medal()
{
	if (operations >= 10)
	{
		float sum = 0;
		for (int i = 0; i < operations; i++)
		{
			sum += grades[i];
		}
		if ((float)sum / operations > 95)
			return true;
		else
			return false;
	}
	return false;
}

void Private::print()
{
	cout << "private" << endl;
	cout << "ID: " << id << endl;
	cout << "first name: " << firstName << endl;
	cout << "last name: " << lastName << endl;
	cout << "num operations: " << operations << endl;
	cout << "grades: ";
	vector<int>::iterator it2 = grades.begin();
	while (it2 != grades.end())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
}
Private::Private(const Private& p)
{
	for (int i = 0; i < p.grades.size(); i++)
	{
		grades[i] = p.grades[i];
	}
	this->id = p.id;
	this->operations = p.operations;
	this->firstName = p.firstName;
	this->lastName = p.lastName;
}