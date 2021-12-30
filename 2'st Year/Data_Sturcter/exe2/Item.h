#pragma once
#include<vector>
#include<iostream>
enum state { empty, full, deleted };
template <class T, class K>
class Item
{
public:
	T data;
	K key;
	state flag;
	Item() {data = T(); key = K(); flag = (state)0;}
	Item(T d, K k, state f) { data = d; key = k; flag = f; }
};

