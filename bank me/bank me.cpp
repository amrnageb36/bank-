#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
#include "FileHelper.h"
#include"Screens.h"
using namespace std;
int main()
{
	//Client c(1, "amrrrrrrr", "amr123456789", 50000);

	//FileHelper::clearFile("client.txt", "clientLastId.txt");
	//FileHelper::saveClient(c);
	//FileHelper::saveClient(c2);
	//FileHelper::saveClient(c3);
	//FileHelper::saveLast("clientLastId.txt", 3);

	//====================================================================

	//Employee e1(1, "anassssss", "anassss12345", 50000);
	//
	//FileHelper::clearFile("employee.txt", "employeeLastId.txt");
	//FileHelper::saveEmployee(e1);
	//FileHelper::saveEmployee(e2);
	//FileHelper::saveEmployee(e3);
	//FileHelper::saveLast("employeeLastId.txt", 3);

	//====================================================================


	//Admin a1(1, "anassssss", "anassss12345", 50000);
	//
	//FileHelper::clearFile("admin.txt", "adminLastId.txt");
	//FileHelper::saveAdmin(a1);
	//FileHelper::saveAdmin(a2);
	//FileHelper::saveAdmin(a3);
	//FileHelper::saveLast("adminLastId.txt", 3);
	//FileHelper::getEmployees();
	//FileHelper::getAdmins();
	//FileHelper::getClients();

	//cout << "amins==================================\n";
	//for (Admin a : admins) {
	//	a.display();
	//}
	//cout << "amins==================================\n";

	//for (Employee e : employees) {
	//	e.display();
	//}
	//cout << "amins==================================\n";

	///*for (Client a : clients) {
	//a.display();
	//}*/
	Screens::runApp();

	
}

