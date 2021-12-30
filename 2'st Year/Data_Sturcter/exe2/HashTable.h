#pragma once
#include<vector>
#include<iostream>
#include"Item.h"
using namespace std;
template <class T, class K>
class HashTable
{

public:
	Item<T, K>* arr = NULL;
	int size;
	HashTable(int N = 0);
	~HashTable();
	virtual int h1(K key) = 0;
	virtual int h2(K key) = 0;
	int Hash(K key, int i);
	int Search(K key);
	void Insert(T data,K key);
	void Delete(K key);
	virtual void Print();

};

inline bool isPrime(int n)
{
	if (n <= 1)  return false;
	if (n <= 3)  return true;
	if (n % 2 == 0 || n % 3 == 0) return false;
	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
inline int nearPrime(int N)
{
	while (!isPrime(N))
	{
		N++;
	}
		return N;
}
template<class T, class K>
inline HashTable<T, K>::HashTable(int N)
{
	size = nearPrime(N);
	arr = new Item<T, K>[size];
	for (int i = 0; i < size; i++)
	{
		arr[i].flag = (state)0;
	}
}
template<class T, class K>
inline HashTable<T, K>::~HashTable()
{
	delete[] arr;
}
template<class T, class K>
inline int HashTable<T, K>::Hash(K k, int i)
{

	return (h1(k) + i) % size;
}
template<class T, class K>
inline int HashTable<T, K>::Search(K k)
{
	int i = 0;
	for (int j = Hash(k, i); i <size;)
	{
		if (arr[j].flag == (state)0)
			break;
		if (arr[j].key == k)
			return j;
		i++;
		j = Hash(k, i);
	}
	return -1;
}
template<class T, class K>
inline void HashTable<T, K>::Insert(T t ,K k)
{
	
	int i = 0;
	int x;
	while (i != size)
	{
 		x = Hash(k, i);
		if (arr[x].flag != (state)1)
		{
			arr[x].data = t ;
			arr[x].key = k;
			arr[x].flag = (state)1;
			break;
		}
		i++;
	}

}
template<class T, class K>
inline void HashTable<T, K>::Delete(K key)
{
	int x = Search(key);
	if (x == -1)
	{
		return; // not in the table
	}
	arr[x].flag = (state)2;
}

template<class T, class K>
inline void HashTable<T, K>::Print()
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].flag == full)
			cout << arr[i].data << endl;
	}
}

