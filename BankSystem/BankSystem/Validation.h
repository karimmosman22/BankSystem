#pragma once
#include <string>
#include <ctype.h>
using namespace std;

class Validation
{
public:
    static bool validName(string name) {
        for (unsigned int i = 0; i < name.size(); i++) {
            if (!isalpha(name[i])) return false;
        }
        return (name.size() >= 5 && name.size() <= 20);
    }
    static bool validPassword(string password) {
        return (password.size() >= 8 && password.size() <= 20);
    }
    static bool validBalance(double balance) {
        return (balance >= 1500);
    }
    static bool validSalary(double salary) {
        return (salary >= 5000);
    }
};

