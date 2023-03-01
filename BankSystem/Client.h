#pragma once
#include "Person.h"

class Client : public Person
{
private:
    double balance;
public:
    Client(int i = 0, string n = "", string p = "", double b = 0.0) : Person(i, n, p) {
        setBalance(b);
    }
    void setBalance(double b) {
        if (Validation::validBalance(b)) {
            balance = b;
        }
        else {
            cout << "Invaild Balance" << endl;
        }
    }
    double getBalance() {
        return balance;
    }
    void deposit(double amount) {
        if (amount <= 0)     return;
        balance += amount;
    }
    void withdraw(double amount) {
        if (amount > getBalance() || amount <= 0)    return;
        balance -= amount;
    }
    void transferTo(double amount, Client& recipient) {
        if (amount > getBalance() || amount <= 0)    return;
        withdraw(amount);
        recipient.deposit(amount);
    }
    void checkBalance() {
        cout << "Your balance = " << getBalance() << endl;
    }
    void display() {
        Person::display();
        cout << "Balance : " << getBalance() << endl;
    }
};

