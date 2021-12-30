/*
*Roei Barak - ID 318419611
*Computer science Introduction
*Exe 12
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#pragma warning (disable:4996)
using namespace std;
struct Item
{
	int code;
	char name[20];
	int amount;
	int minimum_amount;
	float price;
};

void addItem(Item*&store, int maxItems,int& numItems)
{
	Item tmp; bool flag;
	
	int index = numItems; //first empty index
	cout << "enter code :\n";
	cin >> tmp.code;
	cout << "enter name :\n";
	cin >> tmp.name;
	cout << "enter amount :\n";
	cin >> tmp.amount;
	cout << "enter minimum amount :\n";
	cin >> tmp.minimum_amount;
	cout << "enter price :\n";
	cin >> tmp.price;
	for (int i = 0; i < maxItems; i++)
	{
		if ((tmp.code == store[i].code) && (strcmp(tmp.name,store[i].name))) // error ambugies code
		{
			cout << "ERROR\n";
			//store[index] = { NULL};
			return;
		}
		else if (tmp.code == store[i].code && *tmp.name == *store[i].name) // replace between old details of this item to the new one
		{
			tmp.amount += store[i].amount;
			store[i] = tmp;
			
			return;
		}
	}
	if (numItems == maxItems) // check if there is enough space
	{
		cout << "ERROR\n";
		return;
	}
	store[index] = tmp;
	numItems++;

}
void findPrice(Item* store, int numItems)
{
	int code; int i; bool flag = false;
	cout << "enter code: \n";
	cin >> code;
	for (i = 0; i < numItems; i++)
		if (store[i].code == code)
		{
			flag = true;
			break;
		}
	if (flag)
		cout << "price: " << store[i].price << endl;
	else
		cout << "ERROR " << endl;
}
void sold(Item*store, int numItems)
{
	int i,code, amount; bool flag = false;
	cout << "enter code:" << endl;
	cin >> code;
	cout << "enter amount:" << endl;
	cin >> amount;
	for (i = 0; i < numItems; i++)
	{
		if (store[i].code == code)
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "ERROR" << endl;
		return;
	}
	amount = (store[i].amount - amount);
	(amount <= 0) ? store[i].amount = 0 : store[i].amount = amount; // new amount

	

}
void order(Item* store, int numItems)
{
	bool flag = false;
	for (int i = 0; i < numItems; i++)
	{
		if (store[i].amount < store[i].minimum_amount) // check if the amount is smaller then minimum amount
		{
			int amount_to_order = (store[i].minimum_amount + 5) - store[i].amount; // calculate amount to order
			cout << "item name: " << store[i].name << "\ncode: " << store[i].code << "\namount to order: " << amount_to_order;
			store[i].amount += amount_to_order;//oreder the item
			flag = true;
		}
		if (flag == true)
			cout << endl;
		flag = false;
	}
}
void print(Item* store, int numItems)
{
	for (int i = 0; i < numItems; i++)
	{
		cout << "name: " << store[i].name<< endl;
		cout << "code: " << store[i].code <<endl;
		cout << "amount: " << store[i].amount << endl;
		cout << "minimum amount: " << store[i].minimum_amount << endl;
		cout << "price: " << store[i].price << endl;
		cout << endl;
	}
}
enum cases { EXIT, ADD, FIND, SOLD, ORDER, PRINT };
int main()
{
	Item* store;
	int maxItems;
	int numItems = 0;
	int choice;
	cout << "enter max number of items: " << endl;
	cin >> maxItems;
	store = new Item[maxItems];
	do {
		cout << "enter 0-5:\n";

		cin >> choice;

		switch (choice) {
		case EXIT:	break;

		case ADD:	addItem(store, maxItems, numItems);
			break;

			case FIND: 	findPrice(store, numItems);
				break;

			case SOLD:	sold(store, numItems);
				break;

			case ORDER:	order(store, numItems);
				break;

			case PRINT: 	print(store, numItems);
				break;

			default: 	cout << "ERROR" << endl;
			}
		} while (choice != 0);
	return 0;
}
/*
enter max number of items:
1
enter 0-5:
1
enter code :
1
enter name :
1
enter amount :
1
enter minimum amount :
1
enter price :
1
enter 0-5:
1
enter code :
1
enter name :
2
enter amount :
2
enter minimum amount :
2
enter price :
2
ERROR
enter 0-5:
1
enter code :
1
enter name :
1
enter amount :
11
enter minimum amount :
1111
enter price :
111111
enter 0-5:
5
name: 1
code: 1
amount: 11
minimum amount: 1111
price: 111111

enter 0-5:
0
.
*/