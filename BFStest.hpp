#ifndef __BFS__
#define __BFS__

#include "CommonSearcher.hpp"
#include "Direction.hpp"
#include <unordered_set>

template <class T>
class BFS : public CommonSearcher<T>
{
public:
	virtual Solution<T> search(const Searchable<T> &s)
	{
        queue<state<T>> m_openList;
		unordered_set<state<T>> m_closedSet;

		m_openList.push(s.getStartState());
		m_closedSet.insert(s.getStartState());

		while (!m_openList.empty()){
			State<T> currentState = m_openList.front();
			m_openList.pop();

			if(currentState == s.getGoalState()){
				return this->backtrace(currentState);
			}

			vector<State<T>> successors = s.getAllPossibleStates(currentState);
			for (State<T> &successor : successors){
				if(m_closedSet.find(successor) == m_closedSet.end()){
					m_openList.push(successor);
					m_closedSet.insert(successor);
					this->updatePriorityQueue(successor);
                    successor.setValue(5);
				}
			}
		}
		cout << "BFS Solution." << endl;
		return Solution<T>();
	};
};

#endif