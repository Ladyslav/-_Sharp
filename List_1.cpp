#include "pch.h"
#include <iostream>

using namespace std;

struct Node
{
	int data = 0;

	Node* pNext = nullptr;
	Node* pPrev = nullptr;
};

void AddNode(Node*& head);
void DeleteList(Node*& head);
void ShowList(Node*& head);
bool insert(Node*& head, int index);
bool deleteNODE(Node*& head, int index);
bool reverse(Node*& head);



int main()
{
	Node* MyList = nullptr;
	
	AddNode(MyList);
	AddNode(MyList);
	AddNode(MyList);
	insert(MyList, 2);
	//deleteNODE(MyList, 2);
	ShowList(MyList);
	DeleteList(MyList);

	if (MyList == nullptr)
		cout << "Empty" << endl;
   system("pause");
}

void AddNode(Node*& head)
{
	Node* tmpNode = new Node;
	tmpNode->data = 41;

	if (head == nullptr)
		head = tmpNode;
	else
	{
		Node* tmp = head->pNext;

		Node* tmpPrev = head;


		while (tmp != nullptr)
		{
			tmpPrev = tmp;
			tmp = tmp->pNext;
		}

		tmpPrev->pNext = tmpNode;
		tmpNode->pPrev = tmpPrev;
	}
}
void ShowList(Node*& head) 
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		cout << "Address: " << tmp << endl << "Value: " << tmp->data << endl << "LinkNext: " << tmp->pNext <<endl <<"LinkPrev: "<<tmp->pPrev << endl;
		cout << endl;
		tmp = tmp->pNext;
		
	}

	cout << "\n\n\n";
}

void DeleteList(Node*& head)
{
	if (head == nullptr)
		return;

	Node* tmpNext = nullptr;
	Node* tmp = head->pNext;
	delete head;
	head = nullptr;

	while (tmp != nullptr)
	{
		tmpNext = tmp->pNext;
		delete tmp;
		tmp = tmpNext;
	}
}


bool insert(Node*& head, int index) {

	if (index == 0) {
		Node* newNode = new Node;
		newNode->data = 10000;
		newNode->pNext = head;
		newNode->pPrev = newNode;
		head = newNode;
		return true;
	}
	else if (head == nullptr) {
		return false;
	}



	Node* tmp = head;
	int counter = 0;
	Node* prev = nullptr;
	Node* next = nullptr;
	for (; counter < index && tmp != nullptr; counter++)
	{
		
		prev = tmp;
		tmp = tmp->pNext;
		
	}

	if (counter == index) {
		Node* newNode = new Node;
		newNode->data = 99;
		newNode->pNext = tmp;
		newNode->pPrev = prev;
		prev->pNext = newNode;
		tmp->pPrev = newNode;
		return true;
	}
	else
		return false;
}


bool deleteNODE(Node*& head, int index)
{
	if (head == nullptr)
		return false;
	else if (index == 0)
	{
		Node* tmp = head->pNext;
		delete head;
		head = tmp;
		return true;
	}

	int counter = 1;
	Node* tmp = head->pNext;
	Node* tmpPrev = head;
	for (; tmp != 0 && counter < index; ++counter)
	{
		tmpPrev = tmp;
		tmp = tmp->pNext;
	}

	if (tmp == nullptr)
		return false;

	tmpPrev->pNext = tmp->pNext;
	delete tmp;
	return true;
}