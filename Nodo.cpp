/*
 * Nodo.cpp
 *
 *  Created on: 14/09/2014
 *      Author: sebastian
 */

#include "Nodo.h"


template <class T>
Nodo<T>::Nodo()
{
    this->elemento ;
    this->siguiente_elemento = NULL;

}
template <class T>
Nodo<T>::~Nodo() {
    // TODO Auto-generated destructor stub
}

using namespace std;
/**
 * @param
 * @return
 */


/**
 * @param
 * @return
 */
template <class T>
Nodo<T> :: Nodo(T ele)
{
    this->elemento = ele;
    this->siguiente_elemento = NULL;
}
/**
 * @param
 * @return
 */


/**
 * @param
 * @return
 */


/**
 * @param
 * @return
 */
template <class T>
void Nodo<T>:: set_elemento(T nume)
{
    this->elemento = nume;
    return;
}
/**
 * @param
 * @return
 */
template <class T>
void Nodo<T>::set_siguiente(Nodo *punt)
{
    this->siguiente_elemento = punt;
    return;
}
/**
 * @param
 * @return
 */
template <class T>
T Nodo<T> :: get_elemento()
{
    return this->elemento;
}
/**
 * @param
 * @return
 */
template <class T>
Nodo<T>* Nodo<T> :: get_siguiente()
{
    return this->siguiente_elemento;
}
