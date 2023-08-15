// #pragma once
#ifndef __SOLUTION__
#define __SOLUTION__

#include "State.hpp"
#include <memory>
#include <vector>

using namespace std;

template <class T>
class Solution
{
private:
    vector<State<T>> m_solution;

public:
    Solution(){};
    Solution(vector<State<T>> &newSol)
    {
        m_solution = newSol;
    }
    ~Solution(){};

    const vector<State<T>> &getSolution() const
    {
        return m_solution;
    };

    void insertState(State<T> s)
    {
        m_solution.push_back(s);
    };
};

#endif