#include "Jugador.h"
//Constructor con par�metros
Jugador::Jugador(std::string nombre, Mano* manoJugador) : JugadorGenerico(nombre, manoJugador){
}

//Desctructor de la clase Jugador
Jugador::~Jugador()
{
	delete[] mano;
}

Carta* Jugador::pedirCarta(){
	return nullptr;
}

bool Jugador::sePaso()
{
	return false;
}

