#include "Jugador.h"
//Constructor con parámetros
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

