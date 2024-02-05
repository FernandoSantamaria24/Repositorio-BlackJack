#pragma once
#include "Mazo.h"
#include "Lista.h"
class Juego {
private:
	Mazo* baraja;
	Lista listaJugadores;
public:
	Juego(Mazo*);
	~Juego();
	bool ingresoJugadores();
	void jugar();
	void toString();
};
