#pragma once
#include"Nodo.h"
#include<fstream>

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
	Nodo* siguienteJugador();
	void guardarLista(std::ofstream);
	void leerLista(std::ifstream);
	bool listaVacia(); 
};

