// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052

#ifndef __MAZE2DSEARCHABLE__
#define __MAZE2DSEARCHABLE__
#include "Searchable.hpp"
#include "../Maze2d.hpp"

class Maze2dSearchable : public Searchable<int *>
{
private:
	Maze2d *m_maze;

public:
	Maze2dSearchable(Maze2d &maze) : m_maze(&maze){};
	Maze2dSearchable(Maze2d *Maze) : m_maze(Maze){};

	virtual State<int *> *getStartState()
	{
		int *s = m_maze->getStartPosition();
		State<int *> *s1 = new State<int *>(s);
		return s1;
	}

	virtual State<int *> *getGoalState()
	{
		int *s = m_maze->getGoalPosition();
		State<int *> *s1 = new State<int *>(s);
		return s1;
	}

	virtual std::vector<State<int *> *> *getAllPossibleStates(State<int *> &s)
	{
		std::vector<int *> moves = *m_maze->getPossibleMoves(s.getState());
		std::vector<State<int *> *> *smoves = new std::vector<State<int *> *>();
		for (auto it = moves.begin(); it != moves.end(); ++it)
		{
			smoves->push_back(new State<int *>(*it));
		}
		return smoves;
	};
	virtual int getWidth() { return m_maze->getRow(); };
	virtual int getHeight() { return m_maze->getColumn(); };
};

#endif
