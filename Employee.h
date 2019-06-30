#pragma once
#include "SalaryInfo.h"
#include <string>
#include <vector>
#include <iostream>
#include "pch.h"


class Employee
{
protected:
	std::string mPosition;
	std::string mName;
	std::string mBirthDay;
	std::string mHireDay;
	std::string mTerminateDay;
	std::string positions[5] = { "Developer", "HR", "Manager", "Teacher", "LSMAnager" };
	bool mTerminate = true;
	unsigned int mBase = 0;
	unsigned int mBonus = 0;
	unsigned int mSalary = 0;

	
public:
	void ShowEmployee(Employee* value);
	void FillEmployee(Employee* value, int choice);
	void SetName(std::string value) { mName = value; };
	void SetBirthDay(std::string value) { mBirthDay = value; };
	void SetPosition(std::string value) { mPosition = value; };
	bool Hire(std::string value);
	bool Terminate(std::string value);
	void SetBase(unsigned int value) { mBase = value; };
	void SetBonus(unsigned int value) { mBonus = value; };
	bool MakePayment();
	bool isTerminate() const { return mTerminate; }


	virtual void SetSalaryInfo(const SalaryInfo& value) = 0;

	virtual ~Employee() {};
};

class Developer : public Employee
{
public:
	virtual void SetSalaryInfo(const SalaryInfo& value);
private:

protected:

};



class HR : public Employee
{
public:
	virtual void SetSalaryInfo(const SalaryInfo& value);
private:

protected:

};



class Manager : virtual public Employee
{
public:
	virtual void SetSalaryInfo(const SalaryInfo& value);
	
private:

protected:
	virtual void CalculateManagerSalary(const SalaryInfo& value);
};


class Teacher : virtual public Employee
{
public:
	virtual void SetSalaryInfo(const SalaryInfo& value);
	
private:

protected:
	virtual void CalculateLessonSalary(const SalaryInfo& value);
};



class LSManager : public Manager, public Teacher
{
public:
	virtual void SetSalaryInfo(const SalaryInfo& value);
private:

protected:

};


