#include "Mazo.h"
#include "Carta.h"
#include "Mano.h"
//Constructor sin pa�rametros de la clase Mazo
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
    Carta* tC[tam]; //vector para metodo burbuja
    int contRand = 52, numAl;

    for (int i = 0; i < tam; i++) { 

        numAl = rand() % contRand; //aleatorio para revolver

        tC[i] = carta[numAl]; 

        for (int j = numAl; j < contRand - 1; j++) {
            carta[j] = carta[j + 1];

        }
        carta[contRand - 1] = new Carta(); //elimina (o reinicia mejor dicho) la ultima carta del vector, ya que ahora que todas se movieron, la ultima sobra

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
        std::cout << "\nLa carta tomada es:\n";
        return tomada;
    }
    else {
        std::cout << "No quedan cartas en el mazo." << std::endl;
        return nullptr;
    }

}
//ToString de prueba para conocer si la cartas son ingresadas al mazo
//MAL HECHO UTILIZADO SOLO PARA CUESTIONES DE PRUEBA
void Mazo::toString()
{
    for (int i = 0; i < tam; i++)
    {
        std::cout << "Carta #"<<i << "\n";
        std::cout << "Valor: " << carta[i]->getValor() << "   ";
        std::cout << "Palo: " << carta[i]->getPalo() << "  ";;
        std::cout << "Lado: " << carta[i]->getBocaAbajo() << "\n  ";;
    }
}
