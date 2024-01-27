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
	bool getBocaAbajo();
	void setValor(int);
	void setPalo(int);
	void setBocaAbajo(bool);
	void voltear(); //falta desarrollar
};
