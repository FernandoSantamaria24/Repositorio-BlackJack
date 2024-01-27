#pragma once
#include "Carta.h"
#include<iostream>
#define tam 52

class Mazo {
private:
	Carta* carta[tam];
public:
	Mazo();
	~Mazo();
	void inicializador();
	void barajar();
	Carta* tomarCarta();
	void toString();
};
