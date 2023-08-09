// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052
// #pragma once
#ifndef __MAZECOMPRESSION__
#define __MAZECOMPRESSION__
#include "Maze2d.hpp"
#include "Memory.hpp"

class MazeCompression
{
private:
public:
    void save(vector<vector<int>> &mazeVector) // compress maze and save to memory
    {
        ofstream mazeTxt("maze.txt", std::ios::trunc);
        if (mazeTxt.is_open() == true)
        {
            for (int i = 0; i < mazeVector.size(); i++)
            {
                for (int j = 0; j < mazeVector.at(i).size(); j++)
                    mazeTxt << mazeVector[i][j];
                mazeTxt << endl;
            }
        }
        else
        {
            FileNotRead err;
            throw(err);
        }
    };

    vector<vector<int>> load()
    {
        ifstream mazeTxt("maze.txt"); // Open the text file
        if (mazeTxt.is_open())
        {
            vector<vector<int>> loadedMazes;
            vector<int> tempMaze;
            string buffer;

            // const auto begin = mazeTxt.tellg();
            // mazeTxt.seekg(0, ios::end);
            // const auto end = mazeTxt.tellg();
            // const auto fsize = (end - begin);
            // cout << "file size: " << fsize << endl;
            // mazeTxt.seekg(0, ios::beg);

            while (getline(mazeTxt, buffer))
            {
                for (int i = 0; i < buffer.size(); i++)
                {
                    string numAsString(1, buffer[i]); // Convert character to string
                    int temp = stoi(numAsString);
                    tempMaze.push_back(temp);
                }
                loadedMazes.push_back(tempMaze);
                tempMaze.clear();
            }

            mazeTxt.close();
            return loadedMazes;
        }
        else
        {
            throw FileNotRead();
        }
    };
};
#endif

// vector<int *> mazeData = {&m_mazeID, &m_rows, &m_cols, m_start, m_goal, m_arrMaze};

//     m_mazeID = mazeInVector.at(0);
//     m_rows = mazeInVector.at(1);
//     m_cols = mazeInVector.at(2);
//     m_start[0] = mazeInVector.at(3);
//     m_start[1] = mazeInVector.at(4);
//     m_goal[0] = mazeInVector.at(5);
//     m_goal[1] = mazeInVector.at(6);

//     vector<vector<int>> newMaze;
//     vector<int> row;
//     // creates random maze
//     for (int i = 0; i < m_rows; i++)
//     {
//         for (int j = 0; j < m_cols; j++)
//         {
//             row.push_back(mazeInVector.at(i + 7));
//         }
//         newMaze.push_back(row);
//         row.resize(0);
//     }
// };

//     vector<vector<int>> load() // load comppressed maze
//     {
//         vector<vector<int>> loadedMazes;
//         ifstream bin;
//         bin.open("maze.bin", ios::binary);
//         if (bin.is_open() == true)
//         {
//             vector<int> fileData;
//             int value;

//             while (bin.read(reinterpret_cast<char *>(&value), sizeof(int)))
//             {
//                 fileData.push_back(value);
//             }
//             vector<int> tempMaze;
//             cout << "file size:" << fileData.size() << endl;
//             for (int i = 0; i < fileData.size(); i++)
//             {
//                 int rows = fileData.at(i + 1);
//                 int cols = fileData.at(i + 2);
//                 int arrSize = (rows * cols) + 7;

//                 cout << "line 82 rows: " << rows << " cols: " << cols << " arrsize: " << arrSize << " i: " << i << endl;
//                 cout << "file size - arr size: " << (fileData.size() - arrSize) << endl;
//                 for (int j = i; j < arrSize; j++)
//                 {
//                     cout << "here???? line 85 " << j << " " << i << " " << arrSize << endl;
//                     tempMaze.push_back(fileData.at(j));
//                 }
//                 i += (arrSize - 1);
//             }
//             bin.close();
//         }
//         else
//         {
//             FileNotRead err;
//             throw(err);
//         }
//         return loadedMazes;
//     };
// };

// vector<vector<int>> load()
// {
//     vector<vector<int>> loadedMazes;
//     ifstream bin("maze.bin", ios::binary);
//     if (bin.is_open() == true)
//     {

//         // Check if we have enough data to form a maze
//         if (mazeData.size() < 7)
//         {
//             // Handle error - Not enough data for a maze
//             return loadedMazes;
//         }

//         int currentIndex = 0;

//         // Iterate through the mazeData
//         while (currentIndex < mazeData.size())
//         {
//             int width = mazeData[currentIndex + 1];
//             int height = mazeData[currentIndex + 2];

//             vector<int> mazeArr;

//             for (int i = 0; i < height; i++)
//             {
//                 for (int j = 0; j < width; j++)
//                 {
//                     mazeArr.push_back(mazeData[currentIndex + 7 + i * width + j]);
//                 }
//             }

//             loadedMazes.push_back(mazeArr);
//             currentIndex += (width * height + 7);
//         }

//         bin.close();
//     }
//     else
//     {
//         FileNotRead err;
//         throw(err);
//     }
//     return loadedMazes;
// }

// int width, height;
// bin.read(reinterpret_cast<char *>(&width), sizeof(int));
// bin.read(reinterpret_cast<char *>(&height), sizeof(int));

// vector<int> mazeRow(width);
// for (int i = 0; i < height; ++i)
// {
//     bin.read(reinterpret_cast<char *>(mazeRow.data()), width * sizeof(int));
//     loadedMazes.push_back(mazeRow);
// }
// int startPoint[2];
// startPoint[0] = 0;
// startPoint[1] = 0;
// int goalPoint[2];
// goalPoint[0] = 1;
// goalPoint[1] = 1;
// vector<vector<int>> mazeArr;
// // Maze2d *tmpMaze = new Maze2d(startPoint, goalPoint, 1, 1, mazeArr);
// while (bin.read((char *)(tmpMaze), sizeof(Maze2d)))
// {
//     loadedMazes.push_back(*tmpMaze);
// }
