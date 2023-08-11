// #ifndef __CLI__
// #define __CLI_
#pragma once

#include "CommandHashMap.hpp"

using namespace std;
// void printMenu()
void printMenu()
{
    cout << "\t\t--Menu--" << endl;
    cout << "1. Display Files <File Path>" << endl;
    cout << "2. Generate Maze <Maze Name> <Height> <Width>" << endl;
    cout << "3. Display Maze <Maze Name>" << endl;
    cout << "4. Save Maze <Maze Name> <File Name>" << endl;
    cout << "5. Load Maze <File Name> <Maze Name>" << endl;
    cout << "6. Maze Size <Maze Name>" << endl;
    cout << "7. File Size <File Name>" << endl;
    cout << "8. Solve Maze <Maze Name> <Algorithm Name>(Options: BFS, AStar)" << endl;
    cout << "9. Display Solution <Maze Name>" << endl;
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
        string cmdInput;
        do
        {
            printMenu();
            cout << "Enter Commend: " << endl
                 << ">";
            getline(cin, cmdInput);

            if (cmdInput == "Exit")
            {
                cout << "Goodbye!" << endl;
            }
            else
            {
                vector<int> positionsLeft;
                vector<int> positionsRight;

                for (int i = 0; i < cmdInput.size(); i++)
                {
                    if (cmdInput[i] == '<')
                    {
                        positionsLeft.push_back(i);
                    }
                    if (cmdInput[i] == '>')
                    {
                        positionsRight.push_back(i);
                    }
                }

                if (positionsLeft.size() != positionsRight.size())
                {
                    cout << "Invalid Parameters Format." << endl;
                }
                else if (positionsLeft.size() < 1 || positionsLeft.size() > 3)
                {
                    cout << "Invalid Number Of Parameters." << endl;
                }
                else
                {
                    string cmd = cmdInput.substr(0, (positionsLeft[0]) - 1);

                    int numOfParam = positionsLeft.size();
                    vector<string> param;
                    for (int i = 0; i < numOfParam; i++)
                    {
                        param.push_back(cmdInput.substr((positionsLeft[i] + 1), (positionsRight[i]) - (positionsLeft[i] + 1)));
                    }

                    if (m_commandSet->findCommend(cmd))
                    {
                        m_commandSet->executeCommand(cmd, param);
                    }
                    else
                    {
                        cout << "Command not found." << endl;
                    }
                }
            }

        } while (cmdInput != "Exit");
    };
};

// #endif
