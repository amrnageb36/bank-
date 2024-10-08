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
using namespace std;

class ClientManager {
public :
	static void PrintClientMenu() {
		system("cls");
		cout << "(1) " << "Display My Info " << endl;
		cout << "(2) " << "Check Balance  " << endl;
		cout << "(3) " << "Update password " << endl;
		cout << "(4) " << "Withdraw " << endl;
		cout << "(5) " << "Deposit " << endl;
		cout << "(6) " << "Transfer amount " << endl;
		cout << "(7) " << "Logout " << endl;
	}
	static void back(Client* client) {
		cout << endl;
		system("pause");
		clientOptions(client);
	}
	static void updatePassword(Person* person) {
		cout << "Enter new password\n ";
		string newPassword;
		person->setPassword(Validation::enterPassword());
	}

	static Client* Login(int id, string password) {
		for (Client& c : clients)
		{
			if (c.getID() == id&&c.getPassword()==password) {
				return &c;
			}
		}
		return NULL;
	}

	static bool clientOptions(Client* client) {
		PrintClientMenu();
		cout << "enter your choice\n";
		double amount;
		int id;
		Employee e;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			client->display();
			break;
		case 2:
			system("cls");
			cout << client->getBalance();
			break;
		case 3:
			system("cls");
			updatePassword(client);
			FileManager::updateClients();
			break;
		case 4:
			system("cls");
			cout << "\nEnter the Amount \n";
			cin >> amount;
			client->withdraw(amount);
			FileManager::updateClients();
			break;
		case 5:
			system("cls");
			cout << "\nEnter the Amount \n";
			cin >> amount;
			client->deposit(amount);
			FileManager::updateClients();
			break;
		case 6:
			system("cls");
			cout << "\nEnter the Amount \n";
			cin >> amount;
			cout << "\nEnter the other client id \n";
			cin >> id;
			while (e.searchClient(id) == NULL)
			{
				system("cls");
				cout << "Invalid id.\n";
				cout << "\nEnter id of the recipient: ";
				cin >> id;
			}
			client->transferTo(amount, *e.searchClient(id));
			FileManager::updateClients();
			break;
		case 7:
			return false;
			break;
		default:
			system("cls");
			clientOptions(client);
			return true;
			break;
		}
		back(client);
		return true;
	}
};