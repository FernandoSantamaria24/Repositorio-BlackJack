#pragma once
#include<iostream>

class Carta {
private:
	int valor;
	int palo;
	bool bocaAbajo;
public:
	Carta();
	Carta(int, int, bool);
	~Carta();
	int getValor();
	int getPalo();
	void setValor(int);
	void setPalo(int);
	void voltear(); //falta desarrollar
};
