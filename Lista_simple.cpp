#include<iostream>
#include "NodoG.h"
#include "Lista_simple.h"
using namespace std;

/**
 * @brief ListaSimple::ListaSimple  constructor de la clase
 * Inicializa los atributos para evitar problemas.
 */
ListaSimple :: ListaSimple()
{
    primerNodo = NULL;
    ultimoNodo = NULL;
    counter = 0;
}


void ListaSimple :: llenar()
{
    int x;
    for(x = 1; x != 10 ; x++)
    {
        agregarAlFinal(x);
    }
}

/**
 * @brief ListaSimple::imprimir imprime los elementos contenidos
 */
void ListaSimple :: imprimir()
{
    Nodos* temporal = NULL;
    temporal = primerNodo;
    while(temporal != NULL)
    {
        cout << temporal->get_numero() << endl;
        temporal = temporal->get_siguiente();
    }
}

/**
 * @brief ListaSimple::estaVacia retorna booleano
 * Determina si la lista esta vacia o contiene elementos compara el primer elemento con nulo
 * @return booleano indicando si esta o no vacia
 */
bool ListaSimple :: estaVacia()
{
    return primerNodo == NULL;
}

/**
 * @brief ListaSimple::agregarAlFinal agrega un elemento nuevo a una lista
 * Sirve para agregar nuevos objetos a la lista crea un nuevo nodo y si esta vacia se lo asigna al primer y ultimo
 * nodo, de otra manera crea un nuevo nodo y se lo asigna como siguiente nodo al ultimo
 * @param num entero con valor del objeto de la lista nuevo
 */
void ListaSimple :: agregarAlFinal(int num)
{
    counter ++;
    Nodos* temp = new Nodos(num);
    if (estaVacia())
    {
        this->primerNodo = this->ultimoNodo = temp;
    }
    else
    {
        this->ultimoNodo->set_siguiente(temp);
        this->ultimoNodo = temp;
    }
    return;
}




Nodos* ListaSimple :: get_primerNodo(){
    return this->primerNodo;
}



/**
 * @brief ListaSimple::counterNodos cuenta cuantos nodos contiene una lista simple
 * @return counter el entero con el numero de nodos
 */
int ListaSimple :: counterNodos(){
    return counter;
}
