// #pragma once
#ifndef __SEARCHABLE__
#define __SEARCHABLE__

#include <vector>
#include "Solution.hpp"

template <class T>
class Searchable
{
public:
	virtual State<T> *getStartState() = 0;
	virtual State<T> *getGoalState() = 0;
	virtual std::vector<State<T> *> *getAllPossibleStates(State<T> &s) = 0;
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
};

#endif