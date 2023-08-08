#pragma once
#include <string>
#include <memory>
#include "Direction.hpp"
#include "Maze2d.hpp"
using namespace std;

class Player{
    private:
        string m_username;
    public:
    // Constractor
    Player(string username) : m_username(username) {};
    // Destractor
    ~Player();
    // Operators
    // Getters
    // Setters
    // Functions
    void Move(Direction movement, Maze2d<int, int>  maze) {
        cout << "Player Moved." << endl;
    };
};