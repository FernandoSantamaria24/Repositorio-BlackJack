#pragma once
#include"Nodo.h"

class Lista {
private:
	Nodo* inicio;
public:
	Lista();
	~Lista();
	Nodo* getInicio();
	void insertarNodoJugador(JugadorGenerico*);
	Nodo* buscaPersona(JugadorGenerico*);
	void borrarNodoJugador(JugadorGenerico*);
	bool listaVacia();
};

