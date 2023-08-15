#ifndef __ASTAR__
#define __ASTAR__

#include "CommonSearcher.hpp"

template <class T>
class AStar : public CommonSearcher<T>
{
public:
	virtual Solution<T> search(Searchable<T> &s)
	{
		cout << "A* Solution" << endl;

		return Solution<T>();
	};
};

#endif