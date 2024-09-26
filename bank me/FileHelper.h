#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
using namespace std;

class FileHelper
{
public :
	static void saveLast(string fileName, int id)
	{
		fstream file(fileName, ios::out);
		file << id;
		file.close();
	}
	static int getLastId(string fileName)
	{
		fstream file(fileName, ios::in);
		string id;
		file >> id;
		file.close();
		return stoi(id);
	}
	static void saveClient(Client c)
	{
		c.setID(getLastId("clientLastId.txt") + 1);
		saveLast("clientLastId.txt", c.getID());
		fstream f("client.txt", ios::app);
		f << c.getID() << "|" << c.getName() << "|" << c.getPassword() << "|" << c.getBalance() << endl;
		f.close();
	}
	static void saveEmployee(Employee e)
	{
		e.setID(getLastId("employeeLastId.txt")+1);
		saveLast("employeeLastId.txt", e.getID());
		fstream f("employee.txt", ios::app);
		f << e.getID() << "|" << e.getName() << "|" << e.getPassword() << "|" << e.get_salary()<< endl;
		f.close();
		
	}
	static void saveAdmin(Admin a)
	{
		a.setID(getLastId("adminLastId.txt") + 1);
		saveLast("adminLastId.txt", a.getID());
		fstream f("admin.txt", ios::app);
		f << a.getID() << "|" << a.getName() << "|" << a.getPassword() << "|" << a.get_salary() << endl;
		f.close();
	}
	static void getClients()
	{
		fstream f("client.txt", ios::in);
		string line;
		while (getline(f, line)) {
			Client c = Parser::praseToClient(line);
			clients.push_back(c);
		}
		f.close();
	}
	static void getEmployees()
	{
		fstream f("employee.txt", ios::in);
		string line;
		while (getline(f, line)) {
			Employee e = Parser::praseToEmployee(line);
			employees.push_back(e);
		}
		f.close();
	}
	static void getAdmins()
	{
		fstream f("admin.txt", ios::in);
		string line;
		while (getline(f, line)) {
			Admin a = Parser::praseToAdmin(line);
			admins.push_back(a);
		}
		f.close();
	}
	static void clearFile(string fileName, string lastID) {
		fstream f(fileName, ios::out | ios::trunc);
		fstream f2(lastID, ios::out | ios::trunc);
		f2 << 0;
	}
};