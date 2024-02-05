#pragma once
#include "Carta.h"
#include"Mazo.h"
#include<iostream>
class Mano {
private:
	Carta* cartas[9];
	int cant;
public:
	Mano();
	~Mano();
	Carta* agregarCarta(Mazo*);
	void limpiar();
	int getPuntos();
	int getCantidad();
	Carta* getCartaPosicion(int);
	Mano* copia();
	void guardarMano(std::ofstream&);
	static Mano* leerMano(std::ifstream&);
	void toString();
};
