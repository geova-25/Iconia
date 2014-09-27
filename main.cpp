
#include <iostream>
using std::cout;
using std::endl;
#include <stdio.h>
#include <stdlib.h>
#include <string>
using std::string;
#include "ListaEnlazada.h"
#include "ListaEnlazada.cpp"
#include "ListaDeAdyacencia.h"
#include "ListaDeAdyacencia.cpp"

#include "Grafo.h"
#include "Grafo.cpp"

using namespace std;


int main(){
   /* int numero_de_lados;
    cout<<"ingrese numero de lados"<<endl;
    cin>> numero_de_lados;
    string nombre_de_figura;
    cout<<" que figura es?"<<endl;
    cin>> nombre_de_figura;
    cout<<"es un"<<nombre_de_figura<<endl;*/


    ListaDeAdyacencia<int> h ;
    h.agregarAlFinal(4);
    h.agregarAlFinal(5);
    h.agregarAlFinal(7);
    h.relacionar(4,5);
    h.imprimir();










    return 0;
}
