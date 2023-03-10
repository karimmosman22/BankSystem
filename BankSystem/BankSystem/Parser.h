#pragma once
#include "Admin.h"

class Parser {
public:
    static vector<string> split(string line) {
        int pos = 0;
        vector<string> subs;
        string sub;
        while (pos > -1) {
            pos = line.find("-");
            sub = line.substr(0, pos);
            subs.push_back(sub);
            line.erase(0, pos + 1);
        }
        return subs;
    }
    static Client parseToClient(string line) {
        vector<string> subs = split(line);
        Client c(stoi(subs[0]), subs[1], subs[2], stod(subs[3]));
        return c;
    }
    static Employee parseToEmployee(string line) {
        vector<string> subs = split(line);
        Employee e(stoi(subs[0]), subs[1], subs[2], stod(subs[3]), stod(subs[4]));
        return e;
    }
    static Admin parseToAdmin(string line) {
        vector<string> subs = split(line);
        Admin a(stoi(subs[0]), subs[1], subs[2], stod(subs[3]), stod(subs[4]));
        return a;
    }
};
