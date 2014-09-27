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

#include "FigureDetector.h"

#include "Grafo.h"
#include "Grafo.cpp"

#include <pthread.h>

using namespace std;

bool captured=false;
 char key;
ListaDeAdyacencia<string> h ;
FigureDetector fg;
pthread_t hilo1;
/*void *runDetector(void* unused){
    fg.DrawFigures();
}*/

int main(){

   // pthread_create(&hilo1,NULL,runDetector,NULL);




     while(captured == false){



        fg.DrawFigures();




        key = cvWaitKey(10); //Capture Keyboard stroke
        if (char(key) == 27){
            break; //If you hit ESC key loop will break.
        }
        if (char(key)==102){
            int numero_de_lados;
            cout<<"ingrese numero de lados"<<endl;
            cin>> numero_de_lados;
            string nombre_de_figura;
            cout<<" que figura es?"<<endl;
            cin>> nombre_de_figura;
            h.agregarAlFinal(nombre_de_figura);
            cout<<"es un"<<nombre_de_figura<<endl;
            h.imprimir();


        }
         //waitKey(30);
}

     fg.releaseObjects();











    return 0;
}
