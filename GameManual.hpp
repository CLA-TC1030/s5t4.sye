#pragma once

#include "Game.hpp"

class GameManual:public Game {
protected:
    std::string getInput();   
public:
    GameManual(std::string, bool, bool);
};