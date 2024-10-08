#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
using namespace std;


class Admin :public Employee
{
private:
	double salary = 0.0;
public:
	Admin() :Employee()
	{
		salary = 0;
	}
	Admin(int id, string name, string password, double salary) :Employee(id, name, password,salary) {
	}
	
	void addEmployee(Employee& employee) {
		employees.push_back(employee);
	}
	Employee searchEmployee(int id) {
		for (Employee e : employees)
			if (e.getID() == id)
				return e;
		throw exception("not found");
		
	}
	void listEmployee() {
		for (Employee e : employees)
			e.display();
	}
	void editEmployee(int id, string name, string password, double salary) {
		for (Employee e : employees)
			if (e.getID() == id) {
				e.setName(name);
				e.setPassword(password);
				e.setSalary(salary);
			}
	}
};
static vector < Admin > admins;
