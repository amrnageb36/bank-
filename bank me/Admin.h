#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
using namespace std;

class Admin :public Person
{
private:
	double salary = 0.0;
public:
	Admin() :Person()
	{
		salary = 0;
	}
	Admin(int id, string name, string password, double salary) :Person(id, name, password) {
		setSalary(salary);

	}
	void setSalary(double salary) {
		if (Validation::validateSalary(salary))
			this->salary = salary;
		else cout << "Invalid salary\n";
	}
	double get_salary()
	{
		return salary;
	}
	void display()
	{
		Person::display();
		cout << "salary = " << salary << endl;
	}




};
