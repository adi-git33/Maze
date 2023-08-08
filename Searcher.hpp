// #pragma once
#ifndef __SEARCHER__
#define __SEARCHER__

#include "Searchable.hpp"

template <class T>
class Searcher
{
public:
	virtual Solution<T> search(const Searchable<T>& s) = 0;
};

#endif