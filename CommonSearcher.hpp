#ifndef __COMMONSEARCHER__
#define __COMMONSEARCHER__

#include "Searcher.hpp"
#include <chrono>

template <class T>
class CommonSearcher : public Searcher<T>
{

protected:
	int m_evaluatedNodes;

public:
	CommonSearcher() {};

	virtual Solution<T> search(const Searchable<T> &s) = 0;
	virtual void checkEfficiency(const Searchable<T> &s)
	{
		chrono::time_point<chrono::system_clock> startTime = chrono::system_clock::now();
		search(s);
		chrono::time_point<chrono::system_clock> EndTime = chrono::system_clock::now();
		chrono::duration<double> timeDiff = EndTime - startTime;
		double timeMeasure = timeDiff.count();
		cout << "It took the algorithm " << to_string(timeMeasure) << " seconds" << endl;
	}

};

#endif