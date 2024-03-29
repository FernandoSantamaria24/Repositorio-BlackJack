#include "Mazo.h"
#include "Carta.h"
#include "Mano.h"
//Constructor sin par�metros de la clase Mazo
Mazo::Mazo(){
    for (int i = 0; i < tam; i++)
    {
        carta[i] = new Carta();
    }
}
//Destructor de clase Mazo
Mazo::~Mazo(){
    for (int i = 0; i < tam; i++) {

        delete carta[i];
    }
}


//M�todo encargado de Inicializar las cartas de una partida y agregarlas al mazo de la misma partida
void Mazo::inicializador(){
    int pos = 0;

    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 4; j++) {
                carta[pos]->setValor(i);
                carta[pos]->setPalo(j);
                carta[pos]->voltear();
                pos++;
        }
    }
}
//M�todo encarga de revolver las cartas en cada inicio de juego
void Mazo::barajar(){
    Carta* tC[tam]; //vector  burbuja
    int contRand = 52, numAl;

    for (int i = 0; i < tam; i++) { 

        numAl = rand() % contRand; //rand revolver

        tC[i] = carta[numAl]; 

        for (int j = numAl; j < contRand - 1; j++) {
            carta[j] = carta[j + 1];

        }
        carta[contRand - 1] = new Carta(); // reinicia  la ultima carta del vector

        contRand--;
    }

    for (int i = 0; i < tam; i++) { 

        carta[i] = tC[i];

    }
}
//M�todo de tomar una carta del mazo para darsela a un jugador
//Siempre y cuando la carta a�n no sea tomada por alg�n otro jugador
Carta* Mazo::tomarCarta(){
    if (carta[0] != nullptr) {
        // Almacenar el puntero a la primera carta
        Carta* tomada = carta[0];

        // Desplazar las cartas restantes hacia la izquierda
        for (int i = 1; i < 51; ++i) {
            carta[i - 1] = carta[i];
        }

        // La �ltima posici�n se vuelve nullptr para indicar que est� vac�a.
        carta[51] = nullptr;
        return tomada;
    }
    else {
        std::cout << "No quedan cartas en el mazo." << std::endl;
        return nullptr;
    }

}
//M�todo copia, lo que hace es recorrer el vector hasta un tope de 51, donde se le asigna a mazoCopia
//El valor de la carta con su copia, lo que nos permitira no perder nunca sus valores
Mazo* Mazo::copia()
{
    Mazo* mazoCopia = new Mazo();

    for (int i = 0;i < tam;i++) {
        mazoCopia->carta[i] = carta[i]->copia();
    }

    return mazoCopia; 
}
//Metodo utilizado para guardar mazo
void Mazo::guardarMazo(std::ofstream& file)
{
    //Se recorre el vector de mazo para ir guardando cada carta del mazo
    for (int i = 0;i < tam;i++) {
        if (carta[i]!=nullptr) {
            carta[i]->guardarCarta(file);
        }

    }
}
//Metodo utilizado para leer mazo
Mazo* Mazo::leerMazo(std::ifstream& file)
{
    Mazo* nuevoMazo = new Mazo();
    //Se recorre el vector de mazo para ir leyendo cada carta del mazo
    for (int i = 0;i < tam;i++) {
        Carta* nuevaCarta = Carta::leerCarta(file);
        if (nuevaCarta != nullptr) {
            nuevoMazo->carta[i] = nuevaCarta;
        }
    }
    return nuevoMazo;
}
