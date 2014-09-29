#include <iostream>
#include "opencv.h"
#include "opencv2/highgui/highgui.hpp"
#include "genetic.h"
#include "Lista_simple.h"
#include "NodoG.h"


using namespace cv;
using namespace std;

ListaSimple l1x;
ListaSimple l1y;


/**
 * @brief OpenCV::OpenCV Contructor
 * Este carga las imagenes
 */
OpenCV::OpenCV()
{
     img = imread("/home/will/QT Creator C++/Iconia/Imagenes/ejever.jpg", CV_LOAD_IMAGE_UNCHANGED);
     img2 = imread("/home/will/QT Creator C++/Iconia/Imagenes/ejever1.jpg", CV_LOAD_IMAGE_UNCHANGED);
}



/**
 * @brief OpenCV::verificar_igualdad Varifica si son iguales
 * @param i
 * @param j
 * @return bool
 * Este método se encarga de ir comparando pixel con pixel para saber si los colores son iguales, solo que el método
 * tiene un porcentaje de error ya que hay pixel con una diferencia de 5 pixeles pero que no son diferentes solo es
 * un error del editor.
 */
bool OpenCV::verificar_igualdad(int i, int j){
    for(int x = 0; x != 3 ; x++){
        //cout << "x: " << x << endl;
        if (abs((img.at<Vec3b>(j, i)[x] - img2.at<Vec3b>(j, i)[x])) <= 10){
            parecido = true;
        }
        else{
            parecido = false;
            return parecido;
        }
    }
    return parecido;
}


/**
 * @brief OpenCV::verificar_desigualdad verifica si son diferentes
 * @param i
 * @param j
 * @return bool
 * Este método se encarga de ir comparando pixel con pixel para saber si los colores son diferentes, solo que el método
 * tiene un porcentaje de error ya que hay pixel con una diferencia de 5 pixeles pero que no son diferentes solo es
 * un error del editor.
 */
bool OpenCV::verificar_desigualdad(int i, int j){
    for(int x = 0; x != 3 ; x++){
        if (abs((img.at<Vec3b>(j, i)[x] - img2.at<Vec3b>(j, i)[x])) >= 10){
            //cout << "ENTRO OK" << endl;
            return true;
        }
        else{
            return false;
        }

    }
}


/**
 * @brief OpenCV::cargarImagen Carga las Imagenes
 * Carga las dos imagenes y empieza a comparar  si son diferentes en caso que sean diferentes
 * hace una lista de nodos con las posiciones de los pixeles que sean diferentes y con el algoritmo genetico
 * empiza a reconstruir la imagen poco a poco
 */
void OpenCV::cargarImagen(){

    if (img.empty())
    {
         cout << "ERROR : LA IMAGEN NO FUE CARGADA" << endl;
    }


    encuentre_vacio();


    Vec3b pix1;
    Vec3b pix2;
    Genetic g;
    int numero = l1x.counterNodos();
    int x;
    int y;



    for (int i=0;i<5;i++){

        Nodos* Nodox=l1x.get_primerNodo();
        Nodos* Nodoy=l1y.get_primerNodo();

        for(int j=0;j<numero;j++){
            x = Nodox->get_numero();
            y = Nodoy->get_numero();

            pix1 = img.at<Vec3b> (y,x);
            pix2 = img2.at<Vec3b> (y,x);

            int blue1 = pix2.val[0];
            int green1= pix2.val[1];
            int red1  = pix2.val[2];

            int blue = pix1.val[0];
            int green= pix1.val[1];
            int red  = pix1.val[2];


            int pro=promedio1(red,green, blue);
            int pro2=promedio2(red1,green1, blue1);
            int fun = red1+green1+blue1;

            int generaciones=0;

            g.iniciarPoblacion(g.Poblacion);
            int adaptado=0;

            while(adaptado<fun){
               g.convertirIndividuo(g.Poblacion);
               adaptado=g.funcion(g.Poblacion);
               g.fitness(g.Poblacion);
               g.seleccionar(g.Poblacion);
               g.cruce(g.Poblacion);
               g.mutacion(g.Poblacion);
               //g.verPoblacion();
               generaciones++;
            }


            if (img.at<Vec3b>(y, x)[0]>img.at<Vec3b>(y, x)[1] && img.at<Vec3b>(y, x)[0]>img.at<Vec3b>(y, x)[2]){
                mayor=0;
                img2.at<Vec3b>(y, x)[mayor]= g.mejorPixel(pro);
                img2.at<Vec3b>(y, x)[1]= 0;
                img2.at<Vec3b>(y, x)[2]= 0;
                banderaColor=true;
            }
            else if (img.at<Vec3b>(y, x)[1]>img.at<Vec3b>(y, x)[0] && img.at<Vec3b>(y, x)[1]>img.at<Vec3b>(y, x)[2]){
                mayor=1;
                img2.at<Vec3b>(y, x)[mayor]= g.mejorPixel(pro);
                img2.at<Vec3b>(y, x)[0]= 0;
                img2.at<Vec3b>(y, x)[2]= 0;
                banderaColor=true;
            }
            else if (img.at<Vec3b>(y, x)[2]>img.at<Vec3b>(y, x)[0] && img.at<Vec3b>(y, x)[2]>img.at<Vec3b>(y, x)[1]){
                mayor=2;
                img2.at<Vec3b>(y, x)[mayor]= g.mejorPixel(pro);
                img2.at<Vec3b>(y, x)[0]= 0;
                img2.at<Vec3b>(y, x)[1]= 0;
                banderaColor=true;
            }
            else if (img.at<Vec3b>(y, x)[0]==img.at<Vec3b>(y, x)[1]==img.at<Vec3b>(y, x)[2]==0){
                img2.at<Vec3b>(y, x)= g.mejorPixel(pro2);
                banderaColor=false;
            }

            Nodox = Nodox->get_siguiente();
            Nodoy = Nodoy->get_siguiente();
            if(verificar_igualdad(x,y) && banderaColor==true){
                bandera=true;
                break;
            }
        }

        if(bandera==true){
            break;
        }

    }


    namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);
    imshow("MyWindow", img);


    namedWindow("MyWindow2", CV_WINDOW_AUTOSIZE);
    imshow("MyWindow2", img2);



    waitKey(0);

    destroyWindow("MyWindow");
}


/**
 * @brief OpenCV::encuentre_vacio Encuentra si hay pixeles diferente con un vscio blanco
 * @return lista 1
 * Recorre la imagen veindo a ver si son iguales o diferentes los pixeles
 */
int* OpenCV::encuentre_vacio(){
    int i = 0;
    int j = 0;
    while(i != img.rows)
    {
        if(j == img.cols){
            j = 0;
            i += 1;
        }
        else if(verificar_desigualdad(i,j))
        {
            encuentre_cuadrado(i,j);
            return l1;
        }
        else{
            j += 1;
        }
    }
    cout << "¡No encontro nada!" << endl;
}


/**
 * @brief OpenCV::promedio1 Promedio para imagen de color
 * @param red
 * @param green
 * @param blue
 * @return resultadoPro
 * Saca un promedio del RGB la imagen
 */
int OpenCV::promedio1(int red, int green, int blue){

    resultadoPro=(red+green+blue)/3;

    return resultadoPro;
}


/**
 * @brief OpenCV::promedio2 Promedio para la imagen en negro
 * @param red
 * @param green
 * @param blue
 * @return resultadoPro
 * Saca un promedio del RGB la imagen
 */
int OpenCV::promedio2(int red, int green, int blue){

    resultadoPro=(red+green+blue)/3;

    return resultadoPro;
}


/**
 * @brief OpenCV::encuentre_cuadrado Agrega a lista
 * @param x
 * @param y
 * Si los pixeles son diferentes forma dos listas una de las posiciones en x y otra lista con las posiciones en y
 */
void OpenCV::encuentre_cuadrado(int x, int y){
    int tempx = x;
    int tempy = y;
    while(verificar_desigualdad(x,y))
    {
        if(!verificar_desigualdad(x + 1,y))
        {
            l1x.agregarAlFinal(x);
            l1y.agregarAlFinal(y);
            tempy ++;
            y = tempy;
            x = tempx;
        }
        else
        {
            l1x.agregarAlFinal(x);
            l1y.agregarAlFinal(y);
            x += 1;
        }
    }
}


