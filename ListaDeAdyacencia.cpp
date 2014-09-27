#include "ListaDeAdyacencia.h"

template <class T>
 ListaDeAdyacencia<T>:: ListaDeAdyacencia()
{
    this->primerNodo = NULL;
    this->ultimoNodo = NULL;

}
template <class T>
ListaDeAdyacencia<T>::~ListaDeAdyacencia() {
    // TODO Auto-generated destructor stub
}
template <class T>
void ListaDeAdyacencia<T>:: relacionar(T ele1 , T ele2){
    if (estaVacia()){
        cout<<"No hay elementos a imprimir"<<endl;
    }
    else{
        NodoGrafo<T>* temporal = NULL;
        NodoGrafo<T>* temporal2 = NULL;
        NodoGrafo<T>* temporal3 = NULL;

        temporal = this->primerNodo;
        while(temporal != NULL)
        {
            if(temporal->get_elemento() == ele1){ //implenetar mejor
                temporal2 = temporal;
                cout<<"iguales"<<endl;
            }
            if(temporal->get_elemento() == ele2){ //implenetar mejor
                temporal3 = temporal;
                cout<<"iguales2"<<endl;
            }
            temporal = temporal->get_siguiente();
                cout<<"iguales3"<<endl;
        }
        cout<<"iguales4"<<endl;
        if(temporal2 != NULL && temporal3 != NULL){
            temporal2->agregarArista(temporal3);
        }
    }
}

/**
 * @param
 * @return
 */

template <class T>
void ListaDeAdyacencia<T>:: imprimir()
{
    if(estaVacia()){
        cout<<"No hay elementos a imprimir"<<endl;
    }
    else{
        NodoGrafo<T>* temporal = NULL;
        temporal = this->primerNodo;
        while(temporal != NULL)
        {
           cout<< " | "<<temporal->get_elemento()<< " | " ;
           temporal->get_listaDeAristas().imprimir();
            temporal = temporal->get_siguiente();

        }

    }
}
/**
 * @param
 * @return
 */
template <class T>
bool ListaDeAdyacencia<T> :: estaVacia()
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
void  ListaDeAdyacencia<T> :: agregarAlFinal(T num)
{
   NodoGrafo<T>* temp = new NodoGrafo<T>(num);
    if (estaVacia())
    {
        this->primerNodo = this->ultimoNodo = temp;
    }
    else
    {
        this->ultimoNodo->set_siguiente(temp);
        this->ultimoNodo = temp;
        this->ultimoNodo->set_siguiente(NULL);
    }

}

/**
 * @param
 * @return
 */
template <class T>
void  ListaDeAdyacencia<T>:: eliminarDelFinal()
{
    NodoGrafo<T> *tempo = this->primerNodo;
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
void ListaDeAdyacencia<T>:: eliminarDelFrente()
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
void   ListaDeAdyacencia<T>:: vaciar()
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
NodoGrafo<T>*  ListaDeAdyacencia<T>::get_primerNodo(){
    return this->primerNodo;
}
