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
	virtual Carta* pedirCarta();
	virtual bool sePaso();
};
