#pragma once
#include <iostream>
#include "Validation.h"
using namespace std;

class Person
{
protected:
    int id;
    string name;
    string password;
public:
    Person(int i = 0, string n = "", string p = "") {
        setId(i);
        setName(n);
        setPassword(p);
    }
    void setId(int i) {
        id = i;
    }
    void setName(string n) {
        if (Validation::validName(n)) {
            name = n;
        }
        else {
            cout << "Invaild Name" << endl;
        }
    }
    void setPassword(string p) {
        if (Validation::validPassword(p)) {
            password = p;
        }
        else {
            cout << "Invaild Password" << endl;
        }
    }
    int getId() {
        return id;
    }
    string getName() {
        return name;
    }
    string getPassword() {
        return password;
    }
    void display() {
        cout << "Id : " << getId() << endl
            << "Name : " << getName() << endl
            << "Password : " << getPassword() << endl;
    }
};

