#include "Carta.h"
//Constrcutor sin parámetros clase Carta
Carta::Carta()
{
	valor = 0;
	palo = 0;
	bocaAbajo = true;
}
//Constructor con parámetros clase Carta
Carta::Carta(int val, int pal, bool bocaA) : valor(val), palo(pal), bocaAbajo(bocaA)
{
}
//Desctructor básico de la clase Carta
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

bool Carta::getBocaAbajo()
{
	return bocaAbajo;
}

void Carta::setValor(int v){
	valor = v;
}

void Carta::setPalo(int p){
	palo = p;
}

void Carta::setBocaAbajo(bool b){
	bocaAbajo = b;
}

void Carta::voltear()
{
	bocaAbajo = true;
}