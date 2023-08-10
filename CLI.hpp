// #ifndef __CLI__
// #define __CLI_
#pragma once

#include "CommandHashMap.hpp"

using namespace std;

class CLI
{
private:
    istream &m_input;
    ostream &m_output;
    CommandHM *m_commandSet;

public:
    // Constractor
    CLI(std::istream &input = std::cin, std::ostream &output = std::cout, CommandHM *commands = NULL)
        : m_input(input), m_output(output), m_commandSet(commands){};
    // Destractor
    ~CLI(){};
    // Operators
    // Getters
    // Setters
    // Functions
    void Start()
    {
        // string cmd;
        // do
        // {
        //     printMenu();
        //     cout << ">";
        //     cin >> cmd;
        // } while (cmd != "exit");
    };
};
void printMenu();

// #endif
