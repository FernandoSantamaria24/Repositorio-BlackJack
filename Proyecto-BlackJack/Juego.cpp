#include "Juego.h"
#include<fstream>
//Constructor sin parámetros de la clase Juego
Juego::Juego(){}
//Destructor de la clase Juego
Juego::~Juego(){}
//Método encargado de ingresar los jugadores dentro del juego de BlackJack
bool Juego::ingresoJugadores(){
	bool respuesta = false;
	int cantErrores = 0;
	while(respuesta!=true&&cantErrores<3){
		std::cout << "Ingrese la cantidad de jugadores (Maximo 7):  " << std::endl;
		int cantJugadores = 0;
		int cantIngresada = 0;
		std::cin >> cantJugadores;
	if (cantJugadores > 0 && cantJugadores <= 7) {
		while (cantIngresada <= cantJugadores) {
			std::string nombre;
			std::cout << "\nNickname:  " << std::endl;
			std::cin >> nombre;
			if (listaJugadores.buscarNombreJugador(nombre) != true) {
				Mano* manoNueva = new Mano();
				Jugador* jugadorIngreso = new Jugador(nombre, manoNueva);
				listaJugadores.insertarNodoJugador(jugadorIngreso);
				system("cls");
				std::cout << "Jugador Ingresado\n" << listaJugadores.buscaPersona(jugadorIngreso)->dato->getNickname() << "\n" << std::endl;
				cantIngresada++;
				std::cout << "----------------JUEGO BLACKJACK----------------\n" << std::endl;
				std::cout << "Digite nickname del siguiente jugador\n" << std::endl;
			}
			else {
				std::cout << "El nickname de juego escogido ya se encuentra dentro de los participantes\n" << std::endl;
				std::cout << "Favor de escoger algun otro nombre diferente\n" << std::endl;
			}
		}
		respuesta = true;
		}else {
		system("cls");
		std::cout << "La cantidad de jugadores es invalida (Maximo 7)\n" << std::endl;
		cantErrores++;
		}
	}
	return respuesta;
}
//Método Jugar encargado de toda la lógica del juego BlackJack
void Juego::jugar(){
	int opcionJuego=0;
	std::cout << "----------------JUEGO BLACKJACK----------------\n" << std::endl;
	//En cuanto se logren ingresar todos los usuarios dentro del juego inicia el juego en su totalidad
	if (ingresoJugadores()!=false) {
		system("cls");
		Nodo* actual = listaJugadores.getInicio();
		std::cout << "Bienvenido al juego blackjack\n" << std::endl;
		//El juego termina cuando... (por asignar)
		//VERIFICACIÓN DE JUEGO PARA FINALIZAR
		while(opcionJuego!=5) {
		system("cls");
		std::cout <<"JUGADOR ACTUAL: " <<actual->dato->getNickname() << "\n";
		std::cout << "\n 1(D)eme Carta   -   2(P)asar   -   3(G)uardar Partida   -   4(S)alir   \n" << std::endl;
		std::cin >> opcionJuego;
		//Según la opcion desea se ejecuta una opción diferente en el sistema
			if(opcionJuego==1){
			std::cout << "Carta optenida\n" << std::endl;
			}else{
				if (opcionJuego==2) {
					system("cls");
					if (actual->next!=nullptr) {
						actual = actual->next;
					}
					else {
					actual= listaJugadores.getInicio();
					std::cout << "Siguiente jugador\n" << std::endl;
					}
				}
				else {
					if (opcionJuego == 3) {
						system("cls");
						std::cout << "Guardanda partida...\n" << std::endl;
					}
					else {
						if (opcionJuego==4) {
							system("cls");
							std::cout << "Saliendo...\n" << std::endl;
							exit(0);
						}
						else {
							std::cout << "La opcion deseada no se encuentra dentro del sistema\n" << std::endl;
						}
					}
				}
			}
		}
		system("cls");
		std::cout << "El juego llego a su final\n" << std::endl;
		std::cout << "GRACIAS POR JUGAR EN NUESTRO SISTEMA DE BLACKJACK\n" << std::endl;
		exit(0);
	}
	else {
		std::cout << "El ingreso de jugadores tuvo un error (Intente de nuevo)\n" << std::endl;
	}
}

void Juego::toString(){
}
