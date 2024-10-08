#pragma once
#include <iostream>
#include <string>
using namespace std;


class Validation
{
public:
	static bool validatename(string name) {
		if (!(name.size() >= 5 && name.size() <= 20)) {
			cout << "name must be alphabetic and min size is 5 and max size is 20" << endl;
			return false;
		}

		for (int i = 0; i < name.size(); i++) {
			if (!(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z')) {
				return false;
			}
		}
		return true;
	}




	static bool validatepassword(string password) {
		if (password.size() >= 8 && password.size() <= 20)
		{
			return true;
		}
		else
		{
			cout << "min password size is 8 and max is 20" << endl;
			return false;
		}
	}


	static bool validateBalance(double balance) {
		if (balance < 1500) {
			return false;
		}
		return true;
	}
	static bool validateSalary(double salary) {
		if (salary < 5000) {
			cout << "minimum salary is 5000.0" << endl;
			return false;
		}
		return true;
	}

	static string enterName() {
		string name;
		system("cls");
		cout << "Enter name\n";
		cin >> name;
		while (!validatename(name))
		{
			system("cls");
			cout << "invalid name\n";
			cout << "name must be alphabetic and min size is 5 and max size is 20\n";
			cout << "ente name\n";
			cin >> name;
		}
		return name;
	}

	static string enterPassword() {
		string pass;
		system("cls");
		cout << "Enter pass\n";
		cin >> pass;
		while (!validatepassword(pass))
		{
			system("cls");
			cout << "invalid password\n";
			cout << "min password size is 8 and max is 20" << endl;
			cout << "ente password\n";
			cin >> pass;
		}
		return pass;
	}

	static double enterBalance() {
		double balance;
		system("cls");
		cout << "Enter balance\n";
		cin >> balance;
		while (!validateBalance(balance))
		{
			system("cls");
			cout << "invalid balance\n";
			cout << "balance must be at least 1500" << endl;
			cout << "ente balance\n";
			cin >> balance;
		}
		return balance;
	}

	static double enterSalary() {
		double salary;
		system("cls");
		cout << "Enter salary\n";
		cin >> salary;
		while (!validateSalary(salary))
		{
			system("cls");
			cout << "invalid salary\n";
			cout << "balance must be at least 5000" << endl;
			cout << "enter salary\n";
			cin >> salary;
		}
		return salary;
	}



};