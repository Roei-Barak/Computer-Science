#include"Tree.h"
//returns node t where the string equals val. 
//If t has a prent, the pointer parent will contain its address. 
Node* Tree::search(Node* t, string val, Node*& parent)
{
	if (t->value == val)//returns node t where the string equals val. 
	{
		return t;
	}
	list<Answer*>::iterator it = t->answersList.begin();
	for (; it != t->answersList.end(); it++)
	{
		Node* tmp = search((*it)->son, val, t);
		if (tmp == NULL)
			it++;
		else
		{
			parent = t; // the pointer parent will contain its address. 
			return tmp;
		}
	}
	return NULL;//not found
}

bool Tree::searchAndPrint(Node* p, string val)
{
	if (search(p, val, Tree::root) == NULL)
		return false;
	if (p->value != val)
	{
		if (p->isLeaf == true)
			return false;
		list<Answer*>::iterator it = p->answersList.begin();
		for (; it != p->answersList.end(); it++)
		{
			if (searchAndPrint((*it)->son, val) == true)//recursevi
			{
				cout << "=>" << p->value;
				return true;
			}

		}
	}
	else
	{
		cout << p->value;
		return true;
	}
	return NULL;

}

void Tree::print(Node* p, int level)
{
	//for (int i = 0; i < level; i++) // print the spcae acdording to the level
	//	cout << " ";
	cout << p->value << endl;
	list<Answer*>::iterator it = p->answersList.begin();

	for (; it != p->answersList.end(); it++)
	{
		if (*it != NULL)
		{
			for (int i = 0; i < level; i++)
				cout << " ";
			cout << ":" << (*it)->ans << endl;
			print((*it)->son, level + 1);
		}
	}
}

void Tree::process(Node* p)
{
	cout << p->value << endl;
	if (p->isLeaf == false)
	{
		string answer;
		cin >> answer;
		list<Answer*>::iterator it = p->answersList.begin();
		for (; it != p->answersList.end(); it++)
		{
			if ((*it)->ans == answer)
			{
				if ((*it)->son->isLeaf == false)
					process((*it)->son);
				else
					cout << (*it)->son->value << endl;
			}
		}

	}
}

void Tree::deleteAllSubTree(Node* t)
{
	if (t!= NULL)
	{
		list<Answer*>::iterator it = t->answersList.begin();
		for (; it != t->answersList.end(); it++)
		{
			if ((*it) != NULL && (*it)->son != NULL)
				deleteAllSubTree((*it)->son);
			delete [] (*it);
			*it = NULL;
		}
		delete [] t;

	}
}

void Tree::addRoot(string newval)
{
	root = new Node(newval);

}

bool Tree::addSon(string fatherquestion, string newanswer, string newval)
{
	if ((search(root, fatherquestion, root)) == NULL)
		return false;
	Node* n = new Node(newval);
	Answer* a = new Answer(newanswer, n);
	Node* q = search(root, fatherquestion, root);
	q->answersList.push_back(a);
	q->isLeaf = false;
	return true;
}

void Tree::deleteSubTree(string val)
{
	if (search(root, val, root))
		deleteAllSubTree(search(root, val, root));
}

void Node::removeSonValue(string v)
{
	
}
