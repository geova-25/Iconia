#include<iostream>
#include "NodoG.h"
using namespace std;

Nodos :: Nodos()
{
    this->numero = 0;
    this->siguiente = NULL;
}

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

int Nodos :: get_numero()
{
    return this->numero;
}

Nodos* Nodos :: get_siguiente()
{
    return this->siguiente;
}
