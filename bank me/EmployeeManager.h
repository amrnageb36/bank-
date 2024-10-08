#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
#include"FileManager.h"
#include"FileHelper.h"
#include"ClientManager.h"
using namespace std;

class EmployeeManager {
private:
	static void printEmployeeMenu() {
		system("cls");
		cout << "(1) Display my info" << endl;
		cout << "(2) Update Password" << endl;
		cout << "(3) Add new client" << endl;
		cout << "(4) Search for client" << endl;
		cout << "(5) List all clients" << endl;
		cout << "(6) Edit client info" << endl;
		cout << "(7) Logout\n" << endl;
	}
	static void back(Employee* employee) {
		cout << endl;
		system("pause");
		employeeOptions(employee);
	}
public:
	static void newClient(Employee* employee) 
	{
		system("cls");
		Client c;
		c.setID(FileHelper::getLastId("clientLastId.txt" + 1));
		c.setName(Validation::enterName());
		c.setPassword(Validation::enterPassword());
		c.setBalance(Validation::enterBalance());
		employee->addClient(c);
		FileManager::updateClients();
	}

	static void listAllClients(Employee* employee) {
		system("cls");
		cout << "All Clients : \n";
		employee->listClient();
	}

	static void searchForClient(Employee* employee) {
		int id;
		cout << "Enter the client id : \n";
		cin >> id;
		if (employee->searchClient(id) == NULL) cout << "\nClient not found.\n";
		else employee->searchClient(id)->display();
	}

	static void editClientInfo(Employee* employee) {
		system("cls");
		int id;
		cout << "Enter the client id : \n";
		cin >> id;
		if (employee->searchClient(id) == NULL) cout << "\nClient not found.\n";
		else
		{
			employee->editClient(id, Validation::enterName(), Validation::enterPassword(), Validation::enterBalance());
		}
		FileManager::updateClients();
	}

	static Employee* Login(int id, string password) {
		for (Employee& c : employees)
		{
			if (c.getID() == id && c.getPassword() == password) {
				return &c;
			}
		}
		return NULL;
	}

	static bool employeeOptions(Employee* employee) {
		system("cls");
		printEmployeeMenu();
		cout << "Your choice is: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			employee->display();
			break;
		case 2:
			system("cls");
			ClientManager::updatePassword(employee);
			FileManager::updateEmployees();
			break;
		case 3:
			system("cls");
			newClient(employee);
			break;
		case 4:
			system("cls");
			searchForClient(employee);
			break;
		case 5:
			system("cls");
			listAllClients(employee);
			break;
		case 6:
			system("cls");
			editClientInfo(employee);
			break;
		case 7:
			return false;
			break;
		default:
			employeeOptions(employee);
			return true;
			break;
		}
		back(employee);
		return true;
	}
};