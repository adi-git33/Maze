#pragma once

#include <string>
#include <memory>
using namespace std;

template <class T>
class State
{
private:
	T m_state;
	double m_cost;
	unique_ptr<State> m_cameFrom;

public:
	State(T &state) : m_state(state), m_cost(0), m_cameFrom(nullptr) {}
	~State(){};
	bool operator==(State &s) { return m_state.compare(s.m_state) == 0; }
	T &getState() { return m_state; }
};

template <class T>
class Solution
{
private:
	std::vector<unique_ptr<State<T>>> m_solution;

public:
	Solution(){};
	~Solution(){};
};
