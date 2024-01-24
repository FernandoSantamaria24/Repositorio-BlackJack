#pragma once
#include "Carta.h"
#include<iostream>
class Mano {
private:
	Carta* cartas[];
public:
	Mano();
	~Mano();
	void agregarCarta(Mano*);
	void limpiar();
	int getPuntos();
};
