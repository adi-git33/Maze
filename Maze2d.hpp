// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052

#pragma once
#include "Memory.hpp"

using namespace std;

class Employee
{
private:
    int m_IDLen;
    string m_id;
    int m_salary;
    int m_seniority;

public:
    // Constractor
    Employee()
    {
        m_IDLen = 9;
        m_id = "000000000";
        m_salary = 0;
        m_seniority = 0;
    };
    Employee(int newIDLen, string newId, int newSalary, int newSenior) : m_IDLen(newIDLen), m_id(newId), m_salary(newSalary), m_seniority(newSenior){};
    // Destractor
    ~Employee() { m_id.clear(); };
    // Getters
    string getID() { return m_id; };
    int getSalary() { return m_salary; };
    int getSenior() { return m_seniority; };
    // funcs
};

void save(vector<Employee> &EmployeeVec);
vector<Employee> load(vector<Employee> newVec);