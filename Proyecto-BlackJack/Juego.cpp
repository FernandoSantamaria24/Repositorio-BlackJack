#include "Juego.h"
#include "Jugador.h"
#include "Dealer.h"
#include<fstream>
//Constructor sin par�metros de la clase Juego
Juego::Juego(){
	baraja.inicializador();
}
//Destructor de la clase Juego
Juego::~Juego(){}
//M�todo que permite darle dos cartas por jugador al iniciar un nuevo juego de BalckJACK
//Cada jugador recibe dos cartas por juego
void Juego::ingresarCartasIniciales(){
	//Ingresa las cartas de cada jugador 1 por una en orden de la lista
		//Esto permite que los jugadores tengan siempre cartas diferentes y estas no se repitan durante el juego de cada uno
	int contCartas = 0;
	Nodo* jugadoresIngresados = listaJugadores.getInicio();
	while (contCartas < 2) {
		if (jugadoresIngresados != nullptr) {
			jugadoresIngresados->dato->pedirCarta(&baraja);
			if (jugadoresIngresados->next == nullptr) {
				jugadoresIngresados = listaJugadores.getInicio();
				contCartas++;
			}
			else {
				jugadoresIngresados = jugadoresIngresados->next;
			}
		}
	}
}
//M�todo encargado de ingresar los jugadores dentro del juego de BlackJack
bool Juego::ingresoJugadores(){
	bool respuesta = false;
	int cantErrores = 0;
	while(respuesta!=true&&cantErrores<3){
		std::cout << "Ingrese la cantidad de jugadores (Maximo 7):  " << std::endl;
		int cantJugadores = 0;
		int cantIngresada = 0;
		try {
			std::cin >> cantIngresada;
			if (std::cin.fail()) {
				system("cls");
				throw std::invalid_argument("Opcion invalida. Por favor, ingrese un numero.");
			}
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
		//Ingresar cartas a los jugadores nuevos
		ingresarCartasIniciales();
		//Al ingresar jugadores y cartas se retorna true para empezar el juego en su totalidad
		respuesta = true;
		}else {
		system("cls");
		std::cout << "La cantidad de jugadores es invalida (Maximo 7)\n" << std::endl;
		cantErrores++;
		}
	}catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		// Limpiar el estado de error de std::cin y descartar la entrada incorrecta
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cantErrores++;
	}
	return respuesta;
	}
}
//M�todo Jugar encargado de toda la l�gica del juego BlackJack
void Juego::jugar(){
	std::string opcionJuego = "C";
	bool continuidad = true;
	std::cout << "----------------JUEGO BLACKJACK----------------\n" << std::endl;
	//En cuanto se logren ingresar todos los usuarios dentro del juego inicia el juego en su totalidad
	//En caso de no ser posible ingresar los jugadores se enviar� un mensaje de error 
	if (ingresoJugadores()!=false||listaJugadores.getInicio()!=nullptr) {
		baraja.barajar();
		system("cls");
		Nodo* actual = listaJugadores.getInicio()->next;
		//El juego termina cuando... (por asignar)
		//VERIFICACI�N DE JUEGO PARA FINALIZAR
		while(continuidad==true) {
		system("cls");
		std::cout << "Bienvenido al juego blackjack\n" << std::endl;
		if(actual!=listaJugadores.getInicio()){
		listaJugadores.getInicio()->dato->toString();
		std::cout << "\nJUGADOR\n";
		actual->dato->toString();
		std::cout << "\n\n        (D)eme Carta   -   (P)asar   -   (G)uardar Partida   -   (S)alir   \n" << std::endl;
		std::cin >> opcionJuego;
		//Seg�n la opcion desea se ejecuta una opci�n diferente en el sistema
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
						system("cls");
						std::cout << "Guardando partida...\n" << std::endl;
						guardarJuego();
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
		//Al llegar al dealer el juego se terminar� y empezar� a dar los resultados uno por uno
		else {
			actual = listaJugadores.getInicio()->next;
			while(actual!=nullptr) {
				if (listaJugadores.getInicio()->dato->getMano()->getPuntos() < 16) {
					listaJugadores.getInicio()->dato->pedirCarta(&baraja);
				}
				else {
					std::cout << "RESULTADOS\n";
					listaJugadores.getInicio()->dato->toString(); std::cout << "------> CASA\n";
					//Si la suma de cartas es menor a la casa GANA
					if (actual->dato->getMano()->getPuntos() < listaJugadores.getInicio()->dato->getMano()->getPuntos()) {
						actual->dato->toString(); std::cout << "------> LE GANO A LA CASA\n";
					}
					else {
						//Si la suma de cartas es mayor a la casa PIERDE
						if (actual->dato->getMano()->getPuntos() > listaJugadores.getInicio()->dato->getMano()->getPuntos()) {
							actual->dato->toString(); std::cout << "------> PERDIO CONTRA LA CASA\n";
						}
						//Si la suma de cartas es igual a la casa EMPATA
						else {
							actual->dato->toString(); std::cout << "------> EMPATO CONTRA LA CASA\n";
						}
					}
					std::string next;
					std::cout << "Next  (N)\n";
					std::cout << "Terminar resultados  (S)\nDigitar respuesta:";
					std::cin >> next;
					if (next=="N"||next=="n") {
						system("cls");
						actual = actual->next;
					}
					else {
						actual = nullptr;
					}
				}
			}
			std::cout << "\nEl juego actual termino\n";
				std::cout << "\nDesea repetir el juego con los mismos jugadores (C)\n" << "retornar a la pantalla inicial (S)\nRespuesta:";
				std::cin >> opcionJuego;
				if (opcionJuego == "C" || opcionJuego == "c") {
					listaJugadores.limpiarManoJugadores();
					baraja.barajar();//Revuelve las cartas 
					ingresarCartasIniciales();//Ingresa cartas (2) a cada jugador
					actual = listaJugadores.getInicio()->next;
					continuidad = true;
				}
				else {
					if (opcionJuego == "S" || opcionJuego == "s") {
						continuidad = false;
					}
					else {
						std::cout << "\nLa opcion dada no es valida por lo tanto el juego terminara";
						continuidad = false;
					}
				}
			
		
			
			}	
		}
		system("cls");
		std::cout << "          EL JUEGO LLEGO A SU FINAL\n" << std::endl;
		std::cout << "GRACIAS POR JUGAR EN NUESTRO SISTEMA  BLACKJACK\n" << std::endl;
		exit(0);
	}
	else {
		std::cout << "El ingreso de jugadores tuvo un error (Intente de nuevo)\n" << std::endl;
	}
}

void Juego::guardarJuego()
{
	std::ofstream file;
	file.open("Juego.txt");
	if (file.is_open()) {
		return;
	}
	baraja.guardarMazo(file); 
	listaJugadores.guardarLista(file); 
	std::cout << "Partida Guardada\n";

	file.close();
}

void Juego::leerJuego()
{
	std::ifstream file;
	file.open("Juego.txt");
	if (file.is_open()) {
		std::cout << "No se pudo abrir el archivo del juego.\n";
		return;
	}
	baraja.leerMazo(file);
	listaJugadores.leerLista(file);

	file.close();
}

