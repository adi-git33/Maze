// #pragma once
#ifndef __PLAYER__
#define __PLAYER__
#include <string>
// #include <memory>
#include "Direction.hpp"
#include "Maze2d.hpp"
#include <iostream>
using namespace std;

class Player
{
private:
    int m_uid;

public:
    // Constractor
    Player()
    {
        m_uid = 1;
    };
    // Destractor
    ~Player(){};
    // Operators
    // Getters
    // Setters
    // Functions
    void Move(Maze2d *maze)
    {
        int exit = 0;
        while (exit == 0)
        {
            int pos[2];
            int *curPos = maze->getCurrentPosition();
            pos[0] = curPos[0];
            pos[1] = curPos[1];
            if (maze->getPositionInfo(pos[0], pos[1]) == 3)
            {
                cout << "Congrats, you won!" << endl;
                exit = 1;
            }
            else
            {
                cout << *maze << endl
                     << "Enter Direction By Number: " << endl
                     << "1. Up" << endl
                     << "2. Right " << endl
                     << "3. Down " << endl
                     << "4. Left" << endl
                     << "5. Exit" << endl
                     << ">";

                int dir;
                cin >> dir;

                switch (dir)
                {
                case 1:
                {
                    if (((pos[0] - 1) > 0))
                    {
                        if (maze->getPositionInfo((pos[0] - 1), pos[1]) == 0)
                        {
                            pos[0] -= 1;
                            maze->setPosition(pos);
                            cout << "Move Successfully." << endl;
                        }
                        else
                        {
                            cout << "Cannot move up." << endl;
                        }
                    }
                    else
                    {
                        cout << "Out of borders." << endl;
                    }
                    break;
                }
                case 2: // right
                {
                    if ((pos[1] + 1 < maze->getColumn()))
                    {
                        if (maze->getPositionInfo(pos[0], (pos[1] + 1)) == 0 || maze->getPositionInfo(pos[0], (pos[1] + 1)) == 3)
                        {
                            pos[1] += 1;
                            maze->setPosition(pos);
                            cout << "Move Successfully." << endl;
                        }
                        else
                        {
                            cout << "Cannot move right." << endl;
                        }
                    }
                    else
                    {
                        cout << "Out of borders." << endl;
                    }
                    break;
                }
                case 3: // down
                {
                    if ((pos[0] + 1) < maze->getRow())
                    {
                        if (maze->getPositionInfo((pos[0] + 1), pos[1]) == 0 || maze->getPositionInfo((pos[0] + 1), pos[1]) == 3)
                        {
                            pos[0] += 1;
                            maze->setPosition(pos);
                            cout << "Move Successfully." << endl;
                        }
                        else
                        {
                            cout << "Cannot move down." << endl;
                        }
                    }
                    else
                    {
                        cout << "Out of borders." << endl;
                    }
                    break;
                }
                case 4: // left
                {
                    if (((pos[1] - 1) > 0))
                    {
                        if (maze->getPositionInfo((pos[0] - 1), pos[1]) == 0 || maze->getPositionInfo((pos[0] - 1), pos[1]) == 3)
                        {
                            pos[1] -= 1;
                            maze->setPosition(pos);
                            cout << "Move Successfully." << endl;
                        }
                        else
                        {
                            cout << "Cannot move left." << endl;
                        }
                    }
                    else
                    {
                        cout << "Out of borders." << endl;
                    }
                    break;
                }
                case 5:
                {
                    exit = 1;
                    break;
                }
                default:
                    cout << "Invalid Option." << endl;
                }
            }
        }
    };
};

#endif