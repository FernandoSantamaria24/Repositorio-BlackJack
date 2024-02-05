#include "Mazo.h"
#include "Carta.h"
#include "Mano.h"
//Constructor sin parámetros de la clase Mazo
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

//Método encargado de Inicializar las cartas de una partida y agregarlas al mazo de la misma partida
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
//Método encarga de revolver las cartas en cada inicio de juego
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
//Método de tomar una carta del mazo para darsela a un jugador
//Siempre y cuando la carta aún no sea tomada por algún otro jugador
Carta* Mazo::tomarCarta(){
    if (carta[0] != nullptr) {
        // Almacenar el puntero a la primera carta
        Carta* tomada = carta[0];

        // Desplazar las cartas restantes hacia la izquierda
        for (int i = 1; i < 51; ++i) {
            carta[i - 1] = carta[i];
        }

        // La última posición se vuelve nullptr para indicar que está vacía.
        carta[51] = nullptr;
        return tomada;
    }
    else {
        std::cout << "No quedan cartas en el mazo." << std::endl;
        return nullptr;
    }

}
//Método copia, lo que hace es recorrer el vector hasta un tope de 51, donde se le asigna a mazoCopia
//El valor de la carta con su copia, lo que nos permitira no perder nunca sus valores
Mazo* Mazo::copia()
{
    Mazo* mazoCopia = new Mazo();

    for (int i = 0;i < tam;i++) {
        mazoCopia->carta[i] = carta[i]->copia();
    }

    return mazoCopia; 
}
//ToString de prueba para conocer si la cartas son ingresadas al mazo
//MAL HECHO UTILIZADO SOLO PARA CUESTIONES DE PRUEBA
void Mazo::toString()
{
    for (int i = 0; i < tam; i++)
    {
        std::cout << "Carta #"<<i << "\n";
        std::cout << "Valor: " << carta[i]->getValor() << "   " << std::endl;
        std::cout << "Palo: " << carta[i]->getPalo() << "  " << std::endl;
        std::cout << "Lado: " << carta[i]->getBocaAbajo() << "\n  " << std::endl;
    }
}
