#pragma once
#include "Admin.h"

class DataSourceInterface
{
public:
    virtual void addClient(Client c) = 0;
    virtual void addEmployee(Employee e) = 0;
    virtual void addAdmin(Admin a) = 0;
    virtual vector<Client> getAllClients() = 0;
    virtual vector<Employee> getAllEmployees() = 0;
    virtual vector<Admin> getAllAdmins() = 0;
    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;
};
