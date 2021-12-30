#pragma once
#include<iostream>
using namespace std;
class List
{
protected:
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
		// data areas
		int value;
		Link* next;
	};	//end of class Link
public:
	// constructors
	List();
	List(const List&);
	~List();
	friend ostream& operator<<(ostream& os, const List& l);
	friend istream& operator>>(istream& is, List& l);
	List operator = (const List& rhs);
	void insert(int key);
	void add(int value);
	int firstElement() const;
	bool search(const int& value) const;
	bool isEmpty() const;
	void removeFirst();
	void remove(int key);
	void clear();

protected:
	// data field
	Link* head;
};
