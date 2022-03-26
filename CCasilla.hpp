#pragma once

#include <iostream>
#include "Ctesconf.hpp"

class CCasilla
{
protected:
    int numero=1;
    int premio_castigo=NOR_PREMIO_CASTIGO;
    std::string tipo="N";
public:

    CCasilla();
    CCasilla(int, std::string);

    int getNumeroCasilla();
    std::string getTipo();
    
    int getSiguienteCasilla();
    void print();
};