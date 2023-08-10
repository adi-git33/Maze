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
    std::map<std::string, Command> m_ComMap;

public:
    // Constractors

CommandHM(string theCom, Command newCommand)
{
    m_ComMap.insert(std::make_pair(theCom, newCommand));
}
    // Destractors
    virtual ~CommandHM();
    // Operators
    // Getters
    // Setters
    // Functions
    void execute(string cmd)
    {
        // if(m_ComMap.find(cmd)){
        //     command.doCommand();
        // }else{
        //     error;
        // }
    }
};

#endif