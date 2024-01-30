#include "Mano.h"
#include "Mazo.h"
//M�todo constructor sin par�metros 
Mano::Mano(){
	for (int i = 0; i < 9; i++){
		cartas[i] = nullptr;
	}
	cant = 0;
}
//Borra todas las cartas que se encuentran dentro de la mano de cada jugador
//Impidiendo que ocurra un memory leak por parte de Mano
Mano::~Mano(){
	for (int i = 0; i < 9; i++)
	{
		delete cartas[i];
	}
}
//Agrega una carta a la mano del jugador seleccionado
//Solo se pueden agregar una cantidad de 10 cartas a la mano de cada jugador
Carta* Mano::agregarCarta(Mazo* m){
	if (cant<9) {
		Carta* nuevaCarta = m->tomarCarta();
		if (nuevaCarta != nullptr) {
			cartas[cant] = nuevaCarta;
			std::cout << "Carta tomada\n";
			cant++;
			return nuevaCarta;
		}
		else {
			std::cout << "Ya no quedan cartas en el mazo\n";
			return nullptr;
		}
	}
	else {
		std::cout << "Ya no se pueden pedir cartas (limite completado)\n";
		return nullptr;
	}
}
//Limpia la mano para que el jugador pueda volver a jugar otra partida
//FALTA DESARROLLAR
//TOTALMENTE MALO
void Mano::limpiar(){
	for (int i = 0; i < 9; i++){
		if (cartas[i]!=nullptr) {
			cartas[i] = nullptr;
		}
	}
}
//Suma la cantidad de puntos que el usuario tiene hasta el momento
int Mano::getPuntos()
{
	int sum = 0;
	for (int i = 0; i < 9; i++){
		if (cartas[i]!=nullptr) {
			sum += cartas[i]->getValor();
		}
	}
	return sum;
}
int Mano::getCantidad()
{
	return cant;
}
Carta* Mano::getCartaPosicion(int posicion)
{
	if (posicion >= 0 && posicion < cant) {
		return cartas[posicion];
	}
	else {
		return nullptr;
	}
}
//M�todo para mostrar las cartas de la mano para cada jugador
void Mano::toString(){
	for (int i = 0; i < 9; i++)
	{
	 cartas[i]->toString();
	 std::cout << "     ";
	}
}
