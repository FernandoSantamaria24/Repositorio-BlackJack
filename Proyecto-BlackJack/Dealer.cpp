#include "Dealer.h"
//Constructor con parámetros
Dealer::Dealer(std::string nombre, Mano* manoDealer) : JugadorGenerico(nombre, manoDealer){
}
//Destructor de la clase Dealer
Dealer::~Dealer(){
	delete[] mano;
}
//Método encargado de pedir la carta de cada jugador en la clase de Dealer
//Añade cada carta a la mano del jugadro determinado en el Juego
Carta* Dealer::pedirCarta(Mazo* mazo){
	if (!sePaso()) {
		Carta* nuevaCarta = mano->agregarCarta(mazo);
		if (nuevaCarta != nullptr) {
			mano->agregarCarta((Mazo*)&nuevaCarta);
			return nuevaCarta;
		}
	}
	else {
		std::cout << "Ya no se pueden pedir más cartas\n" << std::endl;
		return nullptr;
	}
}
//En este método se crea una copia de Dealer con su nombre y mano respectivamente
JugadorGenerico* Dealer::copia()
{
	return new Dealer(nickname, mano);
}
Mano* Dealer::getMano()
{
	return mano;
}
//Método encargado de conocer si los jugadore la cantidad de cartas en mayor o no de 21 
bool Dealer::sePaso()
{
	if (mano->getPuntos() > 21) {
		return true;
	}
	return false;
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
std::string Dealer::getNickname()
{
	return nickname;
}
void Dealer::guardarJugador(std::ofstream& file){
	file << nickname << mano;
}
JugadorGenerico* Dealer::leerDealer(std::ifstream& file)
{
	std::string nick; 
	file >> nick; 

	Mano* manoJugador = new Mano(); 
	Dealer* nuevoDealer = new Dealer(nick, manoJugador); 

	return nuevoDealer; 
}
//Método toString de la clase Dealer
//Muestra las cartas del Dealer dentro del juego
void Dealer::toString(){
	std::cout << nickname << ":\n      Mano: ";
	mano->toString();
}
