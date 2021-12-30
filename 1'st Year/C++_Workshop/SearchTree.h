#pragma once
#include "Tree.h"
#include "QueueVector.h"
#include <iostream>
#include <cmath>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{

public:
	void add(T value);
	bool  search(T value)
	{
		return search(Tree<T>::root, value);
	}
	void remove(T val);
	T successor(T val);
	void deleteDuplicates();
private:
	void add(typename Tree<T>::Node* current, T val);
	typename Tree<T>::Node* predecessor (typename Tree<T>::Node* current, T val);
	typename Tree<T>::Node* nodeReturn(typename Tree<T>::Node* current, T val);
	bool  search(typename Tree<T>::Node* current, T val);
	void deleteDuplicates(typename Tree<T>::Node* current);

};

template <class T>
void SearchTree<T>::add(T val)
{
		if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}

template<class T>
void SearchTree<T>::remove(T val)
{
		if (search(val) == true) // checks if the value exist in the tree
		{
			if (Tree<T>::root->value != val) 
			{
				typename Tree<T>::Node* parent;
				parent = predecessor(Tree<T>::root, val);
				typename Tree<T>::Node* tmp;
				if (parent->left != NULL && parent->left->value == val)
					tmp = parent->left;
				else
					tmp = parent->right;

				if (tmp->left == NULL && tmp->right == NULL) //no sons
				{
					if (parent->right != NULL && parent->right->value == val)
						parent->right = NULL;
					else
						parent->left = NULL;
					return;
				}
				if (tmp->left == NULL && tmp->right != NULL || tmp->left != NULL && tmp->right == NULL) //one son
				{
					if (parent->right != NULL && parent->right->value == val)
						if (tmp->right != NULL)
							parent->right = tmp->right;
						else
							parent->right = tmp->left;
					if (parent->left != NULL && parent->left->value == val)
						if (tmp->right != NULL)
							parent->left = tmp->right;
						else
							parent->left = tmp->left;
					return;
				}
				if (tmp->left != NULL && tmp->right != NULL) // two sons.
				{
					T temp = successor(val);
					remove(temp);
					tmp->value = temp;

					return;
				}
			}
			else // if the value is the root
			{
				if (Tree<T>::root->left != NULL && Tree<T>::root->right != NULL)
				{
					T temp = successor(val);
					remove(temp);
					Tree<T>::root->value = temp;

					return;
				}
			}
		}
}

template<class T>
T SearchTree<T>::successor(T val)
{
	
	typename Tree<T>::Node* temp;
	temp = nodeReturn(Tree<T>::root, val);
	if (temp == NULL)
	{
		throw "no successor";
	}
	if (temp->right != NULL) 
	{
		typename Tree<T>::Node* temp2;
		temp2 = temp->right;
		while (temp2->left != NULL)
			temp2 = temp2->left;
		return temp2->value;
	}
	else 
	{
		typename Tree<T>::Node* succ = NULL;
		typename Tree<T>::Node* ancestor = Tree<T>::root;
		while (ancestor != temp)
		{
			if (temp->value < ancestor->value)
			{
				succ = ancestor;
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		if (succ != NULL)
			return succ->value;
		else
		{
			throw "no successor";
			return NULL;
		}
	}
}
template<class T>
inline void SearchTree<T>::deleteDuplicates()
{
	deleteDuplicates(Tree<T>::root);
}
template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value < val)

		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	else

		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
}

template<class T>
inline typename Tree<T>::Node* SearchTree<T>::predecessor (typename Tree<T>::Node* current, T val)
{
	if (!current)
		return NULL;
	if ((current->left != NULL && current->left->value == val)/*the value is the left son*/ || (current->right != NULL && current->right->value == val)/*the value is the right son*/)
	{
		typename Tree<T>::Node* temp = current;
		return temp;
	}
	if (current->value < val)
		return predecessor (current->right, val);
	else
		return predecessor (current->left, val);

}

template<class T>
inline typename Tree<T>::Node* SearchTree<T>::nodeReturn(typename Tree<T>::Node* current, T val)
{
		//find the pointer of the value val.
		if (!current)
			return NULL;	// not found
		if (current->value == val)
		{
			typename Tree<T>::Node* temp = current;
			return temp;
		}
		if (current->value < val)
			return nodeReturn(current->right, val);
		else
			return nodeReturn(current->left, val);
}

template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

template<class T>
inline void SearchTree<T>::deleteDuplicates(typename Tree<T>::Node* current)
{
	//all the dublicates number in bst are at the same location
	if (current->left != NULL)
		deleteDuplicates(current->left);
	if (current->right != NULL)
		deleteDuplicates(current->right);
	if (current == NULL)
		return;
	if ((current->left != NULL && current->value == current->left->value) || (current->left != NULL && current->left->right != NULL && current->value == current->left->right->value))
	{
		if (current->left != NULL && current->left->right != NULL && current->value == current->left->right->value)
		{
			if (current->left->right->left == NULL && current->left->right->left == NULL)
				current->left->right = NULL;
			else if (current->left->right->left != NULL && current->left->right->right == NULL)
				current->left->right = current->left->right->left;
			else if (current->left->right->left == NULL && current->left->right->right != NULL)
				current->left->right = current->left->right->right;
			else if (current->left->right->left != NULL && current->left->right->right != NULL)
			{
				T temp = successor(current->left->right->value);
				remove(temp);
				current->left->right->value = temp;
			}
		}

		else
		{
			if (current->left->left == NULL && current->left->right == NULL)
				current->left = NULL;
			else if (current->left->left != NULL && current->left->right == NULL)
				current->left = current->left->left;
			else if (current->left->left == NULL && current->left->right != NULL)
				current->left = current->left->right;
			else if (current->left->left != NULL && current->left->right != NULL)
			{
				T temp = successor(current->left->value);
				remove(temp);
				current->left->value = temp;
			}
		}

	}
}
