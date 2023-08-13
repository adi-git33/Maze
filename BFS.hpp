#ifndef __BFS__
#define __BFS__

#include "CommonSearcher.hpp"
#include "Direction.hpp"

template <class T>
class BFS : public CommonSearcher<T>
{
public:
	virtual Solution<T> search(const Searchable<T> &s)
	{
		cout << "BFS Solution." << endl;
		return Solution<T>();
	};
};

#endif