#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Person.h"
#include "Client.h"
using namespace std;


class Employee :public Person
{
private:

    double salary = 0.0;
public:
    Employee() : Person() {
        salary = 0;
    }
    Employee(int id, string name, string password, double salary) :Person(id, name, password) {
        setSalary(salary);

    }

    void setSalary(double salary) {
        if (Validation::validateSalary(salary))
            this->salary = salary;
        else cout << "Invalid salary\n";
    }
    double get_salary()
    {
        return salary;
    }
    void display()
    {
        Person::display();
        cout << "salary = " << salary << endl;
    }
    void addClient(Client& client) {
        clients.push_back(client);
    }
    Client* searchClient(int id) {
        for (Client& c : clients)
            if (c.getID() == id)
                return& c;
        return nullptr;
    }
    void listClient() {
        for (Client c : clients) {
            c.display();
            cout << "\n--------------------------------";
        }
    }
    void editClient(int id, string name, string password, double balance) {
        for (Client c : clients)
            if (c.getID() == id) {
                c.setName(name);
                c.setPassword(password);
                c.setBalance(balance);
            }
    }

};
static vector < Employee > employees;
