#include "pch.h"
#include <iostream>
#include "Employee.h"
#include <vector>
#include <string>
#include <cstdlib>



using namespace std;

void menu();
string Positions[] = { "Developer", "HR", "Manager", "Teacher", "LSMAnager" };

int main()
{
	//Employee* empl = new LSManager;

	//SalaryInfo salary;
	//salary.Bonus = 100;
	//salary.LessonBase = 10;
	//salary.LessonDuration = 3;
	//salary.MGREficienty = 90;

	//if (empl->Hire("10.11.2018"))
	//	empl->SetSalaryInfo(salary);
	//
	//delete empl;
	//system("pause");
	menu();
	return 0;
}



void menu()
{
	std::vector<Employee*> employees;
	bool exit = false;
	Employee* tmp;
	SalaryInfo salary;
	salary.Bonus = 100;
	salary.LessonBase = 10;
	salary.LessonDuration = 3;
	salary.MGREficienty = 90;
	while (!exit)
	{
		int choice;
		cout << "1 - Create employee and Fill him: " << endl << "2 - Show employees: " << endl << "3 - Choose Bonus and Base: " << endl <<"4 - Hire: "<<endl<<"5 - Terminate: "<< endl <<"6 - Exit: " << endl;
		cin >> choice;
		system("cls");

		switch (choice)
		{
		case 1:
		{
			{
				int choice;
				for (int i(0); i < 5; ++i)
				{
					cout << i + 1 << " - " << Positions[i] << endl;
				}
				cin >> choice;
				if (choice > 0 && choice <= 5)
				{
					system("cls");
					switch (choice)
					{
					case 1:
					{
						tmp = new Developer;
					}
					break;
					case 2:
					{
						tmp = new HR;
					}
					break;
					case 3:
					{
						tmp = new Manager;
					}
					break;
					case 4:
					{
						tmp = new Teacher;
					}
					break;
					case 5:
					{
						tmp = new LSManager;
					}
					break;

					}
					employees.push_back(tmp);
					tmp->FillEmployee(tmp, choice);
					system("cls");
					tmp->ShowEmployee(tmp);
					tmp->isTerminate();
					system("pause");
					system("cls");
				}
				else
				{
					system("cls");
					cout << "Wrong choice" << endl;
					system("pause");
					system("cls");
				}
			}

		}
		break;

		case 2:
		{
			if (employees.size() > 0)
				for (int i(0); i < employees.size(); ++i)
				{
					cout << "Number: " << i + 1 << endl;
					employees[i]->ShowEmployee(employees[i]);
				}
			else
				cout << "Employees not Found" << endl;
			system("pause");
			system("cls");
		}
		break;

		case 3:
		{
			if (employees.size() > 0)
			{
				int number;
				cout << "Choose employee" << endl << "\n\n\n";
				for (int i(0); i < employees.size(); ++i)
				{
					cout << "Number: " << i + 1 << endl;
					employees[i]->ShowEmployee(employees[i]);
				}
				cin >> number;

				if (number > 0)
				{
					if (employees.size() >= number)
					{
						unsigned int Base;
						unsigned int Bonus;
						cout << "Add Base" << endl;
						cin >> Base;
						cout << "Add Bonus" << endl;
						cin >> Bonus;
						employees.at(number - 1)->SetBase(Base);
						employees.at(number - 1)->SetBonus(Bonus);
					}
					else
						cout << "Employees not found" << endl;
					system("pause");
				}
				else
					cout << "Wrong choice, please try again" << endl;
				system("cls");
			}
			else
				cout << "Employees not Found" << endl;

		}
		break;

		case 4:
		{

			if (employees.size() > 0)
			{
				int number;
				cout << "Choose employee" << endl << "\n\n\n";
				for (int i(0); i < employees.size(); ++i)
				{
					cout << "Number: " << i + 1 << endl;
					employees[i]->ShowEmployee(employees[i]);
				}

				cin >> number;

				if (number > 0)
				{
					if (employees.size() >= number)
					{
						string HireDay;
						cout << "Please, write day of hiring this human: " << endl;
						cin >> HireDay;
						employees.at(number - 1)->Hire(HireDay);
					}
					else
						cout << "Employees not found" << endl;
					system("pause");
				}
				else
					cout << "Wrong choice, please try again" << endl;
				system("cls");
			}
			else
				cout << "Employees not Found" << endl;
			system("cls");
		}
		break;

		case 5:
		{
			if (employees.size() > 0)
			{
				int number;
				cout << "Choose employee" << endl << "\n\n\n";
				for (int i(0); i < employees.size(); ++i)
				{
					cout << "Number: " << i + 1 << endl;
					employees[i]->ShowEmployee(employees[i]);
				}

				cin >> number;

				if (number > 0)
				{
					if (employees.size() >= number)
					{
						string TerminateDay;
						cout << "Please, write day of Terminating this human: " << endl;
						cin >> TerminateDay;
						employees.at(number - 1)->Terminate(TerminateDay);
					}
					else
						cout << "Employees not found" << endl;
					system("pause");
				}
				else
					cout << "Wrong choice, please try again" << endl;
				system("cls");
			}
			else
				cout << "Employees not Found" << endl;
			system("cls");
		}
		break;
		case 6:
		{

			exit = true;
			employees.clear();
			break; 
		}

		default:
		{
			cout << "Wrong choice!\n";
			break;
		}
		
		employees.empty();
		system("pause");
		system("cls");
		}
	}
}