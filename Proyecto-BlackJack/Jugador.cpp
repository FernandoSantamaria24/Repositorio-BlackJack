#include "Jugador.h"
//Constructor con parámetros
Jugador::Jugador(std::string nombre, Mano* manoJugador) : JugadorGenerico(nombre, manoJugador){
}

//Desctructor de la clase Jugador
Jugador::~Jugador()
{
	delete[] mano;
}
//Método encargado de pedir la carta de cada jugador en la clase de Jugador
//Añade cada carta a la mano del jugadro determinado en el Juego
Carta* Jugador::pedirCarta(Mazo* mazo){
	if (!sePaso()) {
		Carta* nuevaCarta = mano->agregarCarta(mazo);
		if (nuevaCarta != nullptr) {
			mano->agregarCarta((Mazo*)&nuevaCarta); 
			return nuevaCarta;
		}
		else {
			std::cout << "No quedan más cartas en el mazo\n";
			return nullptr;
		}
	}
	else {
		std::cout << "Ya no se pueden pedir más cartas\n";
		return nullptr;
	}
}
//Método encargado de conocer si los jugadore la cantidad de cartas en mayor o no de 21 
bool Jugador::sePaso()
{
	if (mano->getPuntos()>21) {
		return false;
	}
	return true;
}
//Método toString de la clase JUgador
//Muestra cada una de las cartas del jugador con sus valores respectivos 
void Jugador::toString(){
	mano->toString();
}

