// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052

#include "Maze2d.hpp"

void save(vector<Employee> &EmployeeVec)
{
    ofstream empsBin("emps.bin", ios::binary | std::ios::trunc);
    if (empsBin.is_open() == true)
    {
        for (int i = 0; i < EmployeeVec.size(); i++)
        {
            empsBin.write((char *)&EmployeeVec[i], sizeof(Employee));
        }
        empsBin.close();
    }
    else
    {
        FileNotRead err;
        throw(err);
    }
}

vector<Employee> load(vector<Employee> newVec)
{
    ifstream bin;
    bin.open("emps.bin", ios::binary);
    if (bin.is_open() == true)
    {
        Employee *tmpEmpy = new Employee();
        while (bin.read((char *)(tmpEmpy), sizeof(Employee)))
        {
            newVec.push_back(*tmpEmpy);
        }
        bin.close();
    }
    else
    {
        FileNotRead err;
        throw(err);
    }
    return newVec;
}