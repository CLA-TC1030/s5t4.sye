#pragma once

#include "Ctesconf.hpp"
#include "CCasilla.hpp"

class Tablero {
private:
    CCasilla c[MAX_CASILLAS];
public:
    Tablero();
    Tablero(std::string);

    void setCasilla(CCasilla, int);
    CCasilla getCasilla(int);

    void print();
};