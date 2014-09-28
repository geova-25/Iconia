/*
 * Lista_simple.h
 *
 *  Created on: 03/08/2014
 *      Author: giovanni
 */

#ifndef LISTA_SIMPLE_H_
#define LISTA_SIMPLE_H_
/*
 * Lista_simple.cpp
 *
 *  Created on: 01/08/2014
 *      Author: giovanni
 */

#include<iostream>
#include "Nodo.h"
#include "Lista_simple.h"
using namespace std;

class ListaSimple
{
	private:
		Nodos* primerNodo;
		Nodos* ultimoNodo;

	public:
		ListaSimple();
		void llenar();
		void imprimir();
		void agregarAlFrente(int);
		void agregarAlFinal(int);
		void eliminarDelFrente();
		void eliminarDelFinal();
		bool estaVacia();
		Nodos* get_primerNodo();
};



#endif /* LISTA_SIMPLE_H_ */
