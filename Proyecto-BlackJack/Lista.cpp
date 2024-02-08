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
//Método que retorna la primer posición de la clase lista
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
//Método que nos permite buscar un jugador en especifico
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
//Método encargado de buscar la repeticion de nombres y conocer si alguno de los ingresados es igual a alguno de la lista
//Si dentro de la lista el nombre es igual retorna un valor de true
bool Lista::buscarNombreJugador(std::string jugadorNombre)
{
	Nodo* actual = inicio;
	while (actual != nullptr) {
		if (actual->dato->getNickname()==jugadorNombre) {//Verifica si existe algún nombre igual al del usario ingresado
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
void Lista::guardarLista()
{
	Nodo* aux = inicio; 
	std::ofstream file; 
	file.open("ListaJugadores.txt", std::ios::out);  

	if (file.is_open()) {
		while (aux != nullptr) {
			aux->dato->guardarJugador(file);
			aux = aux->next;
		}
	}
	file.close();
}
void Lista::leerLista()
{
	//Aun falta retocar un poco mas el metodo
	JugadorGenerico* aux = nullptr; 
	std::string tipo;
	std::string buffer;
	std::ifstream file;
	file.open("ListaJugadores.txt", std::ios::in); 

	if (file.is_open()) {
		while (!file.eof()) {
			std::getline(file, tipo, '|');
			if (tipo == "Jugador") {
				aux = Jugador::leerJugador(file);
			}
			if (tipo == "Dealer") {
				aux = Dealer::leerJugador(file);
			}
			if (file.eof()) {
				break;
			}
			if (aux != NULL) {
				insertarNodoJugador(aux);
			}
			//while (std::getline(file, buffer)) {
			//	std::istringstream linea{ buffer };
			//	std::string nombre;
			//	std::getline(linea, nombre);

			//	Mano* manoJugador = aux->dato->getMano()->leerMano(file);
			//	JugadorGenerico* nuevoJugador = aux->dato->leerJugador(file)/*new Jugador(nombre, manoJugador)*/; 
			//	insertarNodoJugador(nuevoJugador);
			//	aux = aux->next;
			//}
		}
	}	
	file.close();
}
//Método que nos permite saber si la lista ya tiene o no algun elemento ya creado
bool Lista::listaVacia()
{
	return (inicio == NULL);
}