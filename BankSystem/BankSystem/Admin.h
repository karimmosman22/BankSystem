#pragma once
#include "Employee.h"

class Admin : public Employee
{
public:
    Admin(int id = 0, string name = "", string password = "", double balance = 0.0, double salary = 0.0) : Employee(id, name, password, balance, salary) {}
    void display() {
        cout << "Admin ";
        Person::display();
        cout << "Balance : " << getBalance() << endl
            << "Salary : " << getSalary() << endl
            << "*********************" << endl;
    }
    void addEmployee(Employee& employee) {
        fstream data;
        data.open("Employee.txt", ios::out | ios::app);
        if (data.is_open()) {
            data << employee.getId() << "-" << employee.getName() << "-" << employee.getPassword() << "-" << employee.getBalance() << "-" << employee.getSalary() << endl;
            data.close();
        }
    }
    Employee* searchEmployee(int id) {
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i].getId() == id) {
                return (&employees[i]);
            }
        }
        cout << "Employee that id = " << id << " does not exist. " << endl
            << "*********************" << endl;
        return NULL;
    }
    void listEmployee() {
        for (int i = 0; i < employees.size(); i++) {
            employees[i].display();
        }
    }
    void editEmployee(int id, string name, string password, double balance, double salary) {
        Employee* p = searchEmployee(id);
        if (p == NULL) return;
        p->setName(name);
        p->setPassword(password);
        p->setBalance(balance);
        p->setSalary(salary);
    }
};
static vector<Admin> admins;
