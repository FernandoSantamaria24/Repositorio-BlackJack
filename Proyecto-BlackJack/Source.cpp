#include <iostream>
#include "Juego.h"
//Main de pruebas 
int main() {
    int opcion;
    Juego juegoNuevo;
    do {
        // Pantalla inicial
        std::cout << "1) Nuevo Juego: Inicia un juego nuevo de Blackjack\n" << std::endl;
        std::cout << "2) Cargar Partida: Carga una partida guardada de un juego previo de Blackjack\n" << std::endl;
        std::cout << "3) Salir: Termina el programa\n";
        std::cout << "Seleccione una opcion: " << std::endl;
        try {
            std::cin >> opcion;
            if (std::cin.fail()) {
                system("cls");
                throw std::invalid_argument("Opcion invalida. Por favor, ingrese un numero.");
            }
        switch (opcion) {
        case 1:
            system("cls");
            juegoNuevo.jugar();
            break;
        case 2:
            system("cls");
            std::cout << "CARGANDO PARTIDA...\n" << std::endl;
            juegoNuevo.leerJuego();
            break;
        case 3:
            system("cls");
            std::cout << "-------------------------¡GRACIAS POR PARTICIPAR!\n" << std::endl;
            break;
        default:
            system("cls");
            std::cout << "Opcion no valida. Intente de nuevo.\n" << std::endl;
        }
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            // Limpiar el estado de error de std::cin y descartar la entrada incorrecta
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (opcion != 3);
    return 0;
}