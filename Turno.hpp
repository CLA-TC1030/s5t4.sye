#pragma once

#include <ostream>
#include <string.h>
#include <iostream>

class Turno {
private:
    std::string turno{""};
    std::string jug_actual{""};
    std::string ca_old_jugador{""};
    std::string va_Dado_Final{""};
    std::string tipo_casilla{""};
    std::string ca_new_jugador{""};

public:
    Turno();
    Turno(std::string, std::string, std::string, std::string, std::string, std::string);

    friend std::ostream& operator<<(std::ostream& out, const Turno& t);  
};