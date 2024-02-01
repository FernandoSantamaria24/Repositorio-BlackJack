#pragma once

#include"JugadorGenerico.h"
#include "Carta.h"

class Dealer : public JugadorGenerico {
public:
	Dealer(std::string, Mano*);
	~Dealer();
	Carta* pedirCarta(Mazo*);
	JugadorGenerico* copia();
	bool sePaso();//Desarrolar
	void volteaSegunda(); //falta desarrollar
	void toString();

};
