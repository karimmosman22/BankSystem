#pragma once
#include "DataSourceInterface.h"
#include "Parser.h"

class FileManager : public DataSourceInterface
{
public:
    void addClient(Client c) {
        fstream data;
        data.open("Clients.txt", ios::out | ios::app);
        if (data.is_open()) {
            data << c.getId() << "-" << c.getName() << "-" << c.getPassword() << "-" << c.getBalance() << endl;
            data.close();
        }
    }
    void addEmployee(Employee e) {
        fstream data;
        data.open("Employee.txt", ios::out | ios::app);
        if (data.is_open()) {
            data << e.getId() << "-" << e.getName() << "-" << e.getPassword() << "-" << e.getBalance() << "-" << e.getSalary() << endl;
            data.close();
        }
    }
    void addAdmin(Admin a) {
        fstream data;
        data.open("Admin.txt", ios::out | ios::app);
        if (data.is_open()) {
            data << a.getId() << "-" << a.getName() << "-" << a.getPassword() << "-" << a.getBalance() << "-" << a.getSalary() << endl;
            data.close();
        }
    }
    vector<Client> getAllClients() {
        fstream data;
        string line;
        data.open("Clients.txt", ios::in);
        if (data.is_open()) {
            while (getline(data, line)) {
                clients.push_back(Parser::parseToClient(line));
            }
        }
        data.close();
        return clients;
    }
    vector<Employee> getAllEmployees() {
        fstream data;
        string line;
        data.open("Employee.txt", ios::in);
        if (data.is_open()) {
            while (getline(data, line)) {
                employees.push_back(Parser::parseToEmployee(line));
            }
        }
        data.close();
        return employees;
    }
    vector<Admin> getAllAdmins() {
        fstream data;
        string line;
        data.open("Admin.txt", ios::in);
        if (data.is_open()) {
            while (getline(data, line)) {
                admins.push_back(Parser::parseToAdmin(line));
            }
        }
        data.close();
        return admins;
    }
    void removeAllClients() {
        fstream data;
        data.open("Clients.txt", ofstream::out | ofstream::trunc);
        data.close();
    }
    void removeAllEmployees() {
        fstream data;
        data.open("Employee.txt", ofstream::out | ofstream::trunc);
        data.close();
    }
    void removeAllAdmins() {
        fstream data;
        data.open("Admin.txt", ofstream::out | ofstream::trunc);
        data.close();
    }
    void clearFile(string fileName) {
        fstream data;
        data.open(fileName, ios::out | ios::trunc);
        data.close();
    }
};

