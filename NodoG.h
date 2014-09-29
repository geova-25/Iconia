#ifndef NODO_H
#define NODO_H

#include<iostream>
using namespace std;


class Nodos
{
    private:
        int numero;
        Nodos *siguiente;
    public:
        Nodos();
        Nodos(int);
        void set_numero(int);
        void set_siguiente(Nodos*);
        int get_numero();
        Nodos* get_siguiente();
};


#endif // NODO_H
