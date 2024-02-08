#pragma once
#include"Nodo.h"
#include<fstream>
#include<sstream>
#include<string>

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
	void guardarLista();
	void leerLista();
	bool listaVacia(); 
};

