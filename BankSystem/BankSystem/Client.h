#pragma once
#include "Person.h"

class Client : public Person
{
protected:
    double balance;
public:
    Client(int id = 0, string name = "", string password = "", double balance = 0.0) : Person(id, name, password) {
        setBalance(balance);
    }
    void setBalance(double balance) {
        if (Validation::validBalance(balance)) {
            this->balance = balance;
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
        setBalance(getBalance() + amount);
    }
    void withdraw(double amount) {
        if (amount > getBalance() || amount <= 0)    return;
        setBalance(getBalance() - amount);
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
        cout << "Client ";
        Person::display();
        cout << "Balance : " << getBalance() << endl
            << "*********************" << endl;
    }
};
static vector<Client> clients;
