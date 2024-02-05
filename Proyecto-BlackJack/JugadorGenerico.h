#pragma once
#include<iostream>
#include "Carta.h"
#include "Mano.h"

//falta desarrollar, le falta la mano
class JugadorGenerico {
protected:
	std::string nickname;
	Mano* mano;
public:
	JugadorGenerico();
	JugadorGenerico(std::string, Mano*);
	~JugadorGenerico();
	Mano* getMano();
	virtual JugadorGenerico* copia()=0;
	virtual Carta* pedirCarta(Mazo*)=0;
	virtual bool sePaso()=0;
	virtual std::string getNickname() = 0;
	virtual void toString()=0;
};
