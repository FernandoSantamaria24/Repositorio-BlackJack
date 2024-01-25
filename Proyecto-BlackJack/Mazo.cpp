#include "Mazo.h"
#include "Carta.h"
#include "Mano.h"

Mazo::Mazo()
{
}

Mazo::~Mazo()
{
	delete[] carta;
}

void Mazo::inicializador()
{

}

void Mazo::barajar()
{
}
//M�todo de tomar una carta del mazo para darsela a un jugador
//Siempre y cuando la carta a�n no sea tomada por alg�n otro jugador
Carta* Mazo::tomarCarta()
{
    if (carta[0] != nullptr) {
        // Almacenar el puntero a la primera carta
        Carta* tomada = carta[0];

        // Desplazar las cartas restantes hacia la izquierda
        for (int i = 1; i < 51; ++i) {
            carta[i - 1] = carta[i];
        }

        // La �ltima posici�n se vuelve nullptr para indicar que est� vac�a.
        carta[51] = nullptr;
        std::cout << "\nLa carta tomada es:\n";
        return tomada;
    }
    else {
        std::cout << "No quedan cartas en el mazo." << std::endl;
        return nullptr;
    }

}