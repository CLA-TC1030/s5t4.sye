#pragma once

#include <ctime>
#include <cstdlib>

class CDado{
    private:
        bool switchrandom=true;

    public:
        static int cara;

        CDado();
        CDado(bool);

        void resetDado();
        int getValorDado();

        int operator+(int);
};