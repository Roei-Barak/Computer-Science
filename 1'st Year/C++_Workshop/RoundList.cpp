#include "RoundList.h"
void RoundList::addToEnd(int val)
{
	if (head == NULL)
	{
		head = new Link(val, head);
		head->next = head;
		return;
	}
	Link* p = head;
	p = p->next;
	while (p->next != head)
	{
		p = p->next;
	}
	p->next = new Link(val, head);
}

int RoundList::search(int n)
{
	if (head == NULL)
		return -1;
	Link* p = head;
	for (int i = 0; i < n; i++)// run n times until the index n 
	{
		p = p->next;
	}
	return p->value;
}

void RoundList::insert(int key)
{

	if (List::head == NULL)
	{
		head = new Link(key, head);
		return;
	}
	if (key >= head->value)
	{
		add(key);
		Link* p = this->head;
		while (true)
		{
			while (p->next != head->next) // get to the last link and change his next to point on the new head
			{
				p = p->next;
			}
		}
		p->next = head;
		return;
	}
	else
	{
		Link* p = this->head;
		while (key < p->value)
		{
			if (p->next == head)
			{
				p->next = new Link(key, head);
				return;
			}
			if (p->next->next == head)
			{
				if (key > p->next->value)
				{
					Link x(key, p->next);
					p->next = new Link(key, p->next);
				}
				else
				{
					p = p->next;
					p->next = new Link(key, head);
				}
				return;
			}
			p = p->next;
		}
		p->next = new Link(key, p->next);
	}
}

void RoundList::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	//check if there only one value
	if (head->next == head)
	{
		clear();
		return;
	}
	// save pointer to the removed node
	Link* p = head;
	// find the last link in the list
	while (p->next != head)
	{
		p = p->next;
	}
	p->next = head->next;
	// reassign the first node
	p = head;
	head = p->next;
	p->next = nullptr;
	// recover memory used by the first element
	delete p;
}

void RoundList::clear()
{
	// empty all elements from the List
	Link* theNext;
	for (Link* p = head; p->next != head; p = theNext)
	{
		// delete the element pointed to by p
		theNext = p->next;
		p->next = nullptr;
		delete p;
	}
	// mark that the List contains no elements
	head = nullptr;
}

void RoundList::add(int val)
{
	if (head == NULL)
	{
		head = new Link(val, head);
		head->next = head;
		return;
	}
	Link* p = head;
	head = new Link(val, head);
	// find the last link in the list
	//if (p->next == head->next && head->next != NULL)
	//{
	//	head->next->next = head;
	//	return;
	//}
	while (p->next != head->next)
	{
		p = p->next;
	}
	p->next = head;
	if (head == nullptr)
		throw "failed in memory allocation";
}
