// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052

#ifndef __VIEW__
#define __VIEW__

using namespace std;

#include "Observer.hpp"

class View
{
protected:
    map<string, Observer *> m_observers;
    map<string, bool> m_state;

public:
    // Constractor
    View(){};
    // Destractor
    ~View(){};
    // Operators
    // Getters
    // Setters
    virtual void setStatus(string ObserverName, bool newStat)
    {
        m_state.find(ObserverName)->second = newStat;
    };
    // Functions
    virtual void Start() = 0;
    virtual void PrintResult(string result) = 0;
    virtual void Notify(string cmd, vector<string> s) = 0;
    virtual void AttachObserver(string observerName, Observer *newObserver)
    {
        m_observers.insert(pair<string, Observer *>(observerName, newObserver));
        m_state.insert(pair<string, bool>(observerName, false));
    };
    virtual void DetachObserver(string observerName)
    {
        m_observers.extract(observerName);
        m_state.extract(observerName);
    };

    virtual void NotifyStatus(string status) = 0;
};

#endif