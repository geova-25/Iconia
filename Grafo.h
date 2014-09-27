/*
 * Grafo.h
 *
 *  Created on: 14/09/2014
 *      Author: sebastian
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
using std::cout;
using std::endl;
#include <stdio.h>
#include <stdlib.h>
#include <string>
using std::string;

#include "Nodo.h"


#include "ListaEnlazada.h"




template <class T> class Grafo {


public:
    Grafo();
    virtual ~Grafo();
    void AgregarFilaDeAdyacencia(ListaEnlazada<T>);
    void imprimir();

private:
    ListaEnlazada<ListaEnlazada<T> > grafo;


};

#endif /* GRAFO_H_ */
