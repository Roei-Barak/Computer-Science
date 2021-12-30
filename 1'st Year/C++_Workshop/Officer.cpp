#include"Officer.h"
bool Officer::medal()
{
	if (operations > 2 && sociometric >= 92)
		return true;
	return false;
}

void Officer::print()
{
	cout << "officer" << endl;
	cout << "ID: " << id << endl;
	cout << "first name: " << firstName << endl;
	cout << "last name: " << lastName << endl;
	cout << "num operations: " << operations << endl;
	cout << "sociometric score: " << sociometric<< endl;

}
