#include "Dealer.h"
//Constructor con parámetros
Dealer::Dealer(std::string nombre, Mano* manoDealer) : JugadorGenerico(nombre, manoDealer){
}
//Destructor de la clase Dealer
Dealer::~Dealer(){
	delete[] mano;
}

Carta* Dealer::pedirCarta(){
	return nullptr;
}

bool Dealer::sePaso()
{
	if (mano->getPuntos() > 21) {
		return false;
	}
	return true;
}



void Dealer::volteaSegunda(){
}