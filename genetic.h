#ifndef GENETIC_H
#define GENETIC_H
#include <string>
#include <sstream>
#include "opencv2/highgui/highgui.hpp"

#define filas   20
#define columnas 6

//using namespace cv;
using namespace std;

class Genetic
{
public:
    Genetic();
    void verPoblacion();
    void iniciarPoblacion(string Poblacion[filas][columnas]);
    void convertirIndividuo(string Poblacion[filas][columnas]);
    int funcion(string Poblacion[filas][columnas]);
    void fitness(string Poblacion[filas][columnas]);
    void seleccionar(string Poblacion[filas][columnas]);
    void cruce(string Poblacion[filas][columnas]);
    void mutacion(string Poblacion[filas][columnas]);
    string Poblacion[filas][columnas];
    int mejorPixel(int pixel);


private:

    stringstream individuos;
    stringstream genes;
    stringstream pix;
    stringstream func;
    stringstream fitn;
    stringstream ran;
    double sumatoria=0;
    int x=0;
    int punto=0;
    int cambio=0;
    int y=0;
    bool banderasel=true;
    bool banderamut=true;
    int a=0;
};

#endif // GENETIC_H
