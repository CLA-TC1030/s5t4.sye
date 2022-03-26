#pragma once

class Jugador {
private:
    int numero;
    int casilla_actual;
public:
    Jugador();
    Jugador(int);
    int getCasilla_actual();
    void setCasilla_actual(int);

    void print();
};