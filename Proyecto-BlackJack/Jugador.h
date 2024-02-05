#pragma once
#include"JugadorGenerico.h"
#include "Carta.h"
#include"Mazo.h"

class Jugador : public JugadorGenerico {
public:
	Jugador(std::string, Mano*);
	~Jugador();
	Carta* pedirCarta(Mazo*);
	Mano* getMano();
	JugadorGenerico* copia();
	bool sePaso();//Desarrolar
	std::string getNickname();
	void guardarJugador(std::ofstream&);
	static JugadorGenerico* leerJugador(std::ifstream&);
	void toString();
};