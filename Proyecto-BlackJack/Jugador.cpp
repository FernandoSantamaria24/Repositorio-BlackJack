#include "Jugador.h"

Jugador::Jugador(std::string nombre, Mano* manoJugador) : JugadorGenerico(nombre, manoJugador)
{
}

Jugador::~Jugador()
{
}

Carta* Jugador::pedirCarta()
{
	return nullptr;
}