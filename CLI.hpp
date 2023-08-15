// #ifndef __CLI__
// #define __CLI_
#pragma once

#include "View.hpp"

using namespace std;

void printMenu()
{
    cout << "\t\t--Menu--" << endl;
    cout << "1. Display Files <File Path>" << endl;
    cout << "2. Generate Maze <Maze Name> <Height> <Width> <Generate Type>(Options: Simple[might not be solveable], DFS)" << endl;
    cout << "3. Display Maze <Maze Name>" << endl;
    cout << "4. Save Maze <Maze Name> <File Name>" << endl;
    cout << "5. Load Maze <File Name> <Maze Name>" << endl;
    cout << "6. Maze Size <Maze Name>" << endl;
    cout << "7. File Size <File Name>" << endl;
    cout << "8. Solve Maze <Maze Name> <Option>(Options: Manualy, Algorithm)" << endl;
    cout << "9. Display Solution <Maze Name>" << endl;
    cout << "10. Exit" << endl;
};

class CLI : public View
{
private:
    istream &m_input;
    ostream &m_output;

public:
    // Constractor
    CLI(std::istream &input = std::cin, std::ostream &output = std::cout)
        : m_input(input), m_output(output){};
    // Destractor
    ~CLI(){};
    // Operators
    // Getters
    // Setters

    // Functions
    virtual void PrintResult(string result)
    {
        cout << result << endl;
    };
    virtual void Notify(string cmd, vector<string> s)
    {
        for (const auto &observerPair : m_observers)
        {
            observerPair.second->viewUpdate(cmd, s);
        }
    };
    virtual void NotifyStatus(string status)
    {
        for (const auto &observerPair : m_observers)
        {
            observerPair.second->returnStatus(status);
        }
    };

    virtual void Start()
    {
        string cmdInput;
        do
        {
            printMenu();
            cout << "Enter Commend: " << endl
                 << ">";
            if (std::cin.peek() == '\n')
            {
                std::cin.ignore();
            }
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
                else if (positionsLeft.size() < 1 || positionsLeft.size() > 4)
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
                    if (cmd == "Solve Maze")
                    {
                        if (param[1] == "Manualy")
                        {
                            m_state.find("Controller")->second = false;
                            NotifyStatus(param[0]);
                            if (m_state.find("Controller")->second == true)
                            {
                                int exit = 0;
                                while (!(exit))
                                {
                                    vector<string> mazeName;
                                    mazeName.push_back(param[0]);

                                    Notify("Display Maze", mazeName);
                                    cout
                                        << "Enter Direction: " << endl
                                        << "1. Up" << endl
                                        << "2. Down" << endl
                                        << "3. Right " << endl
                                        << "4. Left" << endl
                                        << "5. Exit" << endl
                                        << ">";

                                    m_state.find("Controller")->second = false;
                                    string direct;
                                    cin >> direct;
                                    if (direct == "Exit")
                                    {
                                        exit = 1;
                                    }
                                    else
                                    {
                                        cmd = "Solve Maze Manualy";
                                        param[1] = direct;
                                        Notify(cmd, param);
                                        if (m_state.find("Controller")->second == true)
                                        {
                                            exit = 1;
                                            m_state.find("Controller")->second = false;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                cout << "Maze doesn't exists." << endl;
                            }
                        }
                        else if (param[1] == "Algorithm")
                        {
                            cout << "Choose algorithm: " << endl
                                 << "1. BFS" << endl
                                 << "2. AStar" << endl
                                 << ">";
                            string alg;
                            cin >> alg;
                            param[1] = alg;
                            cmd = "Solve Maze Algorithm";
                            Notify(cmd, param);
                        }
                        else
                        {
                            cout << "Not a valid option." << endl;
                        }
                    }
                    else
                    {
                        Notify(cmd, param);
                    }
                }
            }
        } while (cmdInput != "Exit");
    };
};

// #endif
