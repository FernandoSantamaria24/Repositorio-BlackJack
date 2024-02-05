#include "Carta.h"
//Constructor sin parámetros clase Carta
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
//Inicio métodos get clase Carta
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
//Final métodos get clase Carta
//Inicio métodos set clase Carta
void Carta::setValor(int v){
	valor = v;
}

void Carta::setPalo(int p){
	palo = p;
}

void Carta::setBocaAbajo(bool b){
	bocaAbajo = b;
}
//Final métodos set clase Carta
//Método que nos va a ayudar más adelante para voltear las cartas cuando se desee
void Carta::voltear()
{
	bocaAbajo = false;
}
//Método copia para no perder los valores de "Carta"
Carta* Carta::copia()
{
	return new Carta(valor, palo, bocaAbajo);
}
void Carta::guardarCarta(std::ofstream& file)
{
	file << valor << palo << bocaAbajo;
}
Carta* Carta::leerCarta(std::ifstream& file)
{
	int val, pal;
	bool bocaA;

	file >> val >> pal >> bocaA;

	Carta* nuevaCarta = new Carta(val, pal, bocaA);

	return nuevaCarta;
}
//Método mostrar clase Carta
void Carta::toString(){
	std::cout << valor;
	//Realizar un random con palo
}
