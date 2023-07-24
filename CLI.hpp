#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <utility>
#include <exception>
#include <vector>
#include <iterator>
#include <fstream>
#include <cstring>
#include "Commands.hpp"
#include "CommandHashMap.hpp"

using namespace std;

class CLI
{
private:
    istream m_input;         // somehow default is istream
    ostream m_output;       // somehow default is ostream
    CommandHM m_commandSet;

public:
    // Constractor
    CLI(istream in, ostream out, CommandHM commandList){
        // constract in and out
        m_commandSet = commandList;
    };
    // Destractor
    // Operators
    // Getters
    // Setters
    // Functions
    void Start(){
        string inStr;
        do{
            fgets(inStr);
            Command* newCom = m_commandSet.find(inStr);
            if (exist())
                newCom->DoCommand();
            else
                err();
        }while (inStr != "exit")
    };
};