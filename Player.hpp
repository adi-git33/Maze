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
    string m_username;

public:
    // Constractor
    Player(string username) : m_username(username){};
    // Destractor
    ~Player(){};
    // Operators
    // Getters
    // Setters
    // Functions
    void Move(Direction movement, Maze2d *maze)
    {
        int *pos = maze->getCurrentPosition();

        switch (movement)
        {
        case 0:
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
        case 1: // right
        {
            if ((pos[1] + 1 < maze->getColumn()))
            {
                if (maze->getPositionInfo(pos[0], (pos[1] + 1)) == 0)
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
        case 2: // down
        {
            if ((pos[0] + 1) < maze->getRow())
            {
                if (maze->getPositionInfo((pos[0] + 1), pos[1]) == 0)
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
        case 3: // left
        {
            if (((pos[1] - 1) > 0))
            {
                if (maze->getPositionInfo((pos[0] - 1), pos[1]) == 0)
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
        }
    };
};

#endif