#include "Dealer.h"
//Constructor con par�metros
Dealer::Dealer(std::string nombre, Mano* manoDealer) : JugadorGenerico(nombre, manoDealer){
}
//Destructor de la clase Dealer
Dealer::~Dealer(){
	delete[] mano;
}
//M�todo encargado de pedir la carta de cada jugador en la clase de Dealer
//A�ade cada carta a la mano del jugadro determinado en el Juego
Carta* Dealer::pedirCarta(Mazo* mazo){
	if (!sePaso()) {
		Carta* nuevaCarta = mano->agregarCarta(mazo);
		if (nuevaCarta != nullptr) {
			mano->agregarCarta((Mazo*)&nuevaCarta);
			return nuevaCarta;
		}
		else {
			std::cout << "No quedan m�s cartas en el mazo\n";
			return nullptr;
		}
	}
	else {
		std::cout << "Ya no se pueden pedir m�s cartas\n";
		return nullptr;
	}
}
//En este m�todo se crea una copia de Dealer con su nombre y mano respectivamente
JugadorGenerico* Dealer::copia()
{
	return new Dealer(nickname, mano);
}
//M�todo encargado de conocer si los jugadore la cantidad de cartas en mayor o no de 21 
bool Dealer::sePaso()
{
	if (mano->getPuntos() > 21) {
		return false;
	}
	return true;
}


//Voltea la segunda carta del deaelr para ser mostrada a los jugadores del juego
//Si la segunda carta esta volteada se va mostrando en el toString
void Dealer::volteaSegunda()
{
	Mano* manoDeDealer = getMano();
	if (manoDeDealer->getCantidad() >= 2) {
		Carta* segunda = manoDeDealer->getCartaPosicion(1);
		segunda->setBocaAbajo(true);
	}
}
//M�todo toString de la clase Dealer
//Muestra las cartas del Dealer dentro del juego
void Dealer::toString()
{
	for (int i = 0; i < 9; i++)
	{
		if (mano->getCartaPosicion(i)->getBocaAbajo()==true) {
			mano->getCartaPosicion(i)->toString();
		}
	}
}
