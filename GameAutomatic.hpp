#pragma once

#include "Game.hpp"

class GameAutomatic:public Game {
protected:
    std::string getInput();   
public:
    GameAutomatic(std::string, bool, bool);
};