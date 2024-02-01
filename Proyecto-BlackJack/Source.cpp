#include <iostream>
#include "Juego.h"
//Main de pruebas 
int ingresoSistema();
int main() {
	Juego juegoInicial;
	switch (ingresoSistema()){
	case 1:
		juegoInicial.jugar();
		break;
	case 2:
		std::cout << "CARGANDO JUEGO ANTIGUO\n";
		break;
	case 3:
		exit(0);
		break;
	default:
		std::cout << "la opcion no se encuentra dentro del sistema\n  Digitar numeros entre 1-3\n";
		ingresoSistema();
	}
	return 0;
}
int ingresoSistema() {
	int opcion;
	std::cout << "(1)  Nuevo Juego: Inicio un juego nuevo de Blackjack \n";
	std::cout << "(2)  Cargar Partida: Carga una partida guardada de un juego previo de Blackjac\n";
	std::cout << "(3)  Salir: Termina el programa\n";
	std::cin >> opcion;

	return opcion;
}