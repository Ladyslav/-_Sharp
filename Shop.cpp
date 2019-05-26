#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct Product
{
	string Customer;
	string Label;
	unsigned int quantity;
	int Price;
	int number;
	bool Priority = false;
	Product* pNext = nullptr;
	Product* pPrev = nullptr;
};

void menu();
void AddNode(Product*& head, Product*& tail);
void DeleteList(Product*& head, Product*& tail);
void ShowList(Product*& head, Product*& tail);
bool deliveryToCustomer(Product*& head, Product*& tail, Product*& headCustomer, Product*& tailCustomer, int index);
bool deleteNODE(Product*& head, Product*& tail, int index);
void ShowItemList(Product*& headCustomer, Product*& tailCustomer);


int main()
{
	menu();
	return 0;
}

void menu()
{
	Product* head = nullptr;
	Product* tail = nullptr;
	Product* headCustomer = nullptr;
	Product* tailCustomer = nullptr;
	int choice;
	int index = 0;
	bool exit = false;
	while (!exit)
	{
		cout << " 1 - Add Product " << endl << " 2 - Show Product " << endl << " 3 - Delete Product " << endl << " 4 - Send products to the warehouse " << endl << " 5 - Show Product in stock" << endl << " 6 - Delete all Products" << endl << " 7 - Exit: " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			AddNode(head, tail);
		}
		break;
		case 2:
		{
			ShowList(head, tail);
		}
		break;
		case 3:
		{
			ShowList(head, tail);
			cout << "Choose number of Product" << endl;
			cin >> index;
			deleteNODE(head, tail, index);
		}
		break;
		case 4:
		{
			ShowList(head, tail);
			cout << "Choose number of Product" << endl;
			cin >> index;
			deliveryToCustomer(head, tail, headCustomer, tailCustomer, index);
		}
		break;
		case 5:
		{
			ShowItemList(headCustomer, tailCustomer);
		}
		break;
		case 6:
		{
			DeleteList(headCustomer, tailCustomer);
		}
		break;
		case 7:
			exit = true;
			break;
		default:
			cout << "Wrong choice!\n";
			break;
		}

		system("pause");
		system("cls");

	}

}


void AddNode(Product*& head, Product*& tail)
{

	Product* tmpNode = new Product;
	cout << "Put price: ";
	cin >> tmpNode->Price;
	cout << "Put label: ";
	cin >> tmpNode->Label;



	if (head == nullptr)
		head = tail = tmpNode;
	else
	{
		tmpNode->pPrev = tail;
		tail->pNext = tmpNode;
		tail = tail->pNext;

	}
}




void ShowList(Product*& head, Product*& tail)
{
	Product* tmp = head;
	int counter = 1;
	if (tmp == nullptr)
	{
		cout << "Nothing";
	}
	while (tmp != nullptr)
	{

		cout << "Number of product: " << counter << endl << "Value: " << tmp->Price << endl << "Label: " << tmp->Label << endl;
		cout << endl;
		tmp = tmp->pNext;
		counter++;
	}

	cout << "\n\n\n";
}

void DeleteList(Product*& head, Product*& tail)
{
	if (head == nullptr)
		return;

	Product* tmpNext = nullptr;
	Product* tmp = head->pNext;
	delete head;
	head = nullptr;

	while (tmp != nullptr)
	{
		tmpNext = tmp->pNext;
		delete tmp;
		tmp = tmpNext;
	}
}


bool deleteNODE(Product*& srcHead, Product*& srcTail, int index)
{
	if (srcHead == nullptr || srcTail == nullptr)
		return false;

	else if (index > 0)
		index = index - 1;
	else
		return false;

	if (index == 0)
	{

		Product* tmp = srcHead->pNext;
		delete srcHead;
		srcHead = tmp;
		tmp->pPrev = nullptr;
		return true;
	}

	int counter = 1;
	Product* tmp = srcHead->pNext;
	Product* tmpPrev = srcHead;
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

bool deliveryToCustomer(Product*& head, Product*& tail, Product*& headCustomer, Product*& tailCustomer, int index)
{
	if (head == nullptr)
		return false;
	if (index > 0)
		index = index - 1;
	else
		return false;

	int counter = 1;

	Product* tmp = head->pNext;
	Product* tmpPrev = head;

	for (; tmp != 0 && counter <= index; ++counter)
	{
		tmpPrev = tmp;
		tmp = tmp->pNext;
	}

	if (counter != index + 1)
		return false;

	tmp = tmpPrev;

	cout << "Add name of Customer: ";
	cin >> tmp->Customer;
	cout << "Add Priority: 0 - No; 1 - Yes; ";
	cin >> tmp->Priority;

	if (tmp == head)
	{
		if (head == tail)
			head = tail = tail->pNext;
		else
			head = tmp->pNext;
		head->pPrev = nullptr;

	}
	else
	{
		if (tmp == tail)
		{
			tail = tmp->pPrev;
			tail->pNext = nullptr;
		}
		else
		{
			(tmp->pPrev)->pNext = tmp->pNext;
			(tmp->pNext)->pPrev = tmp->pPrev;
		}
	}

	if (headCustomer == nullptr)
	{
		headCustomer = tailCustomer = tmp;
		tmp->pNext = tmp->pPrev = nullptr;
	}
	else
	{
		if (tmp->Priority)
		{
			headCustomer->pPrev = tmp;
			tmp->pNext = headCustomer;
			tmp->pPrev = nullptr;
			headCustomer = tmp;
		}
		else
		{
			tailCustomer->pNext = tmp;
			tmp->pPrev = tailCustomer;
			tmp->pNext = nullptr;
			tailCustomer = tmp;
		}
	}

	return true;
}

void ShowItemList(Product*& headCustomer, Product*& tailCustomer)
{
	Product* tmp = headCustomer;

	int counter = 1;
	if (tmp == nullptr)
	{
		cout << "Nothing";
	}
	while (tmp != nullptr)
	{

		cout << "Number of product: " << counter << endl << "Value: " << tmp->Price << endl << "Customer: " << tmp->Customer << endl << "Label: " << tmp->Label << endl << "Priority :" << tmp->Priority << endl;
		cout << endl;
		tmp = tmp->pNext;
		counter++;
	}

	cout << "\n\n\n";
}
