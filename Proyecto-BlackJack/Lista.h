#pragma once
#include"Nodo.h"

class Lista {
private:
	Nodo* inicio;
public:
	Lista();
	~Lista();
	Nodo* getInicio();
	void insertarNodo(JugadorGenerico*);
	void borrarNodo(Nodo*);
	bool listaVacia();
};

