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
	Mazo* copia();
	void guardarMazo(std::ofstream&);
	static Mazo* leerMazo(std::ifstream&);
	void toString();
};
