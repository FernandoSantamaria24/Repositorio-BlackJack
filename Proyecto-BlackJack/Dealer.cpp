#include "Dealer.h"
//Constructor con parámetros
Dealer::Dealer(std::string nombre, Mano* manoDealer) : JugadorGenerico(nombre, manoDealer){
}
//Destructor de la clase Dealer
Dealer::~Dealer(){
	delete[] mano;
}

Carta* Dealer::pedirCarta(Mazo* mazo){
	if (!sePaso()) {
		Carta* nuevaCarta = mano->agregarCarta(mazo);
		if (nuevaCarta != nullptr) {
			mano->agregarCarta((Mazo*)&nuevaCarta);
			return nuevaCarta;
		}
		else {
			std::cout << "No quedan más cartas en el mazo\n";
			return nullptr;
		}
	}
	else {
		std::cout << "Ya no se pueden pedir más cartas\n";
		return nullptr;
	}
}

bool Dealer::sePaso()
{
	if (mano->getPuntos() > 21) {
		return false;
	}
	return true;
}



void Dealer::volteaSegunda()
{
	Mano* manoDeDealer = getMano();
	if (manoDeDealer->getCantidad() >= 2) {
		Carta* segunda = manoDeDealer->getCartaPosicion(1);
		segunda->setBocaAbajo(true);
	}
}