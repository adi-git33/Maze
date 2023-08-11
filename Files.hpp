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
    void printFilesInPath(string path)
    {
        if (fs::exists(path))
        {
            for (const auto &entry : fs::directory_iterator(path))
            {
                if (fs::is_regular_file(entry))
                {
                    cout << entry.path().filename() << endl;
                }
            }
        }
        else
        {
            cout << "Path doesn't exist." << endl;
        }
    };
};