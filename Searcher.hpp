#pragma once

#include "StateAndSol.hpp"
#include "Searchable.hpp"

template <class T>
class Searcher
{
public:
	virtual Solution<T> search(const Searchable<T>& s) = 0;
	virtual int getNumberOfNodesEvaluated() = 0;
};

