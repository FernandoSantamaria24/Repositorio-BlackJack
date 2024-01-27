#include <iostream>
#include "Carta.h"
#include "Mazo.h"
#include "Lista.h"
#include "Jugador.h"
//Main de pruebas 
int main() {
	//Prueba de clase lista para conocer su funcionamiento
	Lista l;
	Jugador* j= new Jugador("Pedro", NULL);
	l.insertarNodoJugador(j);
	//Prueba para metodos de la clase Mazo
	Mazo m;
	//Inciar las cartas con un valor de 1 a 10
	std::cout << "\nINICIO MAZO SIN BARAJAR\n";
	m.inicializador();
	m.toString();
	//Barajar las cartas para su mezcla
	std::cout << "\nINICIO MAZO BARAJADO\n";
	m.barajar();
	m.toString();

	delete j;
	return 0;
}