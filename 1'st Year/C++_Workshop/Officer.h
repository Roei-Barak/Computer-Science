#pragma once
#include"Soldier.h"
class Officer : public Soldier
{
public:
	Officer(int i, int o, string f, string l, int s) : Soldier(i, o, f, l), sociometric(s) {};
	~Officer() {};
	string soldierType() { return "Officer"; }
	bool medal();
	void print();
	int getSoc(){return sociometric;}
	string getFname() { return firstName; }
	string getName() { return lastName; }
	bool isCombat() {return NULL;}
private:
	int sociometric;
};