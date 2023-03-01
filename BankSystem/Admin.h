#pragma once
#include "Employee.h"

class Admin : public Employee
{
public:
	Admin(int i = 0, string n = "", string p = "", double s = 0.0) : Employee(i, n, p, s) {}
};

