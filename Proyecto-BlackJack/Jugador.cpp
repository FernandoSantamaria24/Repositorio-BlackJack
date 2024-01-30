#include "Jugador.h"
//Constructor con par�metros
Jugador::Jugador(std::string nombre, Mano* manoJugador) : JugadorGenerico(nombre, manoJugador){
}

//Desctructor de la clase Jugador
Jugador::~Jugador()
{
	delete[] mano;
}

Carta* Jugador::pedirCarta(Mazo* mazo){
	if (!sePaso()) {
		Carta* nuevaCarta = mano->agregarCarta(mazo);
		if (nuevaCarta != nullptr) {
			mano->agregarCarta((Mazo*)&nuevaCarta); 
			return nuevaCarta;
		}
		else {
			std::cout << "No quedan m�s cartas en el mazo\n";
			return nullptr;
		}
	}
	else {
		std::cout << "Ya no se pueden pedir m�s cartas\n";
		return nullptr;
	}
}

bool Jugador::sePaso()
{
	if (mano->getPuntos()>21) {
		return false;
	}
	return true;
}

