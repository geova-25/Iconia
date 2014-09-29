#include "genetic.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>
#include <time.h>
#include "opencv2/highgui/highgui.hpp"



using namespace std;


Genetic::Genetic()
{
}

//ver la poblacion existente
void Genetic::verPoblacion(){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++ ){
            cout<<Poblacion[i][j];
            cout<<"    ";
        }
        cout<<"\n";
    }
}

//inicia y crea la poblacion
void Genetic::iniciarPoblacion(string Poblacion[filas][columnas]){
    std::string individuo = "";
    for(int i=0;i<filas;i++){
        genes.str("");
        for(int j=0; j<8;j++){
            int temp = rand()%2;
            genes << temp;
            //if(j!=7){
                genes << ",";
            //}
            individuo =genes.str();
        }
        individuos<<i;
        Poblacion[i][0]=individuos.str();
        individuos.str("");
        Poblacion[i][1]=individuo;
    }
}

//convierte el numero de binario a decimal
void Genetic::convertirIndividuo(string Poblacion[filas][columnas]){

    for(int i=0;i<filas;i++){
            string individuo=Poblacion[i][1];
            int pixel=0;
            int indice=0;
            pix.str("");
            for(int j=individuo.length();j>=0;j--){
                if(individuo[j]=='1'){
                    pixel=pixel+pow(2,indice);
                    indice++;
                }
                else if(individuo[j]=='0'){
                    indice++;
                }

            }
            pix << pixel;
            Poblacion[i][2]=pix.str();

        }
}

//realiza la funcion del pixel lo multiplica por 3
int Genetic::funcion(string Poblacion[filas][columnas]){
    int mayor=0;
    sumatoria=0;
    for(int i=0;i<filas;i++){
        func.str("");
        string pixel=Poblacion[i][2];
        int temp = atoi(pixel.c_str());
        int fun = temp*3;
        func<<fun;
        Poblacion[i][3]=func.str();
        if(fun>mayor){
            mayor=fun;
        }
        sumatoria+=fun;
    }
    return mayor;
}

//funcion de fitnes para saber el mejor individuo
void Genetic::fitness(string Poblacion[filas][columnas]){
    for(int i=0;i<filas;i++){
        fitn.str("");
        string pixel=Poblacion[i][3];
        double temp = atoi(pixel.c_str());
        double fit = temp/sumatoria;
        fitn<<fit;
        Poblacion[i][4]=fitn.str();
    }
}

//saca el individio
/*
void seleccionarIndividuos(string Poblacion[filas][columnas]){
    time_t t;
    srand((unsigned) time(&t));

    for(int w=0;w<filas;w++){
        string padre="";
        string madre="";
        double temp=0.0;
        double numero1=1;
        double numero2=1;
        double resultado=0;

    const long max_rand = 1000000L;

    x = x1 + ( x2 - x1) * (rand() % max_rand) / max_rand;
    a = a1 + ( a2 - a1) * (rand() % max_rand) / max_rand;

    cout<<"el random x es: "<<x<<endl;
    cout<<"el random a es: "<<a<<endl;


    for(int i=0;i<filas;i++){

        string fitnes = Poblacion[i][4];
        string fit="";

        for(int f=0;f<fitnes.length();f++){
            if(fitnes[f]== '.'){
                fit+=",";
            }
            else {
                fit+=fitnes[f];
            }
        }

        temp=atof(fit.c_str());

        //sacar el padre
        resultado=temp-x;
        if (resultado<numero1 && resultado>0){
            cout<<"hola"<<endl;
            numero1=resultado;
            padre = Poblacion[i][1]+" "+Poblacion[i][0];
        }
        else if (resultado<numero2){
            cout<<"buenas"<<endl;
            numero2=resultado;
            padre = Poblacion[i][1]+" "+Poblacion[i][0];
        }

        //sacar el madre

        resultado=temp-a;
        if (resultado<numero1 && resultado>0){
            cout<<"adiosj"<<endl;
            numero1=resultado;
            madre = Poblacion[i][1]+" "+Poblacion[i][0];
        }
        else if (resultado<numero2){
            cout<<"asta lego"<<endl;
            numero2=resultado;
            madre = Poblacion[i][1]+" "+Poblacion[i][0];
        }
    }
     cout<<"este es el padre: "<<padre<<" padre"<<endl;
     cout<<"este es la madre: "<<madre<<" madre"<<endl;
    }
}


*/


//Seleccionar cada individuo
void Genetic::seleccionar(string Poblacion[filas][columnas]){
    if(banderasel==false){
        srand (time(NULL));
        for(int i=0;i<filas;i++){
            ran.str("");
            x=rand()%filas;
            ran<<x;
            Poblacion[i][5]=ran.str();
        }
        banderasel=true;
    }
    else{
        //cout<<"hola"<<endl;
        srand (time(NULL));
        for(int i=0;i<filas;i++){
            ran.str("");
            y=rand()%15;
            ran<<y;
            Poblacion[i][5]=ran.str();
        }
        banderasel=false;
    }

}


void Genetic::cruce(string Poblacion[filas][columnas]){
    time_t g;
    srand((unsigned) time(&g));

    for(int i=0;i<filas;i++){
        string padre = Poblacion[i][1];
        string madre = "";
        string temp="";
        string pareja=Poblacion[i][5];
        punto=1+rand()%14;

        int w=0;
        w=atoi(pareja.c_str());
        for (int l=0;l<filas;l++){
            if(l==w){
                madre=Poblacion[l][1];
            }
        }
        for(int j=0;j<punto;j++){
            temp+=padre[j];
        }
        for(int g=punto;g<madre.length();g++){
            temp+=madre[g];

        }

        Poblacion[i][1]=temp;
    }

}

void Genetic::mutacion(string Poblacion[filas][columnas]){

    string individuo= "";
    string temp="";
    string indtem="";
    if(banderamut==false){
    srand(time(NULL));
    for (int h=0;h<filas;h++){

        individuo=Poblacion[h][1];

        for (int l=0;l<individuo.length();l+=2){
            temp+=individuo[l];
        }

        cambio=rand()%8;

        for(int j=0;j<temp.length();j++){
            if (j==cambio){
                if(temp[j]=='1'){
                    temp[j]='0';
                }
                else{
                    temp[j]='1';
                }
            }
        }
        //cout<<"cambio: "<<cambio<<endl;

        for(int k=0;k<temp.length();k++){
            indtem+=temp[k];
            indtem+=",";
        }

        Poblacion[h][1]=indtem;
        temp="";
        indtem="";
    }
    banderamut=true;
    }
    else{
        srand(time(NULL));
        for (int h=0;h<filas;h++){

            individuo=Poblacion[h][1];

            for (int l=0;l<individuo.length();l+=2){
                temp+=individuo[l];
            }

            a=rand()%8;
            for(int j=0;j<temp.length();j++){
                if (j==cambio){
                    if(temp[j]=='1'){
                        temp[j]='0';
                    }
                    else{
                        temp[j]='1';
                    }
                }
            }
            //cout<<" a: "<<a<<endl;

            for(int k=0;k<temp.length();k++){
                indtem+=temp[k];
                indtem+=",";
            }

            Poblacion[h][1]=indtem;
            temp="";
            indtem="";
        }
        banderamut=false;
    }



}




int Genetic::mejorPixel(int pixel){
    string pixelstr="";
    int indpixel=0;
    int temp=pixel;
    int c=0;
    int resultado=0;
    for(int i=0;i<filas;i++){
        pixelstr=Poblacion[i][2];
        indpixel=atoi(pixelstr.c_str()); // pixel de la matriz (mejor individuo)

        resultado=pixel-indpixel;
        if (resultado<temp && resultado>0){
            c=indpixel;
            temp=resultado;
        }
    }
    cout<<"el mejor pixel es: "<<c<<endl;
    return c;
}
