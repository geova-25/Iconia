#ifndef NODOGRAFO_H
#define NODOGRAFO_H
#include <iostream>
using std::cout;
using std::endl;
#include <stdio.h>
#include <stdlib.h>
#include <string>
using std::string;
#include "Nodo.h"
#include "ListaEnlazada.h"

template <class T> class NodoGrafo :public  Nodo<T>
{
public:
    NodoGrafo();
    virtual~NodoGrafo();
    NodoGrafo(T);
    void set_elemento(T);
    void setListaDeAristas(ListaEnlazada<NodoGrafo<T>*> list);
    ListaEnlazada<NodoGrafo<T>*> get_listaDeAristas();
    T get_elemento();
    void set_siguiente(NodoGrafo<T>*);
    NodoGrafo<T>* get_siguiente();
    void agregarArista(NodoGrafo<T>*);
private:
    T elemento;
    NodoGrafo<T>* siguiente_elemento;
    ListaEnlazada<NodoGrafo<T>* > listaDeAristas;

};

#endif // NODOGRAFO_H
