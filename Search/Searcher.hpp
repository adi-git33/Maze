// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052

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