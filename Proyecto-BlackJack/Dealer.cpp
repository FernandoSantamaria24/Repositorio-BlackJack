#include "Dealer.h"
//Constructor con par�metros
Dealer::Dealer(std::string nombre, Mano* manoDealer) : JugadorGenerico(nombre, manoDealer){}
//Destructor de la clase Dealer
Dealer::~Dealer(){
	delete[] mano;
}

Carta* Dealer::pedirCarta(){
	return nullptr;
}

void Dealer::volteaSegunda(){
}