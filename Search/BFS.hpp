#ifndef __BFS__
#define __BFS__

#include "CommonSearcher.hpp"
#include "Solution.hpp"


template <class T>
class BFS : public CommonSearcher<T>
{
public:
	virtual Solution<T> search(Searchable<T> &s) 
	{
		cout << "BFS Solution." << endl;
		return Solution<T>();
	};
};


#endif
