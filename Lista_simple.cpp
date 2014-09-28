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

ListaSimple :: ListaSimple()
{
	primerNodo = NULL;
	ultimoNodo = NULL;
}

void ListaSimple :: llenar()
{
	int x;
	for(x = 1; x != 10 ; x++)
	{
		agregarAlFinal(x);
	}
}

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

bool ListaSimple :: estaVacia()
{
	return primerNodo == NULL;
}

void ListaSimple :: agregarAlFinal(int num)
{
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

void ListaSimple :: eliminarDelFinal()
{
	Nodos *tempo = primerNodo;
	if(estaVacia())
	{
		cout << "NO HAY ELEMENTOS EN LA LISTA" << endl;
	}
	else
	{
		while(tempo->get_siguiente() != ultimoNodo)
		{
			tempo = tempo->get_siguiente();
		}
		ultimoNodo = tempo;
		ultimoNodo->set_siguiente(NULL);
	}
}

void ListaSimple :: agregarAlFrente(int num)
{
	Nodos* temp = new Nodos(num);
	if(estaVacia())
	{
		primerNodo = ultimoNodo = temp;
	}
	else
	{
		temp->set_siguiente(primerNodo);
		primerNodo = temp;
	}
}

void ListaSimple :: eliminarDelFrente()
{
	if(estaVacia())
	{
		cout << "La lista se encuentra vacia" << endl;
	}
	else
	{
		primerNodo = primerNodo->get_siguiente();
	}
}

