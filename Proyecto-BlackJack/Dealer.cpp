#include "Dealer.h"

Dealer::Dealer(std::string nombre, Mano* manoDealer) : JugadorGenerico(nombre, manoDealer)
{
}

Dealer::~Dealer()
{
}

Carta* Dealer::pedirCarta()
{
	return nullptr;
}

void Dealer::volteaSegunda()
{
}