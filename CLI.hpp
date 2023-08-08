#ifndef __CLI__
#define __CLI_

#include "Commands.hpp"
#include "CommandHashMap.hpp"

using namespace std;

class CLI
{
private:
    // istream m_input;         // somehow default is istream
    // ostream m_output;       // somehow default is ostream
    // CommandHM m_commandSet;

public:
    // Constractor
    CLI(){};
    // CLI(istream in, ostream out, CommandHM commandList){
    //     // constract in and out
    //     m_commandSet = commandList;
    // };
    // Destractor
    ~CLI(){};
    // Operators
    // Getters
    // Setters
    // Functions
    void Start(){
        string inStr;
        // do{
        //     fgets(inStr);
        //     Command* newCom = m_commandSet.find(inStr);
        //     if (exist())
        //         newCom->DoCommand();
        //     else
        //         err();
        // }while (inStr != "exit")
    };
};

#endif