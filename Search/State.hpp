// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052

#ifndef __STATE__
#define __STATE__

#include <string>
using namespace std;

template <class T>
class State
{
private:
	T m_state;
	double m_cost;
	State *m_cameFrom;

public:
	State(T &state) : m_state(state), m_cost(0), m_cameFrom(nullptr) {}
	~State(){};
	bool operator==(State &s) { return m_state.compare(s.m_state) == 0; }
	T &getState() { return m_state; }
	const T &getStateConst() const
	{
		return m_state;
	};
	void setValue(T newValue) { m_state = newValue; };
};

#endif