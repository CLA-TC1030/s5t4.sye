#include <iostream>
#include "GameManual.hpp"
#include "EndGameException.hpp"
#include "InvalidConfigurationException.hpp"
#include "ValidaCfg.hpp"

int main()
{
    int mc;
    int mj;
    int mt;

    try {
        std::cout << "Número de casillas: ";
        std::cin >> mc;

        std::cout << "Número de jugadores: ";
        std::cin >> mj;

        std::cout << "Número de turnos: ";
        std::cin >> mt;

        try {
            validaCfg(mc, mj, mt);
        }
        catch (InvalidConfigurationException &e)
        {
            std::cout << e.what() << "\n";
            throw EndGameException("Finalización anormal del juego...");
        }
    }
    catch(EndGameException &e)
    {
        std::cout << e.what() << "\n";
        return 1;
    }

    try {
        GameManual g("t1.tab", false, true);

        g.start();
    }
    catch(EndGameException &e)
    {
        std::cout << e.what() << "\n";
        return 1;
    }

    return 0;
}