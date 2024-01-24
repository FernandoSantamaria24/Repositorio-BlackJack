#pragma once
#include "Carta.h"
#include<iostream>
class Mano {
private:
	Carta* cartas[9];
	int cant;
public:
	Mano();
	~Mano();
	void agregarCarta(Mano*);
	void limpiar();
	int getPuntos();
};
