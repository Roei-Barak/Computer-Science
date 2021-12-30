#pragma once
#include "Client.h"
#include "HashTable.h"
#include <iostream>
using namespace std;

class HashClient :public HashTable<Client, int>
{
public:
	HashClient(int size) : HashTable(size) {};

private:
	int h1(int key);
	int h2(int key);
};

inline int HashClient::h1(int key)
{
	return (key % size);
}

inline int HashClient::h2(int key)
{
	return (key & size + 1);
}