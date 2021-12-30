#include "List.h"
List::Link::Link(int val, Link* nxt) : value(val), next(nxt) {}


List::Link::Link(const Link& source) : value(source.value), next(source.next) {}


List::List() : head(nullptr) {}

List::List(const List& l)
{
	Link* src, * trg;
	if (l.head == nullptr)
		head = nullptr;
	else
	{
		head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = head;
		while (src->next != nullptr)
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
}


List::~List()
{
	clear();
}

List List::operator=(const List& l)
{
	Link* src, * trg;
	if (l.head == nullptr)
		head = nullptr;
	else
	{
		head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = head;
		while (src->next != nullptr)
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}

	return List();
}

void List::insert(int key)
{

	if (List::head == NULL)
	{
		head = new Link(key, NULL);
		return;
	}
	if (key >= head->value)
	{
		add(key);
		return; 
	}
	else
	{
		Link* p = this->head;
		while (key < p->value)
		{
			if (p->next == NULL)
			{
				p->next = new Link(key, NULL);
				return;
			}
			if (p->next->next == NULL)
			{
				if (key > p->next->value)
				{
					Link x(key, p->next);
					p->next = new Link(key, p->next);
				}
				else
				{
					/*Link y(key, NULL);*/
					p = p->next;
					p->next = new Link (key, NULL);
				}
				return;
			}
			p = p->next;
		}
		p->next = new Link(key, p->next);
	}
}


void List::clear()
{
	// empty all elements from the List
	Link* theNext;
	for (Link* p = head; p != nullptr; p = theNext)
	{
		// delete the element pointed to by p
		theNext = p->next;
		p->next = nullptr;
		delete p;
	}
	// mark that the List contains no elements
	head = nullptr;
}

bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == nullptr;
}

void List::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == nullptr)
		throw "failed in memory allocation";
}

int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}

bool  List::search(const int& val) const
{
	// loop to test each element
	for (Link* p = head; p != nullptr; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}


void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = nullptr;
	// recover memory used by the first element
	delete p;
}

void List::remove(int key)
{
	List::Link* p = this->head;

	if (this->search(key) == true)
	{
		while (key < p->value )
		{
			if (p->next->value == key)
				break;
			p = p->next;
		}
		p->next = p->next->next;
	}
}

ostream& operator<<(ostream& os, const List& l)
{
	List::Link* p = l.head;
	while (p != NULL)
	{
		os << p->value << " ";
		p = p->next;
	}
	return os;
}

istream& operator>>(istream& is, List& l)
{
	int key;
	is >> key;
	l.insert(key);
	List::Link* p = l.head;
	while (true)
	{
		is >> key;
		if (p->value <= key) // not sortted
		{
			return is;
		}
		l.insert(key);
		p = p->next;

	}
	return is;
}
