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

void Carta::setValor(int n){
	if (palo==0) {
		std::cout << "El valor de su carta  'A' a sido cambiado por: " << n;
		valor = n;
	}
	else {
		std::cout << "El palo de su carta no coincide con un As";
	}
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