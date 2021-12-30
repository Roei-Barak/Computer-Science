#pragma once
#include"HashClient.h"
#include"HashTable.h"
#include"VolunteerHash.h"
#include <vector>
#include <algorithm>

class HashTlb
{
	VolunteerHash* VolunteerHashTable;
	HashClient* ClientHashTable;
public:
	HashTlb() { VolunteerHashTable = new VolunteerHash(100); ClientHashTable = new HashClient(100); };
	~HashTlb() { delete[]ClientHashTable;	delete[]VolunteerHashTable; }
	void addVolunteer(Volunteer newVlnt);
	void addClient(Client newClnt);
	void delVolunteer(Volunteer vlnt);
	void DeleteClient(Client clnt);
	void addVolunteerToClient(Volunteer& vol, Client& cli);
	void listOfVolunteers(Client);
	void listOfClients(Volunteer);
	void PrintVlnAndClntTables();
};
void HashTlb::addVolunteer(Volunteer newVlnt)
{
	Item <Volunteer, string>* vlnt = new Item< Volunteer, string >;
	vlnt->key = newVlnt.Name;
	vlnt->data = newVlnt;
	VolunteerHashTable->Insert(vlnt->data, vlnt->key);
}

inline void HashTlb::addClient(Client newClnt)
{
	
	Item <Client, int>* clnt = new Item< Client, int >;
	clnt->key = newClnt.phone;
	clnt->data = newClnt;
	ClientHashTable->Insert(clnt->data, clnt->key);
}

inline void HashTlb::delVolunteer(Volunteer vlnt)
{	//check if the Volunteer exisset
	if (VolunteerHashTable->Search(vlnt.Name) < 0)
		cout << "ERROR not found this voulnteer\n" << endl;
	VolunteerHashTable->Delete(vlnt.Name);
}

inline void HashTlb::DeleteClient(Client clnt)
{
	ClientHashTable->Delete(clnt.phone);
}
inline void HashTlb::addVolunteerToClient(Volunteer& vlnt, Client& clnt)
{
	int vIndex = VolunteerHashTable->Search(vlnt.Name);
	int cIndex = ClientHashTable->Search(clnt.phone);
	if ((vIndex < 0) || (cIndex < 0) )//not exisst
	{
		cout << "ERROR" << endl; return;
	}

	//add Each other for connection
	VolunteerHashTable->arr[vIndex].data.clnt.push_back(ClientHashTable->arr[cIndex].data.Name); 
	ClientHashTable->arr[cIndex].data.vltr.push_back(VolunteerHashTable->arr[vIndex].data.Name);
}
inline void HashTlb::listOfVolunteers(Client clnt)
{
	cout << "The volunteers that helped to client " << clnt.phone << ":  ";
	int cIndex = ClientHashTable->Search(clnt.phone);
	if (cIndex < 0)
	{
		cout << "ERROR" << endl;
		return;
	}
	//loop for all the volunteers
	auto it = ClientHashTable->arr[cIndex].data.vltr.begin();
	for (; it != ClientHashTable->arr[cIndex].data.vltr.end(); it++)
		cout << (*it) << " ";
	cout << endl;
}

inline void HashTlb::listOfClients(Volunteer vlnt)
{
	cout << "The clients that were helped by volunteer " << vlnt.Name << ":  ";
	int vIndex = VolunteerHashTable->Search(vlnt.Name);
	if (vIndex > 0)
	{
		//loop for all the client
		auto it = VolunteerHashTable->arr[vIndex].data.clnt.begin();
		for (; it != VolunteerHashTable->arr[vIndex].data.clnt.end(); it++)
			cout << (*it) << " ";
		return;
	}	
	//chek if the voulnteer was in  the vlnt list at any one 
	for (int i = 0; i < ClientHashTable->size; i++)
	{
		vector <string>::iterator itBegin = ClientHashTable->arr[i].data.vltr.begin();
		vector <string>::iterator itEnd = ClientHashTable->arr[i].data.vltr.end();
		vector <string>::iterator it = find(itBegin, itEnd , vlnt.Name);
		if (it != ClientHashTable->arr[i].data.vltr.end()) // there is a voulnteer before the iterator get to the end
		{
			//print the voulnteer`s were left
			cout << ClientHashTable->arr[i].data.Name << " ";
		}
	}
	cout << "ERROR" << endl;

}

inline void HashTlb::PrintVlnAndClntTables()
{
	cout << "Volunteers:\n";
	VolunteerHashTable->Print();
	cout << "Clients:\n";
	ClientHashTable->Print();
}
