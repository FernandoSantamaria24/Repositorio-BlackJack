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
	return nullptr;
}

bool JugadorGenerico::sePaso()
{
	return false;
}