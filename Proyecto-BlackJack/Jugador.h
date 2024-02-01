#pragma once
#include"JugadorGenerico.h"
#include "Carta.h"
#include"Mazo.h"

class Jugador : public JugadorGenerico {
public:
	Jugador(std::string, Mano*);
	~Jugador();
	Carta* pedirCarta(Mazo*);
	JugadorGenerico* copia();
	bool sePaso();//Desarrolar
	void toString();
};