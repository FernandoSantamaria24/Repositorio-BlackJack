#pragma once
#include "Mazo.h"
#include "Lista.h"
#include<fstream>
class Juego {
private:
	Mazo baraja;
	Lista listaJugadores;
public:
	Juego();
	~Juego();
	bool ingresoJugadores();
	void verificacion(Nodo*);
	void limpiarJugadoresActual();
	void jugar();
	void toString();
	void guardarJuego();
	void leerJuego();
};
