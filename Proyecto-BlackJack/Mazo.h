#pragma once
#include "Carta.h"
#include<iostream>

class Mazo {
private:
	Carta* carta[];
public:
	Mazo();
	~Mazo();
	void inicializador();
	void barajar();
	Carta* tomarCarta();
};
