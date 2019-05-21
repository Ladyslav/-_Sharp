#include <iostream>
#include <string>
using namespace std;

struct Student {
	string name;
	string surname;
	string company;
	int age;
	int marks;
};

void fillGroup(Student*& group, int size);
void showGroup(Student*& group, int size);
void fillStudent(Student&);
void showStudent(Student&);
void deleteGroup(Student*& group);
void createGroup(Student*& group, const int& size);

void Menu();


int main()
{
	Menu();
	return 0;
}


void fillGroup(Student*& group, int size) {
	for (int i = 0; i < size; i++)
	{
		fillStudent(group[i]);
	}
}

void fillStudent(Student& student)
{
	cout << "Fill name: ";
	cin >> (student).name;
	cout << "Fill surname: ";
	cin >> (student).surname;
	cout << "Fill company: ";
	cin >> (student).company;
	cout << "Fill age: ";
	cin >> (student).age;
	cout << "Fill marks: ";
	cin >> (student).marks;
	system("cls");
}
void showGroup(Student*& group, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "Student #" << i + 1 << " : \n";
		showStudent(group[i]);
		cout << "\n";
	}
}
void showStudent(Student& student) {
	cout << "Name: " << (student).name << endl;
	cout << "Surname: " << (student).surname << endl;
	cout << "Company: " << (student).company << endl;
	cout << "Marks: " << (student).marks << endl;
	cout << "Age: " << (student).age << endl;
}

void deleteGroup(Student*& group) {

	if (group != nullptr)
	{
		delete[] group;
		group = nullptr;
	}
}

void createGroup(Student*& group, const int& size)
{
	if (group != nullptr)
		delete[] group;

	group = new Student[size];
}

void Menu()
{
	Student* group = nullptr;
	int choice;
	int score;

	bool exit = false;
	while (!exit)
	{
		cout << "1 - Create Group; 2 - Show Group; 3 - Fill Group; 4 - Delete Group; 5 - Exit: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			if (group != nullptr)
			{
				cout << "Groupd already exist! Delete and create new? Yes - 1 | No - 0: ";
				int recreate(0);
				cin >> recreate;

				if (!recreate)
					break;
			}

			cout << "Kolichestvo Studentov: ";
			cin >> score;

			createGroup(group, score);
			fillGroup(group, score);
		}
		break;
		case 2:
		{
			if (group == nullptr)
				cout << "Group wasn't created\n";
			else 
				showGroup(group, score);
		}
		break;
		case 3:
		{
			if (group == nullptr)
				cout << "Group wasn't created\n";
			else
				fillGroup(group, score);
		}
		break;
		case 4:
		{
			deleteGroup(group);
		}
		break;
		case 5:
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