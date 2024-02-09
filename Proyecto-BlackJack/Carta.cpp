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
//Muestra el valor de la carta y su palo
void Carta::toString(){
	if (valor==1||valor==11) {
		std::cout << "A";
	}
	else {
		if (valor>=12) {
			std::cout <<"10";
		}else{
			std::cout << valor;
		}
	}
	if (valor >= 12) {
		switch (palo){
		case 1:
			std::cout <<"J";
			break;
		case 2:
			std::cout << "Q" ;
			break;
		case 3:
			std::cout << "K";
			break;
		default:
			std::cout << "T" ;
			break;
		}
	}
	else {
	switch (palo){
	case 1:
		std::cout << "E";
		break;
	case 2:
		std::cout << "C";
		break;
	case 3:
		std::cout << "D";
		break;
	case 4:
		std::cout << "T";
		break;
	}
	}
}
