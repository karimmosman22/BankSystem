#pragma once
#include "Person.h"

class Employee : public Person
{
protected:
    double salary;
public:
    Employee(int i = 0, string n = "", string p = "", double s = 0.0) : Person(i, n, p) {
        setSalary(s);
    }
    void setSalary(double s) {
        if (Validation::validSalary(s)) {
            salary = s;
        }
        else {
            cout << "Invaild Salary" << endl;
        }
    }
    double getSalary() {
        return salary;
    }
    void display() {
        Person::display();
        cout << "Salary : " << getSalary() << endl;
    }
};
