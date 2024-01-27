#include <iostream>
#include "Carta.h"
#include "Mazo.h"
//Main de pruebas 
int main() {
	Carta c(0, 0, false);
	std::cout << c.getValor();
	Mazo m;
	m.inicializador();
	m.barajar();
	return 0;
}