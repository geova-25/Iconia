/*
 * ListaEnlazada.cpp
 *
 *  Created on: 14/09/2014
 *      Author: sebastian
 */

#include "ListaEnlazada.h"

#include<iostream>


using namespace std;

template <class T>
 ListaEnlazada<T>:: ListaEnlazada()
{
    this->primerNodo = NULL;
    this->ultimoNodo = NULL;

}
template <class T>
ListaEnlazada<T>::~ListaEnlazada() {
    // TODO Auto-generated destructor stub
}


/**
 * @param
 * @return
 */

template <class T>
void ListaEnlazada<T>:: imprimir()
{
    if(estaVacia()){
        cout<<"No hay elementos a imprimir"<<endl;
    }
    else{
        Nodo<T>* temporal = NULL;
        temporal = this->primerNodo;
        cout << "[";
        while(temporal != NULL)
        {
            if (temporal != this->ultimoNodo){
                    cout << temporal->get_elemento()<<" , ";
            }
            else{
                cout << temporal->get_elemento()<<"]"<<endl;
            }

            temporal = temporal->get_siguiente();

        }

    }
}
/**
 * @param
 * @return
 */
template <class T>
bool ListaEnlazada<T> :: estaVacia()
{
    return this->primerNodo == NULL;
}
/**
 * @param
 * @return
 */

/*void ListaEnlazada :: agregarAlFinal(int* p)
{
    Nodo* temp = new Nodo(p);
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
}*/
/**
 * @param
 * @return
 */
template <class T>
void  ListaEnlazada<T> :: agregarAlFinal(T num)
{
    Nodo<T>* temp = new Nodo<T>(num);
    if (estaVacia())
    {
        this->primerNodo = this->ultimoNodo = temp;
    }
    else
    {
        this->ultimoNodo->set_siguiente(temp);
        this->ultimoNodo = temp;
    }

}

/**
 * @param
 * @return
 */
template <class T>
void  ListaEnlazada<T>:: eliminarDelFinal()
{
    Nodo<T> *tempo = this->primerNodo;
    if(estaVacia())
    {
        cout << "NO HAY ELEMENTOS EN LA LISTA" << endl;
    }
    else
    {
        while(tempo->get_siguiente() != this->ultimoNodo)
        {
            tempo = tempo->get_siguiente();
        }
        this->ultimoNodo = tempo;
        this->ultimoNodo->set_siguiente(NULL);
    }
}
/**
 * @param
 * @return
 */

/*void ListaEnlazada :: agregarAlFrente(int* p)
{
    Nodo* temp = new Nodo(p);
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
/**
 * @param
 * @return
 */
template <class T>
void  ListaEnlazada<T>:: eliminarDelFrente()
{
    if(estaVacia())
    {
        cout << "La lista se encuentra vacia" << endl;
    }
    else
    {
        this->primerNodo = this->primerNodo->get_siguiente();
    }
}
/**
 * @param
 * @return
 */
template <class T>
void   ListaEnlazada<T>:: vaciar()
{
    int x;
    while(this->primerNodo != this->ultimoNodo)
    {
        eliminarDelFinal();
    }
    this->primerNodo = this->ultimoNodo = NULL;
}

/**
 * @param
 * @return
 */
template <class T>
Nodo<T>*  ListaEnlazada<T>::get_primerNodo(){
    return this->primerNodo;
}
