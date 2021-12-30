#include "MyString.h"
MyString::MyString(char* s)
{
	setString(s);
}
MyString::MyString(const MyString& s)
{
	setString(s.getString());
}

MyString::~MyString()
{
	if (str)
		delete[] str;
	str = nullptr;
}
char* MyString::getString() const
{
	return str;
}

void MyString::setString(const char* s)
{
	if (s)
	{
		int len = strlen(s) + 1;
		str = new char[len];
		//strcpy_s(str, len, s);
		strcpy(str, s);
	}
	else str = nullptr;
}

MyString& MyString::operator=(const MyString& s)
{
	if (str)
		delete[] str;
	
	return *this;
}
MyString MyString::operator+(const MyString& s)
{
	int sizeI = strlen(str);
	int sizeII = strlen(s.getString());
	char* temp = new char[sizeI + sizeII + 1];
	strcpy(temp, str);
	strcpy(temp,s.getString());
	MyString x(temp);
	return x;
}

bool MyString::
operator==(const MyString& s) const
{
	return !strcmp(str, s.getString());
}
bool MyString::
operator!=(const MyString& s) const
{
	if (s.getString() == this->getString())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool MyString::operator>(const MyString& s) const
{
	if (strcmp(str, s.getString()) > 0 )
		return true;
	else
		return false;
	
}
bool MyString::operator>=(const MyString& s) const
{
	if (strcmp(str, s.getString()) >= 0 )
		return true;
	else
		return false;
	
}
bool MyString::operator<(const MyString& s) const
{
	if (strcmp(str, s.getString()) < 0)
		return true;
	else
		return false;
}

bool MyString::operator<=(const MyString& s) const
{
	if (strcmp(str, s.getString()) <= 0)
		return true;
	else
		return false;
}

int MyString::length() const
{
	return strlen(str);
}

void MyString::print() const
{
	if (str) cout << str << endl;
}

char& MyString::operator[](int index)
{
	if (index > this->length())
	{
		return str[0];
	}
	else
	{
		return str[index];
	}
}

MyString MyString::insert(int index, const char* s)
{
	if (index > this->length())
	{
		return NULL;
	}
	int totalLenght = strlen(s) + this->length();
	int firstIndex = 0; 
	int secondIndex = 0; 
	int mergedIndex = 0; 
	//char merged[20] = {};
	char *merged = new char[totalLenght+1];
	for (int i = 0; i < index; i++)
	{
		merged[mergedIndex] = s[secondIndex];
		mergedIndex++; secondIndex++;
	}
	for (int i = 0; i < strlen(s); i++)
	{
		merged[mergedIndex] = this->str[firstIndex];
		mergedIndex++; firstIndex++;
	}
	for (int i = 0; i < this->length()- index; i++)
	{
		merged[mergedIndex] = s[secondIndex];
		mergedIndex++; secondIndex++;
	}
	merged[mergedIndex] = '\0';
	MyString mergeStr(merged);
	return mergeStr;
}