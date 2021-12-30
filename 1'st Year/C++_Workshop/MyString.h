#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
	char* str;
	void setString(const char* s);
public:
	static int a;
	// constructor.
	MyString(char* s);
	MyString(const MyString& s);
	~MyString();

	// view function.
	char* getString() const;

	// modify function.
	MyString& operator =(const MyString&);

	// operators
	MyString operator+(const MyString& s);
	bool operator==(const MyString& s) const;
	bool operator!=(const MyString& s) const;
	bool operator>(const MyString& s) const;
	bool operator<(const MyString& s) const;
	bool operator<=(const MyString& s) const;
	bool operator>=(const MyString& s) const;
	char& operator[](int index);
	int length() const; 
	MyString insert(int index, const char* str);

	// print
	void print() const;
};
