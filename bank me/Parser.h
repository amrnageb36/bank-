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
		vector <string>parts;

			while (getline(ss, s, '|')) {
				parts.push_back(s);
		}
	}
};