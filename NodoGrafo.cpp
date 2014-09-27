#include "NodoGrafo.h"


template <class T>
NodoGrafo<T>::NodoGrafo()
{

}
template <class T>
NodoGrafo<T>::NodoGrafo(T ele)
{
   this->elemento = ele;

}
template <class T>
NodoGrafo<T>::~NodoGrafo()
{

}

template <class T>
void NodoGrafo<T>::set_elemento(T ele){
    this->elemento = ele;
}
template <class T>
void NodoGrafo<T>::setListaDeAristas(ListaEnlazada<NodoGrafo<T>*> list){
    this->listaDeAristas = list;
}
template <class T>
T NodoGrafo<T> :: get_elemento(){
    return this->elemento;
}
template <class T>
ListaEnlazada<NodoGrafo<T>*> NodoGrafo<T>::get_listaDeAristas(){
    return this->listaDeAristas;
}
template <class T>
void NodoGrafo<T> ::set_siguiente(NodoGrafo<T>* pointer){
    this->siguiente_elemento = pointer;

}
template <class T>
 NodoGrafo<T>* NodoGrafo<T>::get_siguiente(){
     return this->siguiente_elemento;
 }
 template <class T>
void NodoGrafo<T>:: agregarArista(NodoGrafo<T>*  pointer){
    this->listaDeAristas.agregarAlFinal(pointer);

}
