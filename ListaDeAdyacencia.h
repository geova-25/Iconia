#ifndef LISTADEADYANCENCIA_H
#define LISTADEADYANCENCIA_H

#include <iostream>
using std::cout;
using std::endl;
#include <stdio.h>
#include <stdlib.h>
#include <string>
using std::string;
#include "ListaEnlazada.h"

#include "NodoGrafo.h"

#include "NodoGrafo.cpp"


template <class T> class ListaDeAdyacencia
{
public:
    ListaDeAdyacencia();
    virtual ~ListaDeAdyacencia();
    void imprimir();
    void agregarAlFrente(T p );
    void eliminarDelFrente();
    void eliminarDelFinal();
    void agregarAlFinal(T num);
    void vaciar();
    bool estaVacia();
    NodoGrafo<T>* get_primerNodo();
    void relacionar(T , T);
protected:

    NodoGrafo<T>* primerNodo;
    NodoGrafo<T>* ultimoNodo;
};

#endif // LISTADEADYANCENCIA_H
