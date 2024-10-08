#pragma once
#include "FileHelper.h"
#include "DataSourceInterface.h"
class FileManager :public DataSourceInterface
{
public:
	static void addClient(Client client)
	{
		FileHelper::saveClient(client);
	}
	static void addAdmin(Admin admin)
	{
		FileHelper::saveAdmin(admin);
	}
	static void addEmployee(Employee employee)
	{
		FileHelper::saveEmployee(employee);
	}
	static void getAllAdmins()
	{
		FileHelper::getAdmins();
	}
	static void getAllClients()
	{
		FileHelper::getClients();
	}
	static void getAllEmployees()
	{
		FileHelper::getEmployees();
	}
	static void removeAllAdmins()
	{
		FileHelper::clearFile("admin.txt", "adminLastId.txt");
	}
	static void removeAllEmployees()
	{
		FileHelper::clearFile("employee.txt", "employeeLastId.txt");
	}
	static void removeAllClients()
	{
		FileHelper::clearFile("client.txt", "clientLastId.txt");
	}
	static void getAllData() {
		getAllClients();
		getAllAdmins();
		getAllEmployees();
	}

	static void updateClients() {
		removeAllClients();
		for (auto it = clients.begin(); it != clients.end(); it++)
		{
			addClient(*it);
		}
	}
	static void updateAdmins() {
		removeAllAdmins();
		for (auto it = admins.begin(); it != admins.end(); it++)
		{
			addAdmin(*it);
		}
	}
	static void updateEmployees() {
		removeAllEmployees();
		for (auto it = employees.begin(); it != employees.end(); it++)
		{
			addEmployee(*it);
		}
	}
};
		
	

