#pragma once
#include "Searcher.hpp"
#include <queue>

template <class T>
class CommonSearcher : public Searcher<T>
{

protected:
	int m_evaluatedNodes;
	std::priority_queue<State<T>> m_openList;

public:
	CommonSearcher() : m_evaluatedNodes(0) {}

	// Abstraction
	virtual Solution<T> search(const Searchable<T> &s) = 0;
	virtual int getNumberOfNodesEvaluated() { return m_evaluatedNodes; };
	virtual void checkEfficiency(const Searchable<T> &s)
	{
		// Open Timer

		search(s);

		// Close Timer

		// Print time
	}

	// Additional implementation
	const State<T> &popOpenList()
	{
		m_evaluatedNodes++;
		return m_openList.top();
	}
};
