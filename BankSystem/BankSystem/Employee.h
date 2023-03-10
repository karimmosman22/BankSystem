#pragma once
#include "Client.h"

class Employee : public Client
{
protected:
    double salary;
public:
    Employee(int id = 0, string name = "", string password = "", double balance = 0.0, double salary = 0.0) : Client(id, name, password, balance) {
        setSalary(salary);
    }
    void setSalary(double salary) {
        if (Validation::validSalary(salary)) {
            this->salary = salary;
        }
        else {
            cout << "Invaild Salary" << endl;
        }
    }
    double getSalary() {
        return salary;
    }
    void display() {
        cout << "Employee ";
        Person::display();
        cout << "Balance : " << getBalance() << endl
            << "Salary : " << getSalary() << endl
            << "*********************" << endl;
    }
    void addClient(Client& client) {
        fstream data;
        data.open("Clients.txt", ios::out | ios::app);
        if (data.is_open()) {
            data << client.getId() << "-" << client.getName() << "-" << client.getPassword() << "-" << client.getBalance() << endl;
            data.close();
        }
    }
    Client* searchClient(int id) {
        for (int i = 0; i < clients.size(); i++) {
            if (clients[i].getId() == id) {
                return (&clients[i]);
            }
        }
        cout << "Client that id = " << id << " does not exist. " << endl
            << "*********************" << endl;
        return NULL;
    }
    void listClient() {
        for (int i = 0; i < clients.size(); i++) {
            clients[i].display();
        }
    }
    void editClient(int id, string name, string password, double balance) {
        Client* p = searchClient(id);
        if (p == NULL)  return;
        p->setName(name);
        p->setPassword(password);
        p->setBalance(balance);
    }
};
static vector<Employee> employees;