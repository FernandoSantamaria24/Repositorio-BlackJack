#include <iostream>
#include "Juego.h"
//Main de pruebas 
int main() {
    int opcion;
    Juego juegoNuevo;
    do {
        // Pantalla inicial
        std::cout << "1) Nuevo Juego: Inicia un juego nuevo de Blackjack\n";
        std::cout << "2) Cargar Partida: Carga una partida guardada de un juego previo de Blackjack\n";
        std::cout << "3) Salir: Termina el programa\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            system("cls");
            juegoNuevo.jugar();
            break;
        case 2:
            std::cout << "CARGANDO JUEGO PASADO\n";
            break;
        case 3:
            std::cout << "¡GRACIAS POR PARTICIPAR!\n";
            break;
        default:
            system("cls");
            std::cout << "Opcion no valida. Intente de nuevo.\n";
        }

    } while (opcion != 3);

    return 0;
}