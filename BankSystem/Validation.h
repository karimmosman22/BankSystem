#pragma once
#include <string>
#include <ctype.h>
using namespace std;

class Validation
{
public:
    static bool validName(string n) {
        for (unsigned int i = 0; i < n.size(); i++) {
            if (!isalpha(n[i])) return false;
        }
        return (n.size() >= 5 && n.size() <= 20);
    }
    static bool validPassword(string p) {
        return (p.size() >= 8 && p.size() <= 20);
    }
    static bool validBalance(double b) {
        return (b >= 1500);
    }
    static bool validSalary(double s) {
        return (s >= 5000);
    }
};

