// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052

#ifndef __OBSERVER__
#define __OBSERVER__

using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <list>

class Observer
{
private:
public:
    Observer(){};
    ~Observer(){};
    virtual void modelUpdate(string result) = 0;
    virtual void viewUpdate(string cmd, vector<string> perams) = 0;
    virtual void returnStatus(string status) = 0;
};

#endif