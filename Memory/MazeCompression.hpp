// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052

#ifndef __MAZECOMPRESSION__
#define __MAZECOMPRESSION__

#include "../Maze2d.hpp"
#include "Memory.hpp"

class MazeCompression
{
private:
public:
    void save(vector<int> &mazeVector, string mazeName)
    {
        ofstream mazeData("" + mazeName + ".txt");
        if (mazeData.is_open())
        {
            for (const int &value : mazeVector)
            {
                mazeData << value << " ";
            }
            mazeData.close();
        }
        else
        {
            cerr << "Error opening file for writing." << std::endl;
        }
    }

    vector<int> load(string mazeName)
    {
        vector<int> loadedVector;
        ifstream mazeData("" + mazeName + ".txt");
        int value;
        while (mazeData >> value)
        {
            loadedVector.push_back(value);
        }
        mazeData.close();
        return loadedVector;
    }
};
#endif
