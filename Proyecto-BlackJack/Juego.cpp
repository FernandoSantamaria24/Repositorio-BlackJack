#include "Juego.h"
#include "Jugador.h"
//Constructor sin parámetros de la clase Juego
Juego::Juego(Mazo* m):baraja{m}{
	baraja->inicializador();
	baraja->barajar();
}
//Destructor de la clase Juego
Juego::~Juego(){}
bool Juego::ingresoJugadores(){
	bool respuesta = false;
	int cantErrores = 0;
	while(respuesta!=true&&cantErrores<3){
		std::cout << "Ingrese la cantidad de jugadores (Maximo 7):  ";
		int cantJugadores = 0;
		int cantIngresada = 0;
		std::cin >> cantJugadores;
	if (cantJugadores > 0 && cantJugadores <= 7) {
		while (cantIngresada <= cantJugadores) {
			std::string nombre;
			std::cout << "\nNickname:  ";
			std::cin >> nombre;
			if (listaJugadores.buscarNombreJugador(nombre) != true) {
				Mano* manoNueva = new Mano();
				Jugador* jugadorIngreso = new Jugador(nombre, manoNueva);
				listaJugadores.insertarNodoJugador(jugadorIngreso);
				system("cls");
				std::cout << "Jugador Ingresado\n" << listaJugadores.buscaPersona(jugadorIngreso)->dato->getNickname() << "\n";
				cantIngresada++;
				std::cout << "----------------JUEGO BLACKJACK----------------\n";
				std::cout << "Digite nickname del siguiente jugador\n";
			}
			else {
				std::cout << "El nickname de juego escogido ya se encuentra dentro de los participantes\n";
				std::cout << "Favor de escoger algun otro nombre diferente\n";
			}
		}
		respuesta = true;
		}else {
		system("cls");
		std::cout << "La cantidad de jugadores es invalida (Maximo 7)\n";
		cantErrores++;
		}
	}
	return respuesta;
}
//Método Jugar encargado de toda la lógica del juego BlackJack
void Juego::jugar(){
	std::cout << "----------------JUEGO BLACKJACK----------------\n";
	if (ingresoJugadores()!=false) {
		std::cout << "Bienvenido al juego blackjack\n";
	}
	else {
		std::cout << "EL INGRESO DE LOS JUGADORES NO PUDO SER TRAMITADO POR PROBLEMAS DE INGRESOS\n";
	}


















}

void Juego::toString(){
}
