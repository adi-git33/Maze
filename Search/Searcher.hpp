// #pragma once
#ifndef __SEARCHER__
#define __SEARCHER__

#include "Searchable.hpp"

template <class T>
class Searcher
{
public:
	virtual Solution<T> search(Searchable<T> &s) = 0;
	virtual int getNumberOfNodesEvaluated() = 0;
};

#endif