#ifndef __COMMONSEARCHER__
#define __COMMONSEARCHER__

#include "Searcher.hpp"
#include <chrono>
#include <queue>

template <class T>
class CommonSearcher : public Searcher<T>
{

protected:
	int m_evaluatedNodes;
	queue<State<T>> m_openList;

public:
	// Constractor
	// CommonSearcher(){};
	CommonSearcher() : m_evaluatedNodes(0) {}
	// Destractor
	~CommonSearcher(){};
	// Getters
	virtual int getNumberOfNodesEvaluated() { return m_evaluatedNodes; };
	// Functions
	virtual Solution<T> search(Searchable<T> &s) = 0;
	virtual void checkEfficiency(Searchable<T> &s)
	{
		chrono::time_point<chrono::system_clock> startTime = chrono::system_clock::now();
		search(s);
		chrono::time_point<chrono::system_clock> EndTime = chrono::system_clock::now();
		chrono::duration<double> timeDiff = EndTime - startTime;
		double timeMeasure = timeDiff.count();
		cout << "It took the algorithm " << to_string(timeMeasure) << " seconds" << endl;
	}
	const State<T> &popOpenList()
	{
		m_evaluatedNodes++;
		return m_openList.top();
	}
};

#endif