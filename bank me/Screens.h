#pragma once
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <windows.h>
#include "AdminManager.h"

using namespace std;

class Screens {
	static void bankName() {
		cout << "&& &&&&&&& &&       █████  ███    ███ ██  ██████     ██████   █████  ███    ██ ██   ██\n";
		cout << "&& &&      &&      ██   ██ ████  ████ ██ ██          ██   ██ ██   ██ ████   ██ ██  ██\n";
		cout << "&& &&&&&&& &&      ███████ ██ ████ ██ ██ ██          ██████  ███████ ██ ██  ██ █████  \n";
		cout << "&&      && &&      ██   ██ ██  ██  ██ ██ ██          ██   ██ ██   ██ ██  ██ ██ ██  ██  \n";
		cout << "&& &&&&&&& &&&&&&& ██   ██ ██      ██ ██  ██████     ██████  ██   ██ ██   ████ ██   ██ \n";
	}

	static void Welcome(){
		system("Color 4f");
		cout << "██     ██ ███████ ██       ██████  ██████  ███    ███ ███████        ██  \n";
		cout << "██     ██ ██      ██      ██      ██    ██ ████  ████ ██          ██  ██  \n";
		cout << "██  █  ██ █████   ██      ██      ██    ██ ██ ████ ██ █████           ██  \n";
		cout << "██ ███ ██ ██      ██      ██      ██    ██ ██  ██  ██ ██          ██  ██  \n";
		cout << " ███ ███  ███████ ███████  ██████  ██████  ██      ██ ███████        ██   \n";
		bankName();
		Sleep(3000);
		system("cls");
		system("Color 0f");
	}
	static void loginOptions() {
		cout << "(1) Client\n";
		cout << "(2) Employee\n";
		cout << "(3) Admin\n";
		cout << "Login as:\n";
	}
	static int LoginAs() {
		loginOptions();
		int choice;
		cin >> choice;
		if (choice == 1 || choice == 2 || choice == 3) {
			system("cls");
			return choice;
		}
		else {
			cout << "\nInvalid Choice\n";
			system("cls");
			LoginAs();
			
		}
	}
	static void InValid(int c) {
		system("cls");
		cout << "invalid id or password\n";
		loginScreen(c);
	}
	static void logOut() {
		system("cls");
		loginScreen(LoginAs());
	}
	static void loginScreen(int c) {
		int id;
		string password;
		cout << "enter your id : \n";
		cin >> id;
		cout << "enter your password : \n";
		cin >> password;
		switch (c)
		{
		case 1:
			if (!ClientManager::Login(id, password) == NULL)
			{
				while (ClientManager::clientOptions(ClientManager::Login(id, password)) != false) 
				{
					logOut();
				}
			}
			else 
			{
				InValid(1);
			}
			break;
		case 2:
			if (!EmployeeManager::Login(id, password) == NULL)
			{
				while (EmployeeManager::employeeOptions(EmployeeManager::Login(id, password)) != false)
				{
					logOut();
				}
			}
			else
			{
				InValid(2);
			}	
			break;
		case 3:
			if (!AdminManager::Login(id, password) == NULL)
			{
				while (AdminManager::adminOptions(AdminManager::Login(id, password)) != false)
				{
					logOut();
				}
			}
			else
			{
				InValid(3);
			}
			break;
		default:
			system("cls");
			LoginAs();
			break;
		}
	}
	public :
		static void runApp() {
			FileManager::getAllData();
			Welcome();
			loginScreen(LoginAs());
		}

};
