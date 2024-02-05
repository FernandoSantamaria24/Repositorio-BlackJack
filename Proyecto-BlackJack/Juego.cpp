#include "Juego.h"
#include "Jugador.h"
//Constructor sin parámetros de la clase Juego
Juego::Juego(){}
//Destructor de la clase Juego
Juego::~Juego(){}
//Método Jugar encargado de toda la lógica del juego BlackJack
void Juego::jugar(){
	std::cout << "----------------JUEGO BLACKJACK----------------\n";
	std::cout << "Ingrese la cantidad de jugadores (Maximo 7):  ";
	int cantJugadores = 0;
	int cantIngresada = 0;
	std::cin >> cantJugadores;
	if (cantJugadores>0&&cantJugadores<=7) {
		while (cantIngresada<=cantJugadores) {
			std::string nombre;
			std::cout << "\nNickname:  ";
			std::cin >> nombre;
			if(listaJugadores.buscarNombreJugador(nombre)!=true){
			Mano* manoNueva = new Mano();
			Jugador* jugadorIngreso = new Jugador(nombre,manoNueva);
			listaJugadores.insertarNodoJugador(jugadorIngreso);
			std::cout << "Jugador Ingresado\n" << listaJugadores.buscaPersona(jugadorIngreso)->dato->getNickname() << "\n";
			cantIngresada++;
			system("cls");
			std::cout << "----------------JUEGO BLACKJACK----------------\n";
			std::cout << "Digite nickname del siguiente jugador\n";
			}
			else {
				std::cout << "El nickname de juego escogido ya se encuentra dentro de los participantes\n";
				std::cout << "Favor de escoger algun otro nombre diferente\n";
			}
		}
	}
	else {
		std::cout << "La cantidad de jugadores es invalida (Maximo 7)\n";
	}
	                 


















}

void Juego::toString(){
}
