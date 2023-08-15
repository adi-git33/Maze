// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052

#ifndef __FILES__
#define __FILES__

#include "MazeCompression.hpp"
#include <filesystem>

namespace fs = filesystem;

class Files
{
private:
public:
    int getFileSize(string fileName)
    {
        string filename = fileName + ".txt";

        if (fs::exists(filename))
        {
            return fs::file_size(filename);
        }
        else
        {
            return -1;
        }
    };
    string printFilesInPath(string path)
    {
        string result = "";
        if (fs::exists(path))
        {
            for (const auto &entry : fs::directory_iterator(path))
            {
                if (fs::is_regular_file(entry))
                {
                    result += entry.path().filename().string() + "\n";
                }
            }
        }
        else
        {
            result = "Path doesn't exist.";
        }
        return result;
    };
};

#endif