// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052

#ifndef __MODELSUBJECT__
#define __MODELSUBJECT__

#include "Observer.hpp"

using namespace std;
class ModelSubject
{
protected:
    list<Observer *> m_observers;

public:
    // Constractor
    ModelSubject(){};
    // Destractor
    ~ModelSubject();
    // Operators
    // Getters
    // Setters
    // Functions
    virtual void modelUpdate(string result) = 0;
    void AttachObserver(Observer *newObserver)
    {
        m_observers.push_back(newObserver);
    };
    void DetachObserver(Observer *newObserver)
    {
        m_observers.remove(newObserver);
    };
};

#endif