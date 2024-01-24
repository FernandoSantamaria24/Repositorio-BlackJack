#include "Carta.h"

Carta::Carta(int val, int pal, bool bocaA) : valor(val), palo(pal), bocaAbajo(bocaA)
{
}

Carta::~Carta()
{
}

int Carta::getValor()
{
	return valor;
}

int Carta::getPalo()
{
	return palo;
}

void Carta::voltear()
{
	if (bocaAbajo == true) {
		std::cout << "Esta carta esta volteada.";
	}
	else {
		std::cout << valor << palo;
	}
}