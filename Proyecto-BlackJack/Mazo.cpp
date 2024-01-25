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
//Método de tomar una carta del mazo para darsela a un jugador
//Siempre y cuando la carta aún no sea tomada por algún otro jugador
Carta* Mazo::tomarCarta()
{
    if (carta[0] != nullptr) {
        // Almacenar el puntero a la primera carta
        Carta* tomada = carta[0];

        // Desplazar las cartas restantes hacia la izquierda
        for (int i = 1; i < 51; ++i) {
            carta[i - 1] = carta[i];
        }

        // La última posición se vuelve nullptr para indicar que está vacía.
        carta[51] = nullptr;
        std::cout << "\nLa carta tomada es:\n";
        return tomada;
    }
    else {
        std::cout << "No quedan cartas en el mazo." << std::endl;
        return nullptr;
    }

}