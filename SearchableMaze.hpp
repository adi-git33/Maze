#pragma once
#include "Searchable.hpp"
#include "Maze2d.hpp"

class Maze2dSearchable : public Searchable<string>
{
private:
	Maze2d *m_maze;

public:
	Maze2dSearchable(Maze2d &maze) : m_maze(&maze) {}

	// ADD implementation for those methodes
	virtual State<string> *getStartState()
	{
		string s = m_maze->getStartPosition();
		State<string> *s1 = new State<string>(s);
		return s1;
	}

	virtual State<string> *getGoalState()
	{
		string s = m_maze->getGoalPosition();
		State<string> *s1 = new State<string>(s);
		return s1;
	}

	virtual std::vector<State<string> *> *getAllPossibleStates(State<string> &s)
	{
		std::vector<string> moves = m_maze->getPossibleMoves(s.getState());
		std::vector<State<string> *> *smoves = new std::vector<State<string> *>();
		for (auto it = moves.begin(); it != moves.end(); ++it)
		{
			smoves->push_back(new State<string>(*it));
		}

		return smoves;
	};
};
