#include<iostream>
#include "NodoG.h"
using namespace std;

/**
 * @brief Nodos::Nodos constructor de la clase Nodos inicializa los parametros en 0
 */
Nodos :: Nodos()
{
    this->numero = 0;
    this->siguiente = NULL;
}

/**
 * @brief Nodos::Nodos Sobrecargar el constructor para crear nodo con un valor inmediato
 * @param num valor del nodo
 */
Nodos :: Nodos(int num)
{
    this->numero = num;
    this->siguiente = NULL;
}

void Nodos :: set_numero(int num)
{
    this->numero = num;
    return;
}

void Nodos::set_siguiente(Nodos *punt)
{
    this->siguiente = punt;
    return;
}

/**
 * @brief Nodos::get_numero Obtiene valor
 * @return numero entero que indica el valor
 */
int Nodos :: get_numero()
{
    return this->numero;
}

/**
 * @brief Nodos::get_siguiente obtiene siguiente Nodos
 * devuelve un puntero que apunta hacia el siguiente nodo.
 * @return
 */
Nodos* Nodos :: get_siguiente()
{
    return this->siguiente;
}
