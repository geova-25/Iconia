/*
 * Nodo.h
 *
 *  Created on: 14/09/2014
 *      Author: sebastian
 */

#ifndef NODO_H_
#define NODO_H_



#include <iostream>
using std::cout;
using std::endl;
#include <stdio.h>
#include <stdlib.h>
#include <string>
using std::string;


template <class T> class Nodo {
public:
    Nodo();
    virtual ~Nodo();
    Nodo(T);
    void set_elemento(T);
    T get_elemento();
    void set_siguiente(Nodo<T>*);
    Nodo<T>* get_siguiente();
protected:
    T elemento;

    Nodo<T>* siguiente_elemento;
    //Nodo * anterior_elemento;
};

#endif /* NODO_H_ */
