#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Validation.h"
using namespace std;

class Person
{
protected:
    int id;
    string name;
    string password;
public:
    Person(int id = 0, string name = "", string password = "") {
        setId(id);
        setName(name);
        setPassword(password);
    }
    void setId(int id) {
        this->id = id;
    }
    void setName(string name) {
        if (Validation::validName(name)) {
            this->name = name;
        }
        else {
            cout << "Invaild Name" << endl;
        }
    }
    void setPassword(string password) {
        if (Validation::validPassword(password)) {
            this->password = password;
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

