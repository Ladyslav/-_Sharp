#include "pch.h"
#include "Employee.h"
#include <vector>
#include <iostream>


void Employee::FillEmployee(Employee* value, int choice)
{
	std::string name;
	std::string birthday;
	for (int i(0); i < 5; ++i)
	{
		std::cout << i + 1 << " - " << positions[i] <<std::endl;
	}
	value->SetPosition(positions[choice-1]);
	std::cout << "Write name: " << std::endl;
	std::cin >> name;
	value->SetName(name);
	std::cout << "Write date of Birthday: " << std::endl;
	std::cin >> birthday;
	value->SetBirthDay(birthday);
};

void Employee::ShowEmployee(Employee* value) 
{
	std::cout <<"Position: "<<mPosition<<std::endl << "Name: " << mName << std::endl << "Birthday: " << mBirthDay << std::endl << "Base: " << mBase << std::endl << "Bonus: " << mBonus << std::endl<<"Employee status: "<<mTerminate<<std::endl<<"Day of Hiring: "<<mHireDay<<std::endl <<"Day of Terminating: "<<mTerminateDay<< "\n\n";
}

bool Employee::Hire(std::string value)
{
	if (mTerminate)
	{
		mHireDay = value;
		mTerminate = false;
		return true;
	}
	
	return false;
}

bool Employee::Terminate(std::string value)
{
	if (!mTerminate)
	{
		mTerminateDay = value;
		mTerminate = true;

		return true;
	}

	return false;
}

bool Employee::MakePayment()
{
	if (mSalary != 0)
	{
		/*Где-то тут мы делаем банковский перевод на счет сотрудника!!!*/
		mSalary = 0;
		return true;
	}

	return false;
}


void Developer::SetSalaryInfo(const SalaryInfo& value)
{
	mBonus = value.Bonus;
}

void HR::SetSalaryInfo(const SalaryInfo& value)
{
	/*if (value.HREficienty > 50)
		mBonus = value.Bonus;
	else if (value.HREficienty > 25)
		mBonus = value.Bonus * 0.25;
	else
		mBonus = 0;*/
}

void Manager::SetSalaryInfo(const SalaryInfo& value)
{
	CalculateManagerSalary(value);
}

void Manager::CalculateManagerSalary(const SalaryInfo& value)
{
	/*if (value.MGREficienty > 75)
		mBonus = value.Bonus;
	else if (value.MGREficienty > 60)
		mBonus = value.Bonus * 0.4;
	else
		mBonus = 0;*/
}

void Teacher::SetSalaryInfo(const SalaryInfo& value)
{
	CalculateLessonSalary(value);
}

void Teacher::CalculateLessonSalary(const SalaryInfo& value)
{
	mSalary += value.LessonBase * value.LessonDuration;
}

void LSManager::SetSalaryInfo(const SalaryInfo& value)
{
	if (value.LessonDuration != 0)
		CalculateLessonSalary(value);

	if (value.MGREficienty != 0)
		CalculateManagerSalary(value);
}