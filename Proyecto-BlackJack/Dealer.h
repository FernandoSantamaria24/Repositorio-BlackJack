#pragma once

#include"JugadorGenerico.h"
#include "Carta.h"

class Dealer : public JugadorGenerico {
public:
	Dealer(std::string, Mano*);
	~Dealer();
	Carta* pedirCarta(Mazo*);
	JugadorGenerico* copia();
	Mano* getMano();
	bool sePaso();//Desarrolar
	void volteaSegunda(); //falta desarrollar
	std::string getNickname();
	void guardarJugador(std::ofstream&);
	static JugadorGenerico* leerDealer(std::ifstream&);
	void toString();

};
