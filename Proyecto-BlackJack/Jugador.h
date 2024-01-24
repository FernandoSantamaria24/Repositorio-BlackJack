#pragma once
#include"JugadorGenerico.h"
#include "Carta.h"

class Jugador : public JugadorGenerico {
public:
	Jugador(std::string, Mano*);
	~Jugador();
	Carta* pedirCarta(); //Falta desarrollar

};