#include <iostream>
#include <string>
#include <vector>

using namespace std;
const string positions[] = { "trainee", "junior", "intermediate", "senior", "tech lead", "architect" };
const string OPR_ERROR_MSG = "Operation cannot perfomed\n";
#define OPR_SUCCEED_MSG cout <<"Operation is succeed\n"

struct Worker {
	string Name;
	string Surname;
	unsigned int Salary;
	string Position;
	bool Terminated = false;
	bool Created = false;
};

Worker CreateWorker();
void FillWorker(Worker&);
void ShowWorker(Worker&);
bool TerminatedWorker(Worker&);
bool HireBack(Worker&);
bool ChangeSalary(Worker&);
bool ChangePosition(Worker&);
void ChoosePosition(string&);
void menu();
void func(vector<int> p2)
{
	p2[1] = 77;
}

void func(string str)
{
	str[3] = 'Z';
	cout << str << endl;
}

int main() {

	menu();
	/*vector<int> p1;
	string str = "1234567890";
	p1.push_back(5);
	p1.push_back(6);
	for (int i(0); i < p1.size(); ++i)
		cout << p1[i] << endl;
	func(p1);
	for (int i(0); i < p1.size(); ++i)
		cout << p1[i] << endl;

	cout << str << endl;
	func(str);
	cout << str << endl; */

	system("pause");
	return 0;
}

Worker CreateWorker() {

	Worker employee;
	
	return employee;
	
}


void FillWorker(Worker& employee)
{
	cout << "Fill Name: ";
	cin >> (employee).Name;
	cout << "Fill Surname: ";
	cin >> (employee).Surname;
	cout << "Fill Salary: ";
	cin >> (employee).Salary;
	cout << "Fill Position: ";
	ChoosePosition(employee.Position);
	employee.Created = true;
	system("cls");
}
void ShowWorker(Worker& employee) {
	cout << "Name: " << (employee).Name << endl;
	cout << "Surname: " << (employee).Surname << endl;
	cout << "Salary: " << (employee).Salary << endl;
	cout << "Position: " << (employee).Position << endl;
	cout << "Terminated: " << (employee).Terminated << endl;
}
void ChoosePosition(string& position) {
	bool exit = true;
	
	do
	{
		exit = true;
		//cout << "1 - trainee, 2 - junior, 3 - intermediate, 4 - senior, 5 - tech lead, 6 - architect: ";
		for (int i(0); i < 6; ++i)
			cout << i + 1 << " - " << positions[i] << endl;

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			position = positions[0];
		break;
		case 2:
			position = positions[1];
		break;
		case 3:
			position = positions[2];
		break;
		case 4:
			position = positions[3];
		break;
		case 5:
			position = positions[4];
		break;
		case 6:
			position = positions[5];
		break;

		default:
			cout << "Wrong choice!\n";
			exit = false;
			system("pause");
			break;
		}

		system("cls");
	} while (!exit);
}
bool TerminatedWorker(Worker& employee) {
	if (employee.Terminated == false) {
		employee.Terminated = true;
	
		return true;
	}
	else 
		return false;

}
bool ChangeSalary(Worker& employee) {
	if (employee.Terminated == false) {
		cout << "Add new Salary for Employee" << endl;
		cin >> employee.Salary;
		//cout <<"New Salary is  " <<employee.Salary << endl;
		return true;
			
	}
	else
		return false;
}
bool ChangePosition(Worker& employee) {
	if (employee.Terminated == false){
		cout << "Please, change new Position for employee! " << endl;
		ChoosePosition(employee.Position);
		
		//void choosePosition(string& vasya) 
		//cout << "New position is " << employee.Position << endl;
	return true;
}
	else
		return false;
}
bool HireBack(Worker& employee) {
	if (employee.Terminated == true) {
		employee.Terminated = false;

		return true;
	}
	else
		return false;

}
void menu()
{
	vector<Worker>	employees;
	bool exit = false;
	while (!exit)
	{
		cout << "1 - Add employee and Fill him;\n2 - ReFill employee;\n3 - Delete employee;\n4 - Terminated employee;\n5 - Return employee;\n6 - Change Salary;\n7 - Change Position;\n8 - Show employee\n9 - Exit\nChoose: ";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			
			employees.push_back(CreateWorker());
			for (int i(0); i < employees.size(); ++i)
			{
				if (!employees[i].Created)
					FillWorker(employees[i]);

			}
			cout << "Add new worker: " << employees.size() << endl;
		}
		break;

		case 2: 
		{										
				int b;
				cout << "Choose employee" << endl << "Kolichestvo: " << employees.size() << endl;
				cin >> b;
				if  (employees.size() >= b) {
					FillWorker(employees.at(b - 1));
				OPR_SUCCEED_MSG; 
				}
				else 				
				   cout << "Employees not found" << endl;
		}
		break;


		case 3:
		{
			int b;
			cout << "Choose element"<<endl<<employees.size()<<endl;
			cin >> b;
			if (employees.size() >= b)
			{
				employees.erase(employees.begin() + b - 1);
			}
			else cout << "Employees not Found" << endl;
		}
		break;

		case 4:
		{
			int choice;
			cout << "1 - All employees 2 - Only one" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				for (int i(0); i < employees.size(); ++i)
				{
					if (!TerminatedWorker(employees[i]))
						cout << OPR_ERROR_MSG;
					else
						OPR_SUCCEED_MSG;
				}
			}
			case 2:
			{				
					int b;
					cout << "Choose employee" << endl << "Score of people: " << employees.size() << endl;
					cin >> b;
					if (employees.size() >= b) {
						if (!TerminatedWorker(employees.at(b-1)))
							cout << OPR_ERROR_MSG;
						else
							OPR_SUCCEED_MSG;
					}
					else 
						cout << "Employees not found" << endl;
			}
			}
		}
		break;
		case 5:
		{
			int choice;
			cout << "1 - All employees 2 - Only one" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: 
			{
				for (int i(0); i < employees.size(); ++i)
				{
					if (!HireBack(employees[i]))
						cout << OPR_ERROR_MSG;
					else
						OPR_SUCCEED_MSG;
				}
			}
			break;
			case 2:
			{								
					int b;
					cout << "Choose employee" << endl << "Score of People: " << employees.size() << endl;
					cin >> b;
					if (employees.size() >= b) {
						if (!HireBack(employees.at(b-1)))
							cout << OPR_ERROR_MSG;
						else
							OPR_SUCCEED_MSG;
					}
					else
						cout << "Employees not found" << endl;
			}
			break;
			}
		}
		break;
		case 6:
		{
			int choice;
			cout << "1 - All employees 2 - Only one" << endl;
			cin >> choice;
			switch (choice) {
			case 1:
			{
				for (int i(0); i < employees.size(); ++i)
				{
					if (!ChangeSalary(employees[i]))
						cout << OPR_ERROR_MSG;
					else
						OPR_SUCCEED_MSG;
				}
			}
			break;
			case 2:
			{							
					int b;
					cout << "Choose employee" << endl << "Score of people: " << employees.size() << endl;
					cin >> b;
					if (employees.size() >= b) {
						if (!ChangeSalary(employees.at(b-1)))
							cout << OPR_ERROR_MSG;
						else
							OPR_SUCCEED_MSG;
					}
					else
						cout << "Employees not found" << endl;
			}
			}
		}
		break;

		case 7:
		{
			{
				int choice;
				cout << "1 - All employees 2 - Only one" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{

					for (int i(0); i < employees.size(); ++i)
					{
						if (!ChangePosition(employees[i]))
							cout << OPR_ERROR_MSG;
						else
							OPR_SUCCEED_MSG;
					}
				}
				break;
				case 2:
				{										
						int b;
						cout << "Choose employee" <<endl <<"Score of People: "<<employees.size() << endl;
						cin >> b;
						if (employees.size() >= b) {
							if (!ChangePosition(employees.at(b-1)))
								cout << OPR_ERROR_MSG;
							else
								OPR_SUCCEED_MSG;
						}
						else
							cout << "Employees not found" << endl;
				}
					break;
				}
				}
			
		}
		break;
		case 8: 
		{
			int choice;
			cout << "1 - All employees 2 - Only one" << endl;
		    cin >> choice;
		    switch (choice)
		{
		      case 1:
		{
				  if (employees.size() > 0)
					  for (int i(0); i < employees.size(); ++i)
					  {
						  ShowWorker(employees[i]);
					  }
				  else
					  cout << "Employees not Found" << endl;
		}
		         break;

		      case 2:
		{
			    			
				     int b;
				     cout << "Choose employee: "<<employees.size()<<endl;
				     cin >> b;
					 if (employees.size() >= b)
					 {
						 ShowWorker(employees.at(b - 1));
						 cout << OPR_ERROR_MSG;
					 }
					 else 
						 cout << "Employees not found" << endl;

			
		}
		         break;
		}
		}
		break;
	
		case 9:
			exit = true;
			employees.clear();
			break;
		default:
			cout << "Wrong choice!\n";
			break;
		}

		//employees.empty();
		//employees.clear();
		//employees.operator[];
	

		system("pause");
		system("cls");
	}

}






/*push_back(element) Ч добавить элемент в конец объект-вектора
pop_back(element) Ч удалить последний элемент объект - вектора
sizeof() Ч „исло элементов в векторе
capacity() Ч ¬местимость вектора
insert(Е) Ч —уществует три варианта вставки в какую - либо область в объект - векторе.ѕервый аргумент Ч позици€ вставки, заданна€ итератором, остальные указывают на контейнер, или количество и контейнер, или пару итераторов, указывающих от какой и до какой позиции из другого контейнера вз€ть данные.
erase(iterator или iterator от, и до) Ч ”дал€ет элемент или последовательность элементов из объект - вектора.
begin() Ч ¬озвращает итератор, указывающий на начало коллекции.
end() Ч ¬озвращает итератор, указывающий на конец коллекции.ѕри этом он указывает не самый последний элемент, а на "воображаемый элемент за последним.
at(index) Ч ћетод доступа к элементам коллекции, в отличие от операции[] провер€ет выход из - за границ коллекции, и в случае чего генерит исключение.
clear() Ч ”дал€ет все элементы коллекции, при этом если в объект - векторе содержатс€ объекты классов, вызывает их деструкторы.ј если же содержатс€ указатели на объекты, то может произойти утечка пам€ти(memory leaks = ), так как delete, если будет нужен, ничто и никто не зазовЄт.
reserve(число) Ч –езервирует определЄнный объЄм пам€ти под указанную вместимость
resize(число) Ч »змен€ет актуальный размер вектора под указанное число элементов.
shrink_to_fit() Ч ¬ыравнивает фактический размер и зарезервированный размер памти, путЄм усечени€ резервных €чеек.(—++11 и новее)*/