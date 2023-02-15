all: clean test

appTests: test/tests.cpp
	g++ -Wall --std=c++17 test/tests.cpp test/catch_amalgamated.cpp test/chkFiles.cpp EndGameException.cpp InvalidOptionException.cpp InvalidConfigurationException.cpp Turno.cpp GameAutomatic.cpp GameManual.cpp Game.cpp CDado.cpp Jugador.cpp Tablero.cpp CCasilla.cpp CasillaNormal.cpp CasillaEscalera.cpp CasillaSerpiente.cpp -o build/appTests
test: appTests
	# executes all tests
	./build/appTests

clean:
	rm -f build/appTests
	rm -f build/exercise
run:
	g++ *.cpp -o build/exercise
	clear
	./build/exercise
debug: 
	g++ *.cpp -g -o dexercise
	gdb dexercise
	rm -f dexercise
debugvs:
	g++ *.cpp -g -o build/dexercise
debugtest: 
	g++ -Wall --std=c++17 test/tests.cpp test/catch_amalgamated.cpp test/chkFiles.cpp EndGameException.cpp InvalidOptionException.cpp InvalidConfigurationException.cpp Turno.cpp GameAutomatic.cpp GameManual.cpp Game.cpp CDado.cpp Jugador.cpp Tablero.cpp CCasilla.cpp CasillaNormal.cpp CasillaEscalera.cpp CasillaSerpiente.cpp -g -o build/dexercise