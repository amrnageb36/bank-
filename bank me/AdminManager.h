#pragma once
#include "EmployeeManager.h"

using namespace std;

class AdminManager {
private:
	static void printAdminMenu() {
		system("cls");
		cout << "(1) Display my info" << endl;
		cout << "(2) Update Password" << endl;
		cout << "(3) Add new client" << endl;
		cout << "(4) Search for client" << endl;
		cout << "(5) List all clients" << endl;
		cout << "(6) Edit client info" << endl;
		cout << "(7) Add new Employee" << endl;
		cout << "(8) Search for Employee" << endl;
		cout << "(9) List all Employees" << endl;
		cout << "(10) Edit Employee info" << endl;
		cout << "(11) Logout\n" << endl;
	}
	static void back(Admin* admin) {
		cout << endl;
		system("pause");
		//adminOptions(admin);
	}

public :
	static Admin* Login(int id, string password) {
		for (Admin& c : admins)
		{
			if (c.getID() == id && c.getPassword() == password) {
				return &c;
			}
		}
		return NULL;
	}

	static bool adminOptions(Admin* admin) {
		system("cls");
		printAdminMenu();
		int choice,id;
		Employee c;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			admin->display();
			break;
		case 2:
			ClientManager::updatePassword(admin);
			FileManager::updateAdmins();
		case 3:
			EmployeeManager::newClient(admin);
			FileManager::updateClients();
		case 4:
			EmployeeManager::searchForClient(admin);
		case 5:
			EmployeeManager::listAllClients(admin);
		case 6:
			EmployeeManager::editClientInfo(admin);
		case 7:
				system("cls");
				c.setID(FileHelper::getLastId("employeeLastId.txt" + 1));
				c.setName(Validation::enterName());
				c.setPassword(Validation::enterPassword());
				c.setSalary(Validation::enterBalance());
				admin->addEmployee(c);
				FileManager::updateClients();
		case 8:
			cout << "Enter the client id : \n";
			cin >> id;
			if (admin->searchClient(id) == NULL) cout << "\nClient not found.\n";
			else admin->searchClient(id)->display();
		case 9:
			system("cls");
			admin->listEmployee();
		case 10:
			system("cls");
			cout << "Enter the client id : \n";
			cin >> id;
			if (admin->searchClient(id) == NULL) cout << "\nClient not found.\n";
			else {
				admin->editClient(id, Validation::enterName(), Validation::enterPassword(), Validation::enterBalance());
			}
			FileManager::updateClients();
		case 11:
			return false;
			break;
		default:
			adminOptions(admin);
			return true;
			break;
		}
		back(admin);
		return true;
	}
};