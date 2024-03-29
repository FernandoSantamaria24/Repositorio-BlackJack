#include "Lista.h"
//Constructor de la clase Lista
Lista::Lista()
{
	inicio = nullptr;
}

//Destructor de la clase Lista
Lista::~Lista()
{
	//En este metodo se utiliza un nodo auxiliar que se iguala a inicio, luego con un ciclo while recorremos la lista hasta que
	//auxiliar llegue al final, y por cada salto que vaya haciendo, se va liberando la memoria y eliminando la lista anterior.
	Nodo* aux = inicio;
	while (aux != nullptr) {
		inicio = inicio->next;
		delete aux;
		aux = inicio;
	}
}
//M�todo que retorna la primer posici�n de la clase lista
Nodo* Lista::getInicio()
{
	return inicio;
}

void Lista::insertarNodoJugador(JugadorGenerico* jugador)
{
	//En este metodo se utiliza un nodo auxiliar y ademas se utiliza el metodo de listaVacia, luego de hacer las comparaciones
	//se recorren las listas hasta donde lo desee el usuario y de paso se le va asignando un jugador por cada nodo que se vaya a utilizar.
	Nodo* aux = inicio;
	if (listaVacia()) {
		inicio = new Nodo;
		inicio->dato = jugador;
		inicio->next = nullptr;
	}
	else {
		Nodo* tmp = inicio;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = new Nodo;
		tmp->next->dato = jugador;
		tmp->next->next = nullptr;
	}
}
//M�todo que nos permite buscar un jugador en especifico
Nodo* Lista::buscaPersona(JugadorGenerico* jugador)
{
	Nodo* actual = inicio;

	while (actual != nullptr) {
		if (actual->dato == jugador) {
			return actual;
		}
		actual = actual->next;
	}
	return nullptr;
}
//M�todo encargado de buscar la repeticion de nombres y conocer si alguno de los ingresados es igual a alguno de la lista
//Si dentro de la lista el nombre es igual retorna un valor de true
bool Lista::buscarNombreJugador(std::string jugadorNombre)
{
	Nodo* actual = inicio;
	while (actual != nullptr) {
		if (actual->dato->getNickname()==jugadorNombre) {//Verifica si existe alg�n nombre igual al del usario ingresado
			return true;
		}
		actual = actual->next;
	}
	return false;
}

void Lista::borrarNodoJugador(JugadorGenerico* Jugador)
{
	//En este metodo se utilizan 2 Nodos temporales para realizar el corrimiento de la lista, esto se debe a la comparacion constante
	//que se tiene que ir realizando para poder borrar lo que se desea sin perder los datos/lista del todo.
	Nodo* tmp = buscaPersona(Jugador);
	Nodo* tmp2 = inicio;

	if (tmp == inicio) {
		inicio = inicio->next;
		delete tmp;
	}
	while (tmp2->next != tmp) {
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp->next;
	delete tmp;
}
// Si la partida es continuada con los mismos jugadores limpia la mano de cada uno de ellos
void Lista::limpiarManoJugadores(){
	Nodo* actual = inicio;
		//Mientras se encuentre un jugador en la lista se le limpia la mano actual
		while (actual != nullptr) {
			actual->dato->getMano()->limpiar();
			actual = actual->next;
		}
}
//Metodo para guardar la lista de jugadores
void Lista::guardarLista(std::ofstream& file)
{
	//Se hace una verificacion del tipo de jugador que va a llegar, y dependiendo del tipo se guarda
	//en jugador o dealer
	Nodo* aux = inicio;
	while (aux!=nullptr) {
		JugadorGenerico* jugador = aux->dato;
		if (dynamic_cast<Jugador*>(jugador)) {
			file << "Jugador\n";
			jugador->guardarJugador(file);
		}
		else if (dynamic_cast<Dealer*>(jugador)) {
			file << "Dealer\n";
			jugador->guardarJugador(file);
		}
		aux = aux->next;
	}
}
//Metodo utilizado para leer la lista de jugadores
void Lista::leerLista(std::ifstream& file)
{ 
	//En este metodo se utiliza la variable para verificar el tipo a leer, ya sea jugador o dealer
	std::string tipo; 
	while (file>>tipo){
		if (tipo == "Jugador") {
			JugadorGenerico* jugador = Jugador::leerJugador(file);
			if (jugador != nullptr) {
				insertarNodoJugador(jugador);
			}
		}
		else if (tipo == "Dealer") {
			JugadorGenerico* jugadorDealer = Dealer::leerJugador(file);
			if (jugadorDealer != nullptr) {
				insertarNodoJugador(jugadorDealer);
			}
		}
	}
}
//M�todo que nos permite saber si la lista ya tiene o no algun elemento ya creado
bool Lista::listaVacia()
{
	return (inicio == NULL);
}