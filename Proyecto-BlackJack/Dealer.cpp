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
	}
	else {
		std::cout << "Ya no se pueden pedir m�s cartas\n" << std::endl;
		return nullptr;
	}
}
//En este m�todo se crea una copia de Dealer con su nombre y mano respectivamente
JugadorGenerico* Dealer::copia()
{
	return new Dealer(nickname, mano);
}
Mano* Dealer::getMano()
{
	return mano;
}
//M�todo encargado de conocer si los jugadore la cantidad de cartas en mayor o no de 21 
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
//Metodo utilizado para guardar al dealer
void Dealer::guardarJugador(std::ofstream& file){
	file << "Dealer" << nickname << '\n'; 
	mano->guardarMano(file); 
}
//Metodo utilizado para leer al dealer
JugadorGenerico* Dealer::leerJugador(std::ifstream& file)
{
	std::string nick; 
	file >> nick; 
	//Se crea una mano con los valores ya guardados y se crea un nuevo dealer con los valores de la mano guardada
	Mano* manoJugador = Mano::leerMano(file); 
	Dealer* nuevoDealer = new Dealer(nick, manoJugador);  

	return nuevoDealer; 
}
//M�todo toString de la clase Dealer
//Muestra las cartas del Dealer dentro del juego
void Dealer::toString(){
	std::cout << nickname << ":    ";
	mano->toString();
}
