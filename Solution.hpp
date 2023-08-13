// #pragma once
#ifndef __SOLUTION__
#define __SOLUTION__

#include "State.hpp"
#include "Solution.hpp"

#include <string>
#include <memory>

using namespace std;

template <class T>
class Solution
{
private:
	std::vector<State<T> *> m_solution;

public:
	Solution(){};
	~Solution(){};

    const State<T>& getSolution() const
    {
        return m_solution;
    }};

#endif