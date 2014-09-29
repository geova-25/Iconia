#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include<iostream>
#include "NodoG.h"
#include "Lista_simple.h"
using namespace std;

class ListaSimple
{
    private:
        Nodos* primerNodo;
        Nodos* ultimoNodo;
        int counter;

    public:
        ListaSimple();
        void llenar();
        void imprimir();
        void agregarAlFrente(int);
        void agregarAlFinal(int);
        void eliminarDelFrente();
        void eliminarDelFinal();
        bool estaVacia();
        int counterNodos();
        Nodos* get_primerNodo();
};


#endif // LISTA_SIMPLE_H
