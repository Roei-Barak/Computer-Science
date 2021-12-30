/****************
*	Roei Barak	*
*	318419611	*
*	Exe 10 Q 1  *
****************/
#include <iostream>
using namespace std;

struct Chisun
{
	int code;
	char prodDate[10];
	char expireDate[10];

	//if vaccine not used = 0
	long id;

	// 1 = first shot; 2 = second shot; 0= not given
	int shotTime;

	// 0 = not ill; 
	// 1 = ill between shots;
	// 2 = ill after second shot
	// 3 = ill afters secod shot plus required time  
	int illness;
};

//prototypes
int menu();
Chisun* allocateVaccines(int& n);

//main starting function
int main()
{
	int n;
	int choice = -1;
	Chisun* Chisunim;
	int x = 9;
	float y = 2;
	y = x / 8;
	cout << y; 
	y = float(x) / 8;
	cout << y;
	cout << "welcome to Vaccination Center for JCT" << endl;

	Chisunim = allocateVaccines(n);

	do
	{
		choice = menu();
		switch (choice)
		{
		case 1: // AddVaccines
			
			// TO DO
			break;
		case 2:	// CheckVaccines
			// TO DO
			break;
		case 3:	// Vaccinate
			// TO DO
			break;
		case 4:	// Illness
			// TO DO
			break;
		case 5:	// Printvaccines
			// TO DO
			break;
		case 6:	// SaveToFile
			// TO DO
			break;


		case 7:	// ValidateStockWithFile
			// TO DO
			break;
		}
	} while (choice != 0);

	cout << "Bye bye, be healthy" << endl;
	delete[]  Chisunim;

	return 0;
}

//Allocating memory for vaccines array
Chisun* allocateVaccines(int& n)
{
	do
	{
		//cout << "how many vaccines do you want? ";
		cout << "enter max number of items: ";
		cin >> n;

	} while (n <= 0);

	Chisun* vaccines = new Chisun[n];
	return vaccines;
}

//Presenting the user operations to choose from
int menu()
{
	int choice;

	do
	{
		cout << " 1 - Add vaccines to Stock" << endl;
		cout << " 2 - Check how may vaccines in  Stock" << endl;
		cout << " 3 - Shot vaccine from Stock" << endl;
		cout << " 4 - Illness observed on a vaccinated patient" << endl;
		cout << " 5 - Print the Stock" << endl;
		cout << " 6 - Serialize the Stock to file" << endl;
		cout << " 7 - Validation of the Stock with the file" << endl;
		cout << " 0 - EXIT" << endl;

		cin >> choice;
		if (choice < 0 || choice > 7)
		{
			cout << "invalid choice, try again:" << endl;
			continue;
		}
		if (choice != 0)
			cout << " You pressed: " << choice << endl;
		break;
	} while (true);

	return choice;
}


/**************************************************
*						  						  *
*						  						  *
*						  						  *
*						  						  *
*						  						  *
* 						  						  *
* 						  						  *
* 						  						  *
* 						  						  *
* 						  						  *
* 						  						  *
* 						  						  *
**************************************************/