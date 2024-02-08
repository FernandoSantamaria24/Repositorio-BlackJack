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
	const int limiteCartas = 9;
	if (cant < limiteCartas) {
		Carta* nuevaCarta = m->tomarCarta();

		if (nuevaCarta != nullptr) {
			cartas[cant] = nuevaCarta;
			cant++;
			return nullptr;
		}
	}
	else {
		std::cout << "Error: Se alcanz� el l�mite de cartas en la mano\n" << std::endl;
	}

	return nullptr;
}
//Limpia la mano para que el jugador pueda volver a jugar otra partida
//Se vuelve a rellenar con valores de tipo nullptr
void Mano::limpiar(){
	for (int i = 0; i < cant; ++i) {
			delete cartas[i]; // Elimina la carta actual si existe
			cartas[i] = nullptr; // Asigna nullptr para indicar que no hay carta en esa posici�n
	}
	cant = 0;
}
//Suma la cantidad de puntos que el usuario tiene hasta el momento
int Mano::getPuntos(){
	int sum = 0;
	for (int i = 0; i < 9; i++){
		if (cartas[i]!=nullptr) {
			sum += cartas[i]->getValor();
		}
	}
	return sum;
}
//Este m�todo nos permite retornar la cantidad de cartas que tiene cada mano
int Mano::getCantidad()
{
	return cant;
}
//Este m�todo nos permite saber la posicion de cierta carta en especifico, para as� poder interactuar
//Con esa carta y utilizarla como mejor nos convenga
Carta* Mano::getCartaPosicion(int posicion)
{
	if (posicion >= 0 && posicion < cant) {
		return cartas[posicion];
	}
	else {
		return nullptr;
	}
}
//M�todo copia, lo que hace es recorrer el vector hasta un tope de 9 cartas por mano, donde se le asigna a manoCopia
//El valor de la carta con su copia, lo que nos permitira no perder nunca sus valores
Mano* Mano::copia()
{
	Mano* manoCopia = new Mano();

	for (int i = 0;i < 9;i++) {
		manoCopia->cartas[i] = cartas[i]->copia(); 
	}

	return manoCopia;
}
void Mano::guardarMano(std::ofstream& file)
{
	file << cant << "\n";

	for (int i = 0;i < cant;i++) {
		cartas[i]->guardarCarta(file);
	}
}
Mano* Mano::leerMano(std::ifstream& file)
{
	int cantCartas;
	file >> cantCartas;

	Mano* nuevaMano = new Mano();

	for (int i = 0;i < cantCartas;i++) {
		Carta* nuevaCarta = Carta::leerCarta(file);
		if (nuevaCarta != nullptr) {
			nuevaMano->cartas[i] = nuevaCarta;
			nuevaMano->cant++;
		}
	}
	return nuevaMano;
}
//M�todo para mostrar las cartas de la mano para cada jugador
void Mano::toString(){
	for (int i = 0; i < cant; i++){
	 cartas[i]->toString();
	 std::cout << "  ";
	}
}
