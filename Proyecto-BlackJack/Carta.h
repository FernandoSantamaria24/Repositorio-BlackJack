#pragma once
#include<iostream>

class Carta {
private:
	int valor;
	int palo;
	bool bocaAbajo;
public:
	Carta(int, int, bool);
	~Carta();
	int getValor();
	int getPalo();
	void setValor(int);
	void voltear(); //falta desarrollar
};
