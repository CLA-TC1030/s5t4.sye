#include <string>

#define CATCH_CONFIG_MAIN // defines main() automatically
#include <catch2/catch.hpp>

#include "../Ctesconf.hpp"
#include "../CCasilla.hpp"
#include "../CasillaNormal.hpp"
#include "../CasillaEscalera.hpp"
#include "../CasillaSerpiente.hpp"
#include "../Tablero.hpp"
#include "../Jugador.hpp"
#include "../CDado.hpp"
#include "../GameManual.hpp"
#include "../GameAutomatic.hpp"
#include "../Game.hpp"
#include "chkFiles.hpp"
#include "../InvalidConfigurationException.hpp"
#include "../InvalidOptionException.hpp"
#include "../EndGameException.hpp"

// Pruebas para casillas -----------------------------------------------------------

TEST_CASE("ex0", "[InvalidConfigurationException]")
{   
    SECTION( "Probando InvalidConfigurationException" ) {
        try {
            throw InvalidConfigurationException("Invalid MAX_CASILLAS valor " + std::to_string(MAX_CASILLAS));
            REQUIRE(false);
        }
        catch(InvalidConfigurationException &e) {
            std::cout <<  e.what() << "\n";
            REQUIRE(true);
        }
    }
}

TEST_CASE("ex1", "[InvalidOptionException]")
{   
    SECTION( "Probando InvalidOptionException" ) {
        try {
            throw InvalidOptionException("Invalid option, please press C to continue next turn or E to end the game");
            REQUIRE(false);
        }
        catch(InvalidOptionException &e) {
            std::cout <<  e.what() << "\n";
            REQUIRE(true);
        }
    }
}

TEST_CASE("ex2", "[EndGameException]")
{   
    SECTION( "Probando EndGameException" ) {
        try {
            throw EndGameException("Abnormal Game End ...");
            REQUIRE(false);
        }
        catch(EndGameException &e) {
            std::cout <<  e.what() << "\n";
            REQUIRE(true);
        }
    }
}

TEST_CASE("ex3", "[EndGameException full Game]")
{   
    SECTION( "Probando Juego con excepciones" ) {
        try {
            GameManual g("t1.tab");
            g.setDadoAleatorio(false);
            g.setOutputToFile(true);

            g.start();
            REQUIRE(false);
        }
        catch(EndGameException &e) {
            std::cout <<  e.what() << "\n";
            REQUIRE(chkFiles("output", "test/toutput"));
        }
    }
}
