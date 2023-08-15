// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052

#ifndef __PLAYER__
#define __PLAYER__

#include <string>
#include "Maze2d.hpp"
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
    string Move(Maze2d *maze, string dir)
    {
        string result;
        int pos[2];
        int *curPos = maze->getCurrentPosition();
        pos[0] = curPos[0];
        pos[1] = curPos[1];
        if (dir == "Up" || dir == "up")
        {
            if (((pos[0] - 1) >= 0))
            {
                if (maze->getPositionInfo((pos[0] - 1), pos[1]) == 0)
                {
                    pos[0] -= 1;
                    maze->setPosition(pos);
                    result = "Move Successfully.";
                }
                else if (maze->getPositionInfo((pos[0] - 1), pos[1]) == 3)
                {
                    pos[0] -= 1;
                    maze->setPosition(pos);
                    result = "Congrats, you won!";
                }
                else
                {
                    result = "Cannot move up.";
                }
            }
            else
            {
                result = "Out of borders.";
            }
        }
        else if (dir == "Down" || dir == "down")
        {
            if ((pos[0] + 1) < maze->getRow())
            {
                if (maze->getPositionInfo((pos[0] + 1), pos[1]) == 0)
                {
                    pos[0] += 1;
                    maze->setPosition(pos);
                    result = "Move Successfully.";
                }
                else if (maze->getPositionInfo((pos[0] + 1), pos[1]) == 3)
                {
                    pos[0] += 1;
                    maze->setPosition(pos);
                    result = "Congrats, you won!";
                }
                else
                {
                    result = "Cannot move down.";
                }
            }
            else
            {
                result = "Out of borders.";
            }
        }
        else if (dir == "Right" || dir == "right")
        {
            if ((pos[1] + 1) < maze->getColumn())
            {
                if (maze->getPositionInfo(pos[0], (pos[1] + 1)) == 0)
                {
                    pos[1] += 1;
                    maze->setPosition(pos);
                    result = "Move Successfully.";
                }
                else if (maze->getPositionInfo(pos[0], (pos[1] + 1)) == 3)
                {
                    pos[1] += 1;
                    maze->setPosition(pos);
                    result = "Congrats, you won!";
                }
                else
                {
                    result = "Cannot move right.";
                }
            }
            else
            {
                result = "Out of borders.";
            }
        }
        else if (dir == "Left" || dir == "left")
        {
            if (((pos[1] - 1) >= 0))
            {
                if (maze->getPositionInfo((pos[0]), (pos[1] - 1)) == 0)
                {
                    pos[1] -= 1;
                    maze->setPosition(pos);
                    result = "Move Successfully.";
                }
                else if (maze->getPositionInfo((pos[0]), (pos[1] - 1)) == 3)
                {
                    pos[1] -= 1;
                    maze->setPosition(pos);
                    result = "Congrats, you won!";
                }
                else
                {
                    result = "Cannot move left.";
                }
            }
            else
            {
                result = "Out of borders.";
            }
        }
        else
        {
            result = "Invalid Option.";
        }
        // }
        return result;
    };
};

#endif
