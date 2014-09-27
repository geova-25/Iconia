/*
 * ListaEnlazada.h
 *
 *  Created on: 14/09/2014
 *      Author: sebastian
 */

#ifndef LISTAENLAZADA_H_
#define LISTAENLAZADA_H_

#include "Nodo.h"
#include "Nodo.cpp"



#include <iostream>
using std::cout;
using std::endl;
#include <stdio.h>
#include <stdlib.h>
#include <string>
using std::string;


template <class T> class ListaEnlazada {
public:
    ListaEnlazada();
    virtual ~ListaEnlazada();
    void imprimir();
    void agregarAlFrente(T p );
    void eliminarDelFrente();
    void eliminarDelFinal();
    void agregarAlFinal(T num);
    void vaciar();
    bool estaVacia();
    Nodo<T>* get_primerNodo();
protected:

    Nodo<T>* primerNodo;
    Nodo<T>* ultimoNodo;
};

#endif /* LISTAENLAZADA_H_ */
