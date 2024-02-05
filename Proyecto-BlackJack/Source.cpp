#include <iostream>
#include "Juego.h"
//Main de pruebas 
int main() {
    int opcion;
    Mazo* mazoNuevo = new Mazo();
    Juego* juegoNuevo=new Juego(mazoNuevo);
    do {
        // Pantalla inicial
        std::cout << "1) Nuevo Juego: Inicia un juego nuevo de Blackjack\n" << std::endl;
        std::cout << "2) Cargar Partida: Carga una partida guardada de un juego previo de Blackjack\n" << std::endl;
        std::cout << "3) Salir: Termina el programa\n";
        std::cout << "Seleccione una opcion: " << std::endl;
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            system("cls");
            juegoNuevo->jugar();
            break;
        case 2:
            system("cls");
            std::cout << "CARGANDO PARTIDA...\n" << std::endl;
            break;
        case 3:
            system("cls");
            std::cout << "-------------------------¡GRACIAS POR PARTICIPAR!\n" << std::endl;
            break;
        default:
            system("cls");
            std::cout << "Opcion no valida. Intente de nuevo.\n" << std::endl;
        }

    } while (opcion != 3);
    delete juegoNuevo;
    return 0;
}