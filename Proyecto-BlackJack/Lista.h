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
	bool buscarNombreJugador(std::string);
	void borrarNodoJugador(JugadorGenerico*);
	bool listaVacia();
};

