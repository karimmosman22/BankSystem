#include <iostream>
#include "FileManager.h"
using namespace std;

// Each class exists in .h file

int main()
{
    Client c1(1, "karim", "gjkrthgrgj", 4000);
    Client c2(2, "shibl", "krhhthgrgj", 6000);
    Client c3(3, "nannsi", "rhyyhgrgj", 8000);
    Employee e1(1, "gehad", "lkjmklthhlk", 3600, 7000);
    Employee e2(2, "aaaya", "jaamklthhlk", 4500, 9000);
    Admin a1(1, "mohamed", "maamklthhlw", 9000, 11000);
    FileManager f1;
    f1.addAdmin(a1);
    f1.addEmployee(e1);
    f1.addClient(c1);
    a1.addEmployee(e2);
    e1.addClient(c2);
    e1.addClient(c3);
    f1.getAllClients();
    e1.editClient(3, "nnnancy", "kkkrhyyhgrgj", 8500);
    a1.listClient();
    e1.editClient(4, "ahmmed", "krshyyhgrgj", 9900);
    f1.getAllEmployees();
    a1.listEmployee();
    f1.removeAllClients();
    f1.clearFile("Employee.txt");
    f1.removeAllAdmins();
    return 0;
}

