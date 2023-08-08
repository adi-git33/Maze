#ifndef __COMMANDHASHMAP__
#define _COMMANDHASHMAP__

#include <iostream>
#include <cstring>
#include <map>
#include "Commands.hpp"


using namespace std;

class CommandHM
{
private:
    map<string, Command> m_ComMap;
public:
    // Constractors
    CommandHM(string theCom, Command newCommand){
        m_ComMap.insert(pair<string, Command>(make_pair(theCom, newCommand)));
    }
    // Destractors
    virtual ~CommandHM();
    // Operators
    // Getters
    // Setters
    // Functions
};

#endif