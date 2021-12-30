#pragma once
#include <iostream>
#include"Private.h"
#include<vector>
using namespace std;
class Commander : public Private
{
public:
	Commander(int i, int o, string f, string l, vector<int> n, bool c) : Private(i, o, f,l, n) , combat(c) {}
	~Commander() {}
	bool medal();
	void print();
	string soldierType() { return "Commander"; }
	int getSoc() { throw "ERROR: this function is just for officer soldier"; }
	bool isCombat() { return combat; }
private:
	bool combat;
};

