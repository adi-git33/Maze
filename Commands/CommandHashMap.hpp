#ifndef __COMMANDHASHMAP__
#define _COMMANDHASHMAP__

#include "Commands.hpp"
#include <iostream>
#include <cstring>
#include <map>
#include <memory>

using namespace std;

class CommandHM
{
private:
    map<string, unique_ptr<Command>> m_ComMap;

public:
    // Constractors
    CommandHM(){};
    // Destractors
    virtual ~CommandHM(){};
    // Operators
    // Getters
    // Setters
    // Functions
    void insertCommand(string &theCom, unique_ptr<Command> newCommand)
    {
        if (m_ComMap.find(theCom) == m_ComMap.end())
        {
            m_ComMap.insert(std::make_pair(theCom, move(newCommand)));
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
    void executeCommand(string &cmd, vector<string> &param, Maze2dModel *myModel)
    {
        auto commandIter = m_ComMap.find(cmd);
        auto &command = commandIter->second;
        command->doCommand(param, myModel);
    }
};

#endif