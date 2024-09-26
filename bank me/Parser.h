#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

class Parser {
public :
	static vector<string> split(string line)
	{
		stringstream ss(line);
		string s;
		vector <string>info;
		while (getline(ss, s, '|')) {
			info.push_back(s);
		}
		return info;
	}
	static Client  praseToClient(string line)
	{
		vector<string>info = split(line);
		Client client;
		client.setID(stoi(info[0]));
		client.setName(info[1]);
		client.setPassword(info[2]);
		client.setBalance(stod(info[3]));
		return client;
	}
	static Employee  praseToEmployee(string line)
	{
		vector<string>info = split(line);
		Employee Employee;
		Employee.setID(stoi(info[0]));
		Employee.setName(info[1]);
		Employee.setPassword(info[2]);
		Employee.setSalary(stod(info[3]));
		return Employee;
	}
	static Admin  praseToAdmin(string line)
	{
		vector<string>info = split(line);
		Admin Admin;
		Admin.setID(stoi(info[0]));
		Admin.setName(info[1]);
		Admin.setPassword(info[2]);
		Admin.setSalary(stod(info[3]));
		return Admin;
	}
};