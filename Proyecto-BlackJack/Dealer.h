#pragma once

#include"JugadorGenerico.h"
#include "Carta.h"

class Dealer : public JugadorGenerico {
public:
	Dealer(std::string, Mano*);
	~Dealer();
	Carta* pedirCarta(); //falta desarrollar
	void volteaSegunda(); //falta desarrollar

};
