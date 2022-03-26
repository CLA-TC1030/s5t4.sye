#pragma once

#include "Ctesconf.hpp"
#include "Tablero.hpp"
#include "Jugador.hpp"
#include "CDado.hpp"
#include "Turno.hpp"
#include <fstream>
#include <ostream>

class Game {
protected:
    Tablero t;
    Jugador j[MAX_JUGADORES];
    CDado d;
    bool swio;
    Turno* Pturno;

// Archivos de entrada/salida para el caso de configuracion de IO por archivos ---------
    std::ifstream fi{"input"};
    std::ofstream fo{"output"};

    virtual std::string getInput()=0;    
public:
    static int turno;
    Game();
    Game(std::string, bool, bool);
    void start();
    void outMsg(std::string);
};