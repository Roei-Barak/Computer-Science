#pragma once
#include"List.h"
class RoundList : public List
{
public:
	RoundList() {};
	~RoundList() {};
	void addToEnd(int val);
	int search(int n);
	void insert(int key);
	void removeFirst();
	void clear();
	void add(int value);


private:

};