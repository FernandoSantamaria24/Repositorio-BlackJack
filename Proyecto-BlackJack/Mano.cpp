#include "Mano.h"
#include "Mazo.h"
//Método constructor sin parámetros 
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
			std::cout << "Carta tomada\n" << std::endl;
			cant++;
			return nuevaCarta;
		}
		else {
			std::cout << "Ya no quedan cartas en el mazo\n" << std::endl;
			return nullptr;
		}
	}
	else {
		std::cout << "Ya no se pueden pedir cartas (limite completado)\n" << std::endl;
		return nullptr;
	}
}
//Limpia la mano para que el jugador pueda volver a jugar otra partida
//Se vuelve a rellenar con valores de tipo nullptr
void Mano::limpiar(){
	for (int i = 0; i < 9; ++i) {
		if(cartas[i]!=nullptr) {
			delete cartas[i]; // Elimina la carta actual si existe
			cartas[i] = nullptr; // Asigna nullptr para indicar que no hay carta en esa posición
		}
	
	}
	cant = 0;
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
//Este método nos permite retornar la cantidad de cartas que tiene cada mano
int Mano::getCantidad()
{
	return cant;
}
//Este método nos permite saber la posicion de cierta carta en especifico, para así poder interactuar
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
//Método copia, lo que hace es recorrer el vector hasta un tope de 9 cartas por mano, donde se le asigna a manoCopia
//El valor de la carta con su copia, lo que nos permitira no perder nunca sus valores
Mano* Mano::copia()
{
	Mano* manoCopia = new Mano();

	for (int i = 0;i < 9;i++) {
		manoCopia->cartas[i] = cartas[i]->copia(); 
	}

	return manoCopia;
}
//Método para mostrar las cartas de la mano para cada jugador
void Mano::toString(){
	for (int i = 0; i < 9; i++)
	{
	 cartas[i]->toString();
	 std::cout << "    ||    ";
	}
}
