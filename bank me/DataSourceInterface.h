#pragma once
#include <iostream>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

class DataSourceInterface {
public:
	virtual void addClient(Client) = 0;
	virtual void addEmployee(Employee) = 0;
	virtual void addAdmin(Admin) = 0;
	virtual void getAllClients() = 0;
	virtual void getAllEmployees() = 0;
	virtual void getAllAdmins() = 0;
	virtual void removeAllClients() = 0;
	virtual void removeAllEmployees() = 0;
	virtual void removeAllAdmins() = 0;
};
