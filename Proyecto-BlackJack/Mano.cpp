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
void Mano::agregarCarta(Mazo* m){
	if (cant<9) {
		this->cartas[cant] = m->tomarCarta();
		cant++;
	}
	else {
		std::cout << "Ya no se pueden pedir cartas (limite completado)\n";
	}
}
//Limpia la mano para que el jugador pueda volver a jugar otra partida
//FALTA DESARROLLAR
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