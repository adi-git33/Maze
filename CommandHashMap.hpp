#ifndef __COMMANDHASHMAP__
#define _COMMANDHASHMAP__

#include "Commands.hpp"
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class CommandHM
{
private:
    std::map<std::string, Command *> m_ComMap;

public:
    // Constractors
    CommandHM(){};
    // Destractors
    virtual ~CommandHM(){};
    // Operators
    // Getters
    // Setters
    // Functions
    void insertCommand(string &theCom, Command *newCommand)
    {
        if (m_ComMap.find(theCom) == m_ComMap.end())
        {
            cout << theCom;
            m_ComMap.insert(std::make_pair(theCom, newCommand));
            cout << "Command insert successfuly." << endl;
        }
        else
        {
            cout << "Command already exists" << endl;
        }
    }
    bool findCommend(string &cmd)
    {
        if (m_ComMap.find(cmd) != m_ComMap.end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void executeCommand(string &cmd, vector<string> &param)
    {
        auto command = m_ComMap.find(cmd)->second;
        command->doCommand(param);
    }
};

#endif