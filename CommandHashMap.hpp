#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <utility>
#include <exception>
#include <vector>
#include <iterator>
#include <fstream>
#include <cstring>
#include "Commands.hpp"

using namespace std;

class CommandHM
{
private:
    map<string, Command> m_ComMap;
public:
    // Constractors
    CommandHM(string theCom, Command newCommand){
        m_ComMap.insert(pair<string, Command>(make_pair(theCom, newCommand)));
    }
    // Destractors
    virtual ~CommandHM();
    // Operators
    // Getters
    // Setters
    // Functions
};