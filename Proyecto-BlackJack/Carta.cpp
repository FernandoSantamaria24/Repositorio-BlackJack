#include "Carta.h"
//Constructor sin par�metros clase Carta
Carta::Carta()
{
	valor = 0;
	palo = 0;
	bocaAbajo = true;
}
//Constructor con par�metros clase Carta
Carta::Carta(int val, int pal, bool bocaA) : valor(val), palo(pal), bocaAbajo(bocaA)
{
}
//Desctructor b�sico de la clase Carta
Carta::~Carta()
{
}
//Inicio m�todos get clase Carta
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
//Final m�todos get clase Carta
//Inicio m�todos set clase Carta
void Carta::setValor(int v){
	valor = v;
}

void Carta::setPalo(int p){
	palo = p;
}

void Carta::setBocaAbajo(bool b){
	bocaAbajo = b;
}
//Final m�todos set clase Carta
//M�todo que nos va a ayudar m�s adelante para voltear las cartas cuando se desee
void Carta::voltear()
{
	bocaAbajo = false;
}
//M�todo copia para no perder los valores de "Carta"
Carta* Carta::copia()
{
	return new Carta(valor, palo, bocaAbajo);
}
//M�todo mostrar clase Carta
void Carta::toString(){
	std::cout << valor;
	//Realizar un random con palo
}
