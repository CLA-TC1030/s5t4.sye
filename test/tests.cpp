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
        INFO("FUNCIONALIDAD ESPERADA: La clase InvalidConfigurationException debe heredar de std::exception y lanzar una excepcion con un mensaje personalizado que contenga el valor invalido de configuracion.");
        INFO("SUGERENCIA DE PROGRAMACION: Implementa un constructor que reciba un string con el mensaje de error y almacenalo en un atributo privado. Sobrescribe el metodo what() para devolver el mensaje mediante c_str().");
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
        INFO("FUNCIONALIDAD ESPERADA: La clase InvalidOptionException debe heredar de std::exception y lanzar una excepcion cuando el usuario ingrese una opcion invalida en el menu del juego.");
        INFO("SUGERENCIA DE PROGRAMACION: Crea una clase similar a InvalidConfigurationException con un constructor que reciba el mensaje de error y un metodo what() que devuelva ese mensaje.");
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
        INFO("FUNCIONALIDAD ESPERADA: La clase EndGameException debe heredar de std::exception y lanzar una excepcion cuando el juego finalice de manera anormal o prematura.");
        INFO("SUGERENCIA DE PROGRAMACION: Implementa una clase de excepcion con constructor que reciba un mensaje descriptivo de finalizacion y sobrescribe what() para retornarlo como c_str().");
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
        INFO("FUNCIONALIDAD ESPERADA: El juego debe manejar excepciones InvalidOptionException cuando el usuario ingrese opciones invalidas multiples veces, y lanzar EndGameException cuando se exceda el limite de intentos, generando una salida que coincida con el archivo toutput.");
        INFO("SUGERENCIA DE PROGRAMACION: En el metodo start() de Game, usa un bloque try-catch dentro de un ciclo while para capturar InvalidOptionException. Incrementa un contador de intentos y cuando llegue a 5, lanza EndGameException. Asegurate de escribir los mensajes correctos al archivo output usando outMsg().");
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
