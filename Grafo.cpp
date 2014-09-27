/*
 * Grafo.cpp
 *
 *  Created on: 14/09/2014
 *      Author: sebastian
 */

#include "Grafo.h"

#include<iostream>


using namespace std;

template <class T>
Grafo<T>::Grafo() {


    // TODO Auto-generated constructor stub


}
template <class T>
Grafo<T>::~Grafo() {

    // TODO Auto-generated destructor stub
}

template <class T>
void Grafo<T>::AgregarFilaDeAdyacencia(ListaEnlazada<T> list){
    grafo.agregarAlFinal(list);


}

template <class T>
void Grafo<T>::imprimir(){
    Nodo<ListaEnlazada<T> >* actual;
    actual = grafo.get_primerNodo();
        if(grafo.estaVacia())
            {
                cout << "NO HAY ELEMENTOS EN EL GRAFO" << endl;
            }
        else
            {
                while(actual!= NULL)
                {
                    actual->get_elemento().imprimir();
                    actual = actual->get_siguiente();
                }
            }
}


