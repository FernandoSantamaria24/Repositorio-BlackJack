#include "Juego.h"
#include "Jugador.h"
#include "Dealer.h"
#include<fstream>
//Constructor sin parámetros de la clase Juego
Juego::Juego(){
	baraja.inicializador();
	baraja.barajar();
}
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
		std::cin >> cantIngresada;
	if (cantIngresada >= 1 && cantIngresada <= 7) {
		Mano* manoD = new Mano();
		Dealer* dealer = new Dealer("Dealer", manoD);
		listaJugadores.insertarNodoJugador(dealer);
		while (cantJugadores < cantIngresada) {
			//Ingresar la cantidad de  jugadores encogidos por el usuario >=1 && >7
			std::string nombre;
			std::cout << "\nNickname:  " << std::endl;
			std::cin >> nombre;
			if (listaJugadores.buscarNombreJugador(nombre) != true) {
				Mano* manoJ = new Mano();
				Jugador* jugadorIngreso = new Jugador(nombre,manoJ);
				listaJugadores.insertarNodoJugador(jugadorIngreso);
				system("cls");
				std::cout << "Jugador Ingresado\n" << listaJugadores.buscaPersona(jugadorIngreso)->dato->getNickname() << "\n" << std::endl;
				cantJugadores++;
				std::cout << "----------------JUEGO BLACKJACK----------------\n" << std::endl;
				std::cout << "Digite nickname del siguiente jugador\n" << std::endl;
			}
			else {
				std::cout << "El nickname de juego escogido ya se encuentra dentro de los participantes\n" << std::endl;
				std::cout << "Favor de escoger algun otro nombre diferente\n" << std::endl;
			}
		}
		//Ingresa las xartas de cada jugador 1 por una en orden de la lista
		//Esto permite que los jugadores tengan siempre cartas diferentes y estas no se repitan durante el juego de cada uno
		int contCartas = 0;
		Nodo* jugadoresIngresados = listaJugadores.getInicio();
		while (contCartas<2) {
			if (jugadoresIngresados!=nullptr) {
				jugadoresIngresados->dato->pedirCarta(&baraja);
				if (jugadoresIngresados->next==nullptr) {
					jugadoresIngresados = listaJugadores.getInicio();
					contCartas++;
				}
				else {
					jugadoresIngresados = jugadoresIngresados->next;
				}
			}
		}
		//Al ingresar jugadores y cartas se retorna true para empezar el juego en su totalidad
		respuesta = true;
		}else {
		system("cls");
		std::cout << "La cantidad de jugadores es invalida (Maximo 7)\n" << std::endl;
		cantErrores++;
		}
	}
	std::cout << "La cantidad de jugadores es invalida (Maximo 7)\n" << std::endl;
	return respuesta;
}
//Método encargado de decirnos que jugadores perdieron,ganaron o empataron con la casa
//Método se activa cuando la casa de toda la vuelta a la mesa de juego
void Juego::verificacion(Nodo* dealer){
	Nodo* jugadores = listaJugadores.getInicio()->next;
	//Mientra dealer sus cartas sean menores a 21 sigue sumando cartas a su mazo
	if (dealer->dato->getMano()->getPuntos()<16) {
		dealer->dato->pedirCarta(&baraja);
	}
	else {
		std::cout << "RESULTADOS JUEGO ACTUAL\n" << std::endl;
		dealer->dato->toString(); std::cout << "------> CASA\n";
		while (jugadores!=dealer) {
			if(jugadores!=nullptr){
			//Si la suma de cartas es menor a la casa GANA
			if (jugadores->dato->getMano()->getPuntos() < dealer->dato->getMano()->getPuntos()) {
				jugadores->dato->toString(); std::cout << "------> LE GANO A LA CASA\n" << std::endl;
			}
			else {
				//Si la suma de cartas es mayor a la casa PIERDE
				if (jugadores->dato->getMano()->getPuntos() > dealer->dato->getMano()->getPuntos()) {
					jugadores->dato->toString(); std::cout << "------> PERDIO CONTRA LA CASA" << std::endl;
				}
				//Si la suma de cartas es igual a la casa EMPATA
				else {
					jugadores->dato->toString(); std::cout << "------> EMPATO CONTRA LA CASA" << std::endl;
				}
			}
			jugadores = jugadores->next;
			}
		}
	}
}
//Si la partida es continuada con los mismos jugadores limpia la mano de cada uno de ellos
void Juego::limpiarJugadoresActual(){
	Nodo* actual = listaJugadores.getInicio();
	//Mientras se encuentre un jugador en la lista se le limpia la mano actual
	if(actual!=nullptr){
			actual->dato->getMano()->limpiar();
			actual = actual->next;
	}
}
//Método Jugar encargado de toda la lógica del juego BlackJack
void Juego::jugar(){
	std::string opcionJuego = "C";
	bool continuidad = true;
	std::cout << "----------------JUEGO BLACKJACK----------------\n" << std::endl;
	//En cuanto se logren ingresar todos los usuarios dentro del juego inicia el juego en su totalidad
	//En caso de no ser posible ingresar los jugadores se enviará un mensaje de error 
	if (ingresoJugadores()!=false) {
		baraja.barajar();
		system("cls");
		Nodo* actual = listaJugadores.getInicio()->next;
		std::cout << "Bienvenido al juego blackjack\n" << std::endl;
		//El juego termina cuando... (por asignar)
		//VERIFICACIÓN DE JUEGO PARA FINALIZAR
		while(continuidad==true||opcionJuego=="C") {
		if(actual!=listaJugadores.getInicio()){
		system("cls");
		actual->dato->toString();
		std::cout << "\n        (D)eme Carta   -   (P)asar   -   (G)uardar Partida   -   (S)alir   \n" << std::endl;
		std::cin >> opcionJuego;
		//Según la opcion desea se ejecuta una opción diferente en el sistema
			if(opcionJuego == "D"||opcionJuego == "d"){
				if (!actual->dato->sePaso()) {
			actual->dato->pedirCarta(&baraja);
				}else {
					system("cls");
					if (actual->next != nullptr) {
						actual = actual->next;
					}
					else {
						actual = listaJugadores.getInicio();
					}
				}
			}
			else{
				if (opcionJuego == "P" || opcionJuego == "p") {
					if (actual->next!=nullptr) {
						actual = actual->next;
					}
					else {
					actual= listaJugadores.getInicio();
					std::cout << "Siguiente jugador\n" << std::endl;
					}
					system("cls");
				}
				else {
					if (opcionJuego == "G" || opcionJuego == "g") {
						std::cout << "Guardanda partida...\n" << std::endl;
						system("cls");
					}
					else {
						if (opcionJuego=="S" || opcionJuego == "s") {
							system("cls");
							std::cout << "Saliendo...\n" << std::endl;
							exit(0);
						}
						else {
							std::cout << "Opcion no encontrada en el juego\n" << std::endl;
						}
					}
				}
			}
		}
		//Si llegamos al lugar de la casa dentro de la listaJugadores entonces hacemos la verificacion de los jugadores contra la casa
		else {
			verificacion(actual);
			std::cout << "\nDesea repetir el juego con los mismos jugadores (C)\n" <<"retornar a la pantalla inicial (S)\n" << std::endl;
			std::cin >> opcionJuego;
			if (opcionJuego=="C"||opcionJuego == "c") {
				limpiarJugadoresActual();//ARREGLAR
				baraja.barajar();//OBSERVACIONES
				actual = actual->next;
				opcionJuego = "C";
				continuidad = true;
			}
			else {
				if (opcionJuego=="S" || opcionJuego == "s") {
					continuidad = false;
				}
				else {
					std::cout << "\nLa opcion dada no es valida por lo tanto el juego acabara";
					continuidad = false;
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
