#include "JugadorGenerico.h"

JugadorGenerico::JugadorGenerico() : nickname("	"), mano(NULL)
{
}

JugadorGenerico::JugadorGenerico(std::string nick, Mano* manoJuego) : nickname(nick), mano(manoJuego)
{
}

JugadorGenerico::~JugadorGenerico()
{
}

Carta* JugadorGenerico::pedirCarta()
{
	return 0;
}

bool JugadorGenerico::sePaso()
{
	return 0;
}