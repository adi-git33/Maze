// #ifndef __CLI__
// #define __CLI_
#pragma once

#include "CommandHashMap.hpp"

using namespace std;
// void printMenu()
void printMenu()
{
    cout << "\t\t--Menu--" << endl;
    cout << "1. Display Files" << endl;
    cout << "2. Generate maze" << endl;
    cout << "3. Display maze" << endl;
    cout << "4. Save Maze" << endl;
    cout << "5. Load Maze" << endl;
    cout << "6. Maze Size" << endl;
    cout << "7. File Size" << endl;
    cout << "8. Solve Maze" << endl;
    cout << "9. Dislay Solution" << endl;
    cout << "10. Exit" << endl;
};

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
    CLI(CommandHM *commands)
        : m_input(std::cin), m_output(std::cout), m_commandSet(commands){};

    // Destractor
    ~CLI(){};
    // Operators
    // Getters
    // Setters
    // Functions
    void Start()
    {
        string cmd;
        do
        {
            printMenu();
            cout << "Enter Commend: " << endl
                 << ">";
            cin >> cmd;
            vector<string> param;
            // Generate Maze <MazeName> <11> <15>
            // cmd string + param string
            if (m_commandSet->findCommend(cmd))
            {
                m_commandSet->executeCommand(cmd, param);
            }
            else
            {
                cout << "Command not found." << endl;
            }
        } while (cmd != "exit");

        // Maze2d saveMaze = mazesArr.find(param[0])->second;
        // string cmd;
        // do
        // {
        //     printMenu();
        //     cout << ">";
        //     cin >> cmd;
        // } while (cmd != "exit");
    };
};

// #endif
